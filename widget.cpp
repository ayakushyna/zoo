#include "widget.h"
#include "ui_widget.h"

QVector <Zoo*> Widget::mZoos = { new Zoo("Zoo1"),new Zoo("Zoo2"),new Zoo("Zoo3") };

Widget::Widget(QWidget *parent) :
    QWidget(parent),ui(new Ui::Widget){

    ui->setupUi(this);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(createZooGroupBox(),0,0);
    mainLayout->addWidget(createTabsOfAnimals(),1,0);
    mainLayout->addWidget(createButtonsGroupBox(),0,1,2,1);

    mZoo = mZoos[0];

    setLayout(mainLayout);

    setWindowTitle(mZoo->getZooName());
    setWindowIcon(QIcon(":/images/zoo_icon.png"));
}


QGroupBox* Widget::createZooGroupBox(){
    zooGroupBox = new QGroupBox("Select zoo:");
    QVBoxLayout *layout = new QVBoxLayout;

    listOfZoo = new QComboBox;
    foreach (Zoo* zoo0, mZoos) {
        listOfZoo->addItem(zoo0->getZooName());
    }

    connect(listOfZoo,SIGNAL(currentIndexChanged(int)),this, SLOT(changeZoo(int)));

    layout->addWidget(listOfZoo);
    zooGroupBox->setLayout(layout);

    return zooGroupBox;
}

QGroupBox* Widget::createButtonsGroupBox(){
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

    return buttonsGroupBox;
}

QTabWidget* Widget::createTabsOfAnimals(){
    tabsOfAnimals = new QTabWidget;

    createAnimalGroupBox(BIRD);
    createAnimalGroupBox(MAMMAL);
    createAnimalGroupBox(SNAKE);

    tabsOfAnimals->addTab(birdsGroupBox,"Birds");
    tabsOfAnimals->addTab(mammalsGroupBox,"Mammals");
    tabsOfAnimals->addTab(snakesGroupBox,"Snakes");

    return tabsOfAnimals;

}

void Widget::createAnimalGroupBox(Animaltype type){
    QTimer* updateTimer = new QTimer;

    switch (type)
    {
    case BIRD:
    {
        birdsGroupBox = new QGroupBox;
        QVBoxLayout *layout = new QVBoxLayout;
        listOfBirds = new QComboBox;
        birdInfo = new AnimalInfo(BIRD);

        QPushButton* moveAnimalButton = new QPushButton("Move to another zoo");
        moveAnimalButton->setDisabled(true);
        connect(moveAnimalButton, SIGNAL(clicked()), SLOT(moveAnimalSlot()));

        connect(listOfBirds, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                [=](const QString &text){
                    if(listOfBirds->count()){
                        birdInfo->setAnimalInfo(BIRD, mZoo->getAnimal(text));
                        moveAnimalButton->setDisabled(false);
                    } else{
                        birdInfo->clearAnimalInfo(BIRD);
                        moveAnimalButton->setDisabled(true);
                }
        });
        connect(updateTimer,&QTimer::timeout,
                [=]() {
                    if(listOfBirds->count())
                        birdInfo->setAnimalInfo(BIRD, mZoo->getAnimal(listOfBirds->currentText()));
                    else
                        birdInfo->clearAnimalInfo(BIRD);
        });
        updateTimer->start(1000);

        layout->addWidget(listOfBirds);
        layout->addWidget(birdInfo->getBirdInfo());
        layout->addWidget(moveAnimalButton);

        birdsGroupBox->setLayout(layout);
        break;
    }

    case MAMMAL:
    {
        mammalsGroupBox = new QGroupBox;
        QVBoxLayout *layout = new QVBoxLayout;
        listOfMammals = new QComboBox;
        mammalInfo = new AnimalInfo(MAMMAL);

        QPushButton* moveAnimalButton = new QPushButton("Move to another zoo");
        moveAnimalButton->setDisabled(true);
        connect(moveAnimalButton, SIGNAL(clicked()), SLOT(moveAnimalSlot()));

        connect(listOfMammals, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                [=](const QString &text){
                    if(listOfMammals->count()){
                        mammalInfo->setAnimalInfo(MAMMAL, mZoo->getAnimal(text));
                        moveAnimalButton->setDisabled(false);
                    } else{
                        mammalInfo->clearAnimalInfo(MAMMAL);
                        moveAnimalButton->setDisabled(true);
                }
        });
        connect(updateTimer,&QTimer::timeout,
                [=]() {
                    if(listOfMammals->count())
                        mammalInfo->setAnimalInfo(MAMMAL, mZoo->getAnimal(listOfMammals->currentText()));
                    else
                        mammalInfo->clearAnimalInfo(MAMMAL);
        });
        updateTimer->start(1000);

        layout->addWidget(listOfMammals);
        layout->addWidget(mammalInfo->getMammalInfo());
        layout->addWidget(moveAnimalButton);

        mammalsGroupBox->setLayout(layout);
        break;
    }

    case SNAKE:
    {

        snakesGroupBox = new QGroupBox;
        QVBoxLayout *layout = new QVBoxLayout;
        listOfSnakes = new QComboBox;
        snakeInfo = new AnimalInfo(SNAKE);

        QPushButton* moveAnimalButton = new QPushButton("Move to another zoo");
        moveAnimalButton->setDisabled(true);
        connect(moveAnimalButton, SIGNAL(clicked()), SLOT(moveAnimalSlot()));

        connect(listOfSnakes, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                [=](const QString &text){
                    if(listOfSnakes->count()){
                        snakeInfo->setAnimalInfo(SNAKE, mZoo->getAnimal(text));
                        moveAnimalButton->setDisabled(false);
                    } else{
                        snakeInfo->clearAnimalInfo(SNAKE);
                        moveAnimalButton->setDisabled(true);
                }
        });

        connect(updateTimer,&QTimer::timeout,
                [=]() {
                    if(listOfSnakes->count())
                        snakeInfo->setAnimalInfo(SNAKE, mZoo->getAnimal(listOfSnakes->currentText()));
                    else
                        snakeInfo->clearAnimalInfo(SNAKE);
                });
        updateTimer->start(1000);

        layout->addWidget(listOfSnakes);
        layout->addWidget(snakeInfo->getSnakeInfo());
        layout->addWidget(moveAnimalButton);

        snakesGroupBox->setLayout(layout);
        break;
    }
    }

}

