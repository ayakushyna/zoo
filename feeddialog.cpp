#include "feeddialog.h"

FeedDialog::FeedDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Animal Feeding");
    QGridLayout* layout = new QGridLayout;

    QLabel* animalTypeLabel = new QLabel("Choose a type of animals:");
    animalButtons = new QButtonGroup;
    QRadioButton* birdButton = new QRadioButton("Birds");
    QRadioButton* mammalButton = new QRadioButton("Mammals");
    QRadioButton* snakeButton = new QRadioButton("Snakes");

    animalButtons->addButton(birdButton,BIRD);
    animalButtons->addButton(mammalButton,MAMMAL);
    animalButtons->addButton(snakeButton,SNAKE);

    QList <QStringList> foodTypes;
    foodTypes.push_back(QStringList(" "));

    QStringList birdFood, mammalFood,snakeFood ;
    foreach(Food food, mFoods){
        if(food.getFoodAnimalType() == BIRD)
            birdFood << food.getFoodName();
        if(food.getFoodAnimalType() == MAMMAL)
            mammalFood << food.getFoodName();
        if(food.getFoodAnimalType() == SNAKE)
            snakeFood << food.getFoodName();
    }
    foodTypes.push_back(birdFood);
    foodTypes.push_back(mammalFood);
    foodTypes.push_back(snakeFood);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                      |QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

    QLabel* foodTypeLabel = new QLabel("Choose a type of food:");
    listOfFood = new QComboBox;
    listOfFood->addItems(foodTypes[0]);

    connect(animalButtons, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            [=](int id){
                listOfFood->clear();
                listOfFood->addItems(foodTypes[id]);
                buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    });

    layout->addWidget(animalTypeLabel,0,0);
    layout->addWidget(birdButton,0,1);
    layout->addWidget(mammalButton,1,1);
    layout->addWidget(snakeButton,2,1);
    layout->addWidget(foodTypeLabel,3,0);
    layout->addWidget(listOfFood,3,1);
    layout->addWidget(buttonBox,4,1);

    setLayout(layout);
    setWindowIcon(QIcon(":/images/zoo_icon.png"));
}

const QVector<Food> FeedDialog::mFoods = { Food(BIRD, "Seeds", 30),Food(BIRD, "Millet", 20),Food(BIRD, "Fish", 50),
                                           Food(MAMMAL, "Grass", 30),Food(MAMMAL, "Meat", 50),Food(MAMMAL, "Milk", 40),
                                           Food(SNAKE, "Insects", 30),Food(SNAKE, "Mouse", 50)};

void FeedDialog::accept(){
    QString name = listOfFood->currentText();

    foreach(Food food, mFoods){
        if(name == food.getFoodName()){
            mFood = food;
            break;
        }
    }

    QDialog::accept();
}

Food FeedDialog::getSelectedFood() const { return mFood; }

FeedDialog::~FeedDialog() {}
