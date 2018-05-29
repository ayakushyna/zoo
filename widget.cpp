#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),ui(new Ui::Widget){

    ui->setupUi(this);
    zoo = new Zoo;

    createButtonsGroupBox();
    createTabsOfAnimals();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(tabsOfAnimals);
    mainLayout->addWidget(buttonsGroupBox);

    setLayout(mainLayout);

    setWindowTitle(zoo->getZooName());
    setWindowIcon(QIcon(":/images/zoo_icon.png"));
}

Widget::~Widget(){
    delete ui;
}

void Widget::createButtonsGroupBox(){
    buttonsGroupBox = new QGroupBox("Zoo Actions");
    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton* changeZooNameButton = new QPushButton("Change Zoo Name");
    QPushButton* feedingButton = new QPushButton("Feeding");
    QPushButton* addAnimalButton = new QPushButton("Add Animal");

    connect(changeZooNameButton, SIGNAL(clicked()),SLOT(changeZooNameSlot()));
    connect(feedingButton, SIGNAL(clicked()),SLOT(feedingSlot()));
    connect(addAnimalButton, SIGNAL(clicked()),SLOT(addAnimalSlot()));

    layout->addWidget(changeZooNameButton);
    layout->addWidget(feedingButton);
    layout->addWidget(addAnimalButton);

    buttonsGroupBox->setLayout(layout);
}

void Widget::createTabsOfAnimals(){
    tabsOfAnimals = new QTabWidget;

    createAnimalGroupBox(BIRD);
    createAnimalGroupBox(MAMMAL);
    createAnimalGroupBox(SNAKE);

    tabsOfAnimals->addTab(birdsGroupBox,"Birds");
    tabsOfAnimals->addTab(mammalsGroupBox,"Mammals");
    tabsOfAnimals->addTab(snakesGroupBox,"Snakes");

}

void Widget::createAnimalGroupBox(Animaltype type){

    QTimer* timer = new QTimer;
    switch (type)
    {
    case BIRD:
    {
        birdsGroupBox = new QGroupBox;
        QVBoxLayout *layout = new QVBoxLayout;
        listOfBirds = new QComboBox;
        birdInfo = new AnimalInfo(BIRD);

        connect(listOfBirds, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                [=](const QString &text){birdInfo->setAnimalInfo(BIRD, zoo->getAnimal(text));});

        connect(timer,&QTimer::timeout,
                [=]() {
                    if(listOfBirds->count())
                        birdInfo->setAnimalInfo(BIRD, zoo->getAnimal(listOfBirds->currentText()));
        });
        timer->start(1000);

        layout->addWidget(listOfBirds);
        layout->addWidget(birdInfo->getBirdInfo());


        birdsGroupBox->setLayout(layout);
        break;
    }

    case MAMMAL:
    {
        mammalsGroupBox = new QGroupBox;
        QVBoxLayout *layout = new QVBoxLayout;
        listOfMammals = new QComboBox;
        mammalInfo = new AnimalInfo(MAMMAL);

        connect(listOfMammals, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                [=](const QString &text){mammalInfo->setAnimalInfo(MAMMAL, zoo->getAnimal(text));});

        connect(timer,&QTimer::timeout,
                [=]() {
                    if(listOfMammals->count())
                        mammalInfo->setAnimalInfo(MAMMAL, zoo->getAnimal(listOfMammals->currentText()));
        });
        timer->start(1000);

        layout->addWidget(listOfMammals);
        layout->addWidget(mammalInfo->getMammalInfo());

        mammalsGroupBox->setLayout(layout);
        break;
    }

    case SNAKE:
    {

        snakesGroupBox = new QGroupBox;
        QVBoxLayout *layout = new QVBoxLayout;
        listOfSnakes = new QComboBox;
        snakeInfo = new AnimalInfo(SNAKE);

        connect(listOfSnakes, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                [=](const QString &text){snakeInfo->setAnimalInfo(SNAKE, zoo->getAnimal(text));});

        connect(timer,&QTimer::timeout,
                [=]() {
                    if(listOfSnakes->count())
                        snakeInfo->setAnimalInfo(SNAKE, zoo->getAnimal(listOfSnakes->currentText()));
                });
        timer->start(1000);

        layout->addWidget(listOfSnakes);
        layout->addWidget(snakeInfo->getSnakeInfo());

        snakesGroupBox->setLayout(layout);
        break;
    }

    }
}

