#include "widget.h"
#include "ui_widget.h"

QVector <std::shared_ptr<Zoo>> Widget::mZoos = { std::shared_ptr<Zoo>(new Zoo("Zooone")),
                                                 std::shared_ptr<Zoo>(new Zoo("Zootwo")),
                                                 std::shared_ptr<Zoo>(new Zoo("Zoothree")) };

Widget::Widget(QWidget *parent) :
    QWidget(parent),ui(new Ui::Widget){

    ui->setupUi(this);

    QMenuBar* menuBar = new QMenuBar(this);
    createActions();
    createMenus();
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);

    updateTimer = new QTimer(this);
    updateTimer->start(3000);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(menuBar,0,0);
    mainLayout->addWidget(createZooGroupBox(),1,0);
    mainLayout->addWidget(createTabsOfAnimals(),2,0);
    mainLayout->addWidget(createButtonsGroupBox(),1,1,2,1);

    mZoo = mZoos[0];

    setLayout(mainLayout);

    setWindowTitle(mZoo->getZooName());
    setWindowIcon(QIcon(":/images/zoo_icon.png"));
}

void Widget::createActions(){
    openAct = new QAction("Open",this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct,SIGNAL(triggered()),this, SLOT(loadApp()));

    saveAct = new QAction("Save",this);
    saveAct->setShortcuts(QKeySequence::Save);
    connect(saveAct,SIGNAL(triggered()),this, SLOT(saveApp()));

    aboutAct = new QAction("About",this);
}

void Widget::createMenus(){
    fileMenu = new QMenu("File",this);
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAct);

    helpMenu = new QMenu("Help",this);
    helpMenu->addAction(aboutAct);
}

QGroupBox* Widget::createZooGroupBox(){
    zooGroupBox = new QGroupBox("Select zoo:",this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    listOfZoo = new QComboBox(this);
    foreach (auto zoo, mZoos) {
        listOfZoo->addItem(zoo->getZooName());
    }

    connect(listOfZoo,SIGNAL(currentIndexChanged(int)),this, SLOT(changeZooSlot(int)));

    layout->addWidget(listOfZoo);
    zooGroupBox->setLayout(layout);

    return zooGroupBox;
}

QGroupBox* Widget::createButtonsGroupBox(){
    buttonsGroupBox = new QGroupBox("Zoo Actions");
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton* changeZooNameButton = new QPushButton("Change Zoo Name",this);
    QPushButton* feedingButton = new QPushButton("Feeding",this);
    QPushButton* addAnimalButton = new QPushButton("Add Animal",this);

    connect(changeZooNameButton, SIGNAL(clicked()),this,SLOT(changeZooNameSlot()));
    connect(feedingButton, SIGNAL(clicked()),this,SLOT(feedingSlot()));
    connect(addAnimalButton, SIGNAL(clicked()),this,SLOT(addAnimalSlot()));

    layout->addWidget(changeZooNameButton);
    layout->addWidget(feedingButton);
    layout->addWidget(addAnimalButton);

    buttonsGroupBox->setLayout(layout);

    return buttonsGroupBox;
}

QTabWidget* Widget::createTabsOfAnimals(){
    tabsOfAnimals = new QTabWidget(this);

    listOfBirds = new QComboBox(this);
    birdInfo = new BirdInfo;
    birdsGroupBox = createAnimalGroupBox(listOfBirds,birdInfo);

    listOfMammals = new QComboBox(this);
    mammalInfo = new MammalInfo;
    mammalsGroupBox = createAnimalGroupBox(listOfMammals,mammalInfo);

    listOfSnakes = new QComboBox(this);
    snakeInfo = new SnakeInfo;
    snakesGroupBox = createAnimalGroupBox(listOfSnakes,snakeInfo);

    tabsOfAnimals->addTab(birdsGroupBox,"Birds");
    tabsOfAnimals->addTab(mammalsGroupBox,"Mammals");
    tabsOfAnimals->addTab(snakesGroupBox,"Snakes");

    return tabsOfAnimals;

}

QGroupBox* Widget::createAnimalGroupBox( QComboBox* listOfAnimals,AnimalInfo* animalInfo){

    QGroupBox* animalGroupBox = new QGroupBox(this);
    QGridLayout *layout = new QGridLayout(this);

    QPushButton* moveAnimalButton = new QPushButton("Move to another zoo",this);
    QPushButton* removeAnimalButton = new QPushButton("Remove Animal",this);
    moveAnimalButton->setDisabled(true);
    removeAnimalButton->setDisabled(true);
    connect(moveAnimalButton, SIGNAL(clicked()),this, SLOT(moveAnimalSlot()));
    connect(removeAnimalButton, SIGNAL(clicked()),this,SLOT(removeAnimalSlot()));

    connect(listOfAnimals, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            [=](const QString &text){
                updateTimer->stop();
                if((listOfAnimals->count() || !text.isEmpty())
                        && mZoo->getAnimalsNames().contains(text))
                {
                    animalInfo->setAnimalInfo(mZoo->getAnimal(text));
                    moveAnimalButton->setDisabled(false);
                    removeAnimalButton->setDisabled(false);
                } else {
                    listOfAnimals->setCurrentText("");
                    animalInfo->clearAnimalInfo();
                    moveAnimalButton->setDisabled(true);
                    removeAnimalButton->setDisabled(true);
                }
                updateTimer->start(3000);
    });

    connect(updateTimer,&QTimer::timeout,
            [=]() {
                if((listOfAnimals->count() || !listOfAnimals->currentText().isEmpty())
                        && mZoo->getAnimalsNames().contains(listOfAnimals->currentText()))
                {
                    animalInfo->setAnimalInfo(mZoo->getAnimal(listOfAnimals->currentText()));
                    moveAnimalButton->setDisabled(false);
                    removeAnimalButton->setDisabled(false);
                } else {
                    listOfAnimals->setCurrentText("");
                    animalInfo->clearAnimalInfo();
                    moveAnimalButton->setDisabled(true);
                    removeAnimalButton->setDisabled(true);
                }
    });

    layout->addWidget(listOfAnimals,0,0,1,2);
    layout->addWidget(animalInfo->getAnimalInfo(),1,0,1,2);
    layout->addWidget(moveAnimalButton,2,0,1,1);
    layout->addWidget(removeAnimalButton,2,1,1,1);

    animalGroupBox->setLayout(layout);
    return animalGroupBox;

}

QStringList Widget::getZooNames() const{
    QStringList list;

    foreach(auto zoo, mZoos){
        list << zoo->getZooName();
    }

    return list;
}

void Widget::changeListOfAnimals(std::shared_ptr<Zoo> zoo, QComboBox* listOfAnimals, AnimalType type){
    listOfAnimals->clear();
    listOfAnimals->addItems(zoo->getSpecificNames(type));
}

void Widget::changeZooSlot(int index){
    mZoo = mZoos[index];
    changeListOfAnimals(mZoo,listOfBirds,BIRD);
    changeListOfAnimals(mZoo,listOfMammals,MAMMAL);
    changeListOfAnimals(mZoo,listOfSnakes,SNAKE);
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
        setWindowTitle(zooName);

        listOfZoo->setItemText(mZoos.indexOf(mZoo),zooName);
    }

}