QStringList Widget::getZooNames() const{
    QStringList list;

    foreach(Zoo* zoo0, mZoos){
        if(mZoo->getZooName() != zoo0->getZooName())
            list << zoo0->getZooName();
    }

    return list;
}

void Widget::changeZoo(int index){

    listOfBirds->clear();
    listOfMammals->clear();
    listOfSnakes->clear();

    mZoo = mZoos[index];

    listOfBirds->addItems(mZoo->getSpecificNames(BIRD));
    listOfMammals->addItems(mZoo->getSpecificNames(MAMMAL));
    listOfSnakes->addItems(mZoo->getSpecificNames(SNAKE));

    setWindowTitle(mZoo->getZooName());
}

void Widget::changeZooNameSlot(){
    bool bOk, bInvalid = false;
    QString zooName;

    do {
    zooName = QInputDialog::getText( this, "Input Name", "Name:",
                                     QLineEdit::Normal,  (bInvalid? "Invalid Name":""), &bOk );
    bInvalid= true;
    }
    while(!mZoo->checkZooName(zooName) && bOk);

    if(bOk)
    {
        mZoo->setZooName(zooName);
        setWindowTitle(mZoo->getZooName());

        listOfZoo->setItemText(mZoos.indexOf(mZoo),mZoo->getZooName());
    }

}

void Widget::feedingSlot(){
    feedDialog = new FeedDialog;
    feedDialog->resize(400,200);
    feedDialog->show();

    if (feedDialog->exec()){
        int message = mZoo->feeding(feedDialog->getAnimalType(),feedDialog->getFoodType(),feedDialog->getPercentIncrease());

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

    wizard = new AnimalWizard(mZoo->getAnimalsNames());
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

        mZoo->addAnimal(animal);
        listOfBirds->addItem(animal->getName());
        break;
        }

        case MAMMAL:
        {
        animal = new Mammal(wizard->getAnimalName(), MAMMAL, wizard->getAnimalYears(), wizard->getAnimalMonths(),
                            wizard->getAnimalWeight(), wizard->getAnimalPercent(), wizard->getAnimalSpecies(),
                            wizard->getAnimalMilkPeriod(), wizard->getAnimalPredator());


        mZoo->addAnimal(animal);
        listOfMammals->addItem(animal->getName());

        break;
        }

        case SNAKE:
        {

        animal = new Snake(wizard->getAnimalName(), SNAKE, wizard->getAnimalYears(), wizard->getAnimalMonths(),
                           wizard->getAnimalWeight(), wizard->getAnimalPercent(), wizard->getAnimalSpecies(),
                           wizard->getAnimalLength(), wizard->getAnimalPoisonous());



        mZoo->addAnimal(animal);
        listOfSnakes->addItem(animal->getName());
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

void Widget::moveAnimalSlot(){
    moveDialog = new MoveDialog(getZooNames());
    moveDialog->show();

    if(moveDialog->exec())
    {
        QString selectedZooName = moveDialog->getSelectedZooName();
        QString currAnimalName;

        switch(tabsOfAnimals->currentIndex()+1)
        {
        case BIRD:
        {
            currAnimalName = listOfBirds->currentText();
            listOfBirds->removeItem(listOfBirds->currentIndex());
            break;
        }
        case MAMMAL:
        {
            currAnimalName = listOfMammals->currentText();
            listOfMammals->removeItem(listOfMammals->currentIndex());
            break;
        }
        case SNAKE:
        {
            currAnimalName = listOfSnakes->currentText();
            listOfSnakes->removeItem(listOfSnakes->currentIndex());
            break;
        }
        }

        Animal* currAnimal = mZoo->getAnimal(currAnimalName);
        mZoo->removeAnimal(currAnimalName);

        foreach (auto zoo, mZoos) {
            if(zoo->getZooName() == selectedZooName){
                if(zoo->getAnimalsNames().contains(currAnimalName)){

                    QMessageBox* msgBox = new QMessageBox;
                    msgBox->setText("Animal with this name has already existed in that zoo.");
                    msgBox->setIcon(QMessageBox::Warning);
                    msgBox->setInformativeText("Do you want to rename the animal or remove it?");
                    msgBox->addButton("Rename", QMessageBox::AcceptRole);
                    msgBox->addButton("Remove", QMessageBox::RejectRole);
                    msgBox->setWindowIcon(QIcon(":/images/zoo_icon.png"));
                    msgBox->setWindowTitle("Warning");

                    int res = msgBox->exec();
                    if(res == QMessageBox::RejectRole)
                        break;

                    renameDialog = new RenameDialog(currAnimal,zoo);
                    renameDialog->show();
                    if(renameDialog->exec())
                        zoo->addAnimal(currAnimal);
                    break;
                }
                zoo->addAnimal(currAnimal);
                break;
            }
        }
    }
}

Widget::~Widget(){
    delete ui;
}