void Widget::changeZooNameSlot(){
    bool bOk, bInvalid = false;
    QString zooName;

    do {
    zooName = QInputDialog::getText( this, "Input Name", "Name:",
                                     QLineEdit::Normal,  (bInvalid? "Invalid Name":""), &bOk );
    bInvalid= true;
    }
    while(!zoo->checkZooName(zooName) && bOk);

    if(bOk)
    {
        zoo->setZooName(zooName);
        setWindowTitle(zoo->getZooName());
    }
}

void Widget::feedingSlot(){
    feedDialog = new FeedDialog;
    feedDialog->resize(400,200);
    feedDialog->show();

    if (feedDialog->exec()){
        int message = zoo->feeding(feedDialog->getAnimalType(),feedDialog->getFoodType(),feedDialog->getPercentIncrease());

        switch(message)
        {
        case FED:
        {
            QMessageBox::information(this, "Feeding info", "Successful feeding.");
            break;
        }
        case UNFED:
        {
            QMessageBox::critical(this, "Feeding info", "Failed feeding.");
            break;
        }
        case NOANIMAL:
        {
            QMessageBox::critical(this, "Feeding info", "There are no animals of this type.");
            break;
        }
        }
    }
}


void Widget::addAnimalSlot(){

    wizard = new AnimalWizard(zoo->getAnimalsNames());
    wizard->resize(700,400);
    wizard->show();

    if (wizard->exec())
    {
        Animal* animal;

        switch(wizard->getPath())
        {
        case BIRD:
        {
        animal = new Bird(wizard->getAnimalName(), BIRD, wizard->getAnimalYears(), wizard->getAnimalMonths(),
                          wizard->getAnimalWeight(), wizard->getAnimalPercent(), wizard->getAnimalSpecies(),
                          wizard->getAnimalLengthOfWings(), wizard->getAnimalPredator());

        zoo->addAnimal(animal);
        listOfBirds->addItem(QIcon(":/images/" + animal->getSpecies() + ".png"),animal->getName());
        break;
        }

        case MAMMAL:
        {
        animal = new Mammal(wizard->getAnimalName(), MAMMAL, wizard->getAnimalYears(), wizard->getAnimalMonths(),
                            wizard->getAnimalWeight(), wizard->getAnimalPercent(), wizard->getAnimalSpecies(),
                            wizard->getAnimalMilkPeriod(), wizard->getAnimalPredator());


        zoo->addAnimal(animal);
        listOfMammals->addItem(QIcon(":/images/" + animal->getSpecies() + ".png"),animal->getName());

        break;
        }

        case SNAKE:
        {

        animal = new Snake(wizard->getAnimalName(), SNAKE, wizard->getAnimalYears(), wizard->getAnimalMonths(),
                           wizard->getAnimalWeight(), wizard->getAnimalPercent(), wizard->getAnimalSpecies(),
                           wizard->getAnimalLength(), wizard->getAnimalPoisonous());



        zoo->addAnimal(animal);
        listOfSnakes->addItem(QIcon(":/images/" + animal->getSpecies() + ".png"),animal->getName());
        break;
        }
        }

        QTimer* feedingTimer = new QTimer;
        connect(feedingTimer,&QTimer::timeout,
                [animal](){
                    if(animal->getPercentOfFeeding() > 0)
                        animal->declinePercentOfFeeding();

                });
        feedingTimer->start(1000);

        QTimer* ageTimer = new QTimer;
        connect(ageTimer,&QTimer::timeout,
                [animal](){
                    if(animal->getYears() < 100)
                        animal->riseAge();

                });
        ageTimer->start(10000);

    }
    }