void Widget::feedingSlot(){
    feedDialog = new FeedDialog;
    feedDialog->setModal(true);
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

void Widget::setTimers(Animal& animal){

    connect(animal.getFeedingTimer(),&QTimer::timeout,
            [&animal](){
                if(animal.getPercentOfFeeding() > 0)
                    animal.decreasePercentOfFeeding();
                else{
                    animal.getFeedingTimer()->stop();

                    QMessageBox* msgBox = new QMessageBox;
                    msgBox->setAttribute( Qt::WA_DeleteOnClose, true );
                    msgBox->setIcon(QMessageBox::Warning);
                    msgBox->setWindowIcon(QIcon(":/images/zoo_icon.png"));
                    msgBox->setWindowTitle("Warning");
                    msgBox->setText(animal.getName()+" is hungry.\n Feed it as soon as possible.");
                    msgBox->exec();

                }

            });
    animal.getFeedingTimer()->start(3000);

    connect(animal.getAgeTimer(),&QTimer::timeout,
            [=,&animal](){
                if(animal.getYears() < 100)
                    animal.increaseAge();
                else{

                    QMessageBox* msgBox = new QMessageBox;
                    msgBox->setAttribute( Qt::WA_DeleteOnClose, true );
                    msgBox->setIcon(QMessageBox::Information);
                    msgBox->setWindowIcon(QIcon(":/images/zoo_icon.png"));
                    msgBox->setWindowTitle("Info");
                    msgBox->setText(animal.getName()+"'s hour has come to end.\n");
                    msgBox->exec();

                    foreach(auto zoo, mZoos){
                        if(zoo->getAnimal(animal.getName())!= nullptr && zoo->getAnimal(animal.getName())->getYears() == 100){
                            zoo->removeAnimal(animal.getName());
                            changeListOfAnimals(zoo,listOfBirds,BIRD);
                            changeListOfAnimals(zoo,listOfMammals,MAMMAL);
                            changeListOfAnimals(zoo,listOfSnakes,SNAKE);
                            break;
                        }
                    }
                }


            });
    animal.getAgeTimer()->start(10000);
}

void Widget::addAnimal( std::shared_ptr<Animal> animal, QComboBox* listOfAnomals){

    qDebug()<< "After add" <<  animal.use_count();
    mZoo->addAnimal(animal);
    qDebug()<< "After 2add" <<  animal.use_count();
    listOfAnomals->addItem(animal->getName());
    setTimers(*animal);
    qDebug()<< "After 3add" <<  animal.use_count();

}

void Widget::addAnimalSlot(){

    wizard = new AnimalWizard(mZoo->getAnimalsNames());
    wizard->setModal(true);
    wizard->resize(700,400);
    wizard->show();

    if (wizard->exec())
    {
        std::shared_ptr<Animal> animal(&(wizard->getAnimal()));
        switch(wizard->getPath())
        {
        case BIRD:
        {
            qDebug()<< "Before add" <<animal.use_count();
            addAnimal( animal, listOfBirds);
            qDebug()<< "After 4add" << animal.use_count();
        break;
        }

        case MAMMAL:
        {
            qDebug()<< "Before add" << animal.use_count();
            addAnimal( animal, listOfMammals);
            qDebug()<< "After 4add" << animal.use_count();
        break;
        }

        case SNAKE:
        {
            qDebug()<< "Before add" << animal.use_count();
            addAnimal( animal, listOfSnakes);
            qDebug()<< "After 4add" << animal.use_count();
        break;
        }
        }

    }
}


void Widget::removeAnimalSlot(){
    mZoo->removeAnimal( getCurrentListOfAnimals()->currentText());
    changeListOfAnimals(mZoo,listOfBirds,BIRD);
    changeListOfAnimals(mZoo,listOfMammals,MAMMAL);
    changeListOfAnimals(mZoo,listOfSnakes,SNAKE);
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

void Widget::moveAnimalSlot(){
    moveDialog = new MoveDialog(getZooNames(), mZoo->getZooName());
    moveDialog->setModal(true);
    moveDialog->show();

    if(moveDialog->exec())
    {
        QString selectedZooName = moveDialog->getSelectedZooName();
        QString currAnimalName = getCurrentListOfAnimals()->currentText();
        std::shared_ptr<Animal> currAnimal = mZoo->getAnimal(currAnimalName);

        foreach (auto zoo, mZoos) {
            if(zoo->getZooName() == selectedZooName){
                if(zoo->getAnimalsNames().contains(currAnimalName)){

                    QMessageBox* msgBox = new QMessageBox(this);
                    msgBox->setAttribute( Qt::WA_DeleteOnClose, true );
                    msgBox->setText("Animal with this name has already existed in that zoo.");
                    msgBox->setIcon(QMessageBox::Warning);
                    msgBox->setInformativeText("Do you want to rename the animal?");
                    msgBox->addButton("Rename", QMessageBox::AcceptRole);
                    msgBox->addButton("Cancel", QMessageBox::RejectRole);
                    msgBox->setWindowIcon(QIcon(":/images/zoo_icon.png"));
                    msgBox->setWindowTitle("Warning");

                    if(msgBox->exec() == QMessageBox::AcceptRole){

                        renameDialog = new RenameDialog(*currAnimal,zoo);
                        renameDialog->setModal(true);
                        renameDialog->show();

                        if(!renameDialog->exec()){
                            break;
                        }
                    }
                }
                mZoo->removeAnimal(currAnimal->getName());
                changeListOfAnimals(mZoo,getCurrentListOfAnimals(),currAnimal->getType());
                zoo->addAnimal(currAnimal);
                break;
            }
        }
    }
}

void Widget::read(const QJsonObject &json){
    updateTimer->stop();
    try{
    if (json.contains("zoos") && json["zoos"].isArray()) {
            QJsonArray zoosArray = json["zoos"].toArray();

            for (int zooIndex = 0; zooIndex < zoosArray.size(); ++zooIndex) {
                QJsonObject zooObject = zoosArray[zooIndex].toObject();
                mZoos[zooIndex]->read(zooObject);
            }
        }
    }
    catch(const std::exception & ex){
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setAttribute( Qt::WA_DeleteOnClose, true );
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->setWindowIcon(QIcon(":/images/zoo_icon.png"));
        msgBox->setWindowTitle("Error");
        msgBox->setText(ex.what());
        msgBox->exec();
        this->close();

    }

    QStringList newList = getZooNames();
    foreach(auto zoo, mZoos){
        listOfZoo->setItemText(mZoos.indexOf(zoo),newList[mZoos.indexOf(zoo)]);

        QStringList names = zoo->getAnimalsNames();
        for(int i = 0; i < names.size();i++){
            setTimers(*(zoo->getAnimal(names[i])));
        }
    }
    changeZooSlot(listOfZoo->currentIndex());
    updateTimer->start(3000);
}



void Widget::write(QJsonObject &json) const{
    QJsonArray zoosArray;
       foreach (auto zoo, mZoos) {
           QJsonObject zooObject;
           zoo->write(zooObject);
           zoosArray.append(zooObject);
       }
       json["zoos"] = zoosArray;
}

bool Widget::loadApp()
{
    QString file = QFileDialog::getOpenFileName(this, "Open json files", ".//", "*.json");
    QFile loadFile(file);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    read(loadDoc.object());

    return true;
}
bool Widget::saveApp()
{
    const QString ext = ".json" ;
    QString file = QFileDialog::getSaveFileName(this, "Save zoos into file", ".//", "*"+ext).trimmed();
    if (file.right(ext.length()).toLower() != ext)
    {
        file += ext;
    }

    QFile saveFile(file);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject appObject;
    write(appObject);
    QJsonDocument saveDoc(appObject);
    saveFile.write(saveDoc.toJson(QJsonDocument::Indented));

    return true;
}

Widget::~Widget(){
    delete ui;
}
