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
    foreach (Zoo* zoo, mZoos) {
        listOfZoo->addItem(zoo->getZooName());
    }

    connect(listOfZoo,SIGNAL(currentIndexChanged(int)),this, SLOT(changeZooSlot(int)));

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

    listOfBirds = new QComboBox;
    birdInfo = new BirdInfo;
    birdsGroupBox = createAnimalGroupBox(listOfBirds,birdInfo);

    listOfMammals = new QComboBox;
    mammalInfo = new MammalInfo;
    mammalsGroupBox = createAnimalGroupBox(listOfMammals,mammalInfo);

    listOfSnakes = new QComboBox;
    snakeInfo = new SnakeInfo;
    snakesGroupBox = createAnimalGroupBox(listOfSnakes,snakeInfo);


    tabsOfAnimals->addTab(birdsGroupBox,"Birds");
    tabsOfAnimals->addTab(mammalsGroupBox,"Mammals");
    tabsOfAnimals->addTab(snakesGroupBox,"Snakes");

    return tabsOfAnimals;

}

template<class T>
QGroupBox* Widget::createAnimalGroupBox( QComboBox* listOfAnimals,T* animalInfo){

    QGroupBox* animalGroupBox = new QGroupBox;
    QGridLayout *layout = new QGridLayout;
    QTimer* updateTimer = new QTimer;

    QPushButton* moveAnimalButton = new QPushButton("Move to another zoo");
    QPushButton* removeAnimalButton = new QPushButton("Remove Animal");
    moveAnimalButton->setDisabled(true);
    removeAnimalButton->setDisabled(true);
    connect(moveAnimalButton, SIGNAL(clicked()), SLOT(moveAnimalSlot()));
    connect(removeAnimalButton, SIGNAL(clicked()),SLOT(removeAnimalSlot()));

    connect(listOfAnimals, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            [=](const QString &text){
                if(listOfAnimals->count()){
                    animalInfo->setAnimalInfo(mZoo->getAnimal(text));
                    setCurrentAnimalName(listOfAnimals);
                    moveAnimalButton->setDisabled(false);
                    removeAnimalButton->setDisabled(false);
                } else {
                    animalInfo->clearAnimalInfo();
                    moveAnimalButton->setDisabled(true);
                    removeAnimalButton->setDisabled(true);
            }
    });

    connect(updateTimer,&QTimer::timeout,
            [=]() {
                if(listOfAnimals->count())
                    animalInfo->setAnimalInfo(mZoo->getAnimal(listOfAnimals->currentText()));
                else
                    animalInfo->clearAnimalInfo();
    });
    updateTimer->start(1000);

    layout->addWidget(listOfAnimals,0,0,1,2);
    layout->addWidget(animalInfo->getAnimalInfo(),1,0,1,2);
    layout->addWidget(moveAnimalButton,2,0,1,1);
    layout->addWidget(removeAnimalButton,2,1,1,1);

    animalGroupBox->setLayout(layout);
    return animalGroupBox;

}

QStringList Widget::getZooNames() const{
    QStringList list;

    foreach(Zoo* zoo, mZoos){
        if(mZoo->getZooName() != zoo->getZooName())
            list << zoo->getZooName();
    }

    return list;
}

void Widget::changeZooSlot(int index){

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

        switch(mZoo->feeding(feedDialog->getSelectedFood()))
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
        Animal* animal = nullptr;

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
                        animal->decreasePercentOfFeeding();

                });
        feedingTimer->start(1000);

        QTimer* ageTimer = new QTimer;
        connect(ageTimer,&QTimer::timeout,
                [animal](){
                    if(animal->getYears() < 100)
                        animal->increaseAge();

                });
        ageTimer->start(10000);

    }
}

void Widget::removeAnimalSlot(){
    mZoo->removeAnimal(currAnimalName);
    removeCurrentAnimalName(getCurrentListOfAnimals());
}

QComboBox* Widget::getCurrentListOfAnimals()const {
    QComboBox* listOfAnimals = nullptr;
    switch(tabsOfAnimals->currentIndex()+1)
    {
    case BIRD:
    {
        listOfAnimals = listOfBirds;
        break;
    }
    case MAMMAL:
    {
        listOfAnimals = listOfMammals;
        break;
    }
    case SNAKE:
    {
         listOfAnimals = listOfSnakes;
         break;
    }
    }
    return listOfAnimals;
}

QMessageBox* Widget::createNameWarningBox(){
    QMessageBox* msgBox = new QMessageBox;

    msgBox->setText("Animal with this name has already existed in that zoo.");
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setInformativeText("Do you want to rename the animal?");
    msgBox->addButton("Rename", QMessageBox::AcceptRole);
    msgBox->addButton("Cancel", QMessageBox::RejectRole);
    msgBox->setWindowIcon(QIcon(":/images/zoo_icon.png"));
    msgBox->setWindowTitle("Warning");

    return msgBox;
}

void Widget::setCurrentAnimalName(QComboBox* listOfAnimals){
    currAnimalName = listOfAnimals->currentText();
}

void Widget::removeCurrentAnimalName(QComboBox* listOfAnimals){
    listOfAnimals->removeItem(listOfAnimals->currentIndex());
    currAnimalName = "";
}

void Widget::moveAnimalSlot(){
    moveDialog = new MoveDialog(getZooNames());
    moveDialog->show();

    QComboBox* listOfAnimals = getCurrentListOfAnimals();

    if(moveDialog->exec())
    {
        QString selectedZooName = moveDialog->getSelectedZooName();
        Animal* currAnimal = mZoo->getAnimal(currAnimalName);

        foreach (auto zoo, mZoos) {
            if(zoo->getZooName() == selectedZooName){
                if(zoo->getAnimalsNames().contains(currAnimalName)){

                    QMessageBox* msgBox = createNameWarningBox();
                    if(msgBox->exec() == QMessageBox::AcceptRole){

                        renameDialog = new RenameDialog(currAnimal,zoo);
                        renameDialog->show();

                        if(renameDialog->exec()){
                            mZoo->removeAnimal(currAnimalName);
                            removeCurrentAnimalName(listOfAnimals);
                            zoo->addAnimal(currAnimal);
                        }
                    }
                    break;
                }
                mZoo->removeAnimal(currAnimalName);
                removeCurrentAnimalName(listOfAnimals);
                zoo->addAnimal(currAnimal);
                break;
            }
        }
    }
}

Widget::~Widget(){
    delete ui;
}
