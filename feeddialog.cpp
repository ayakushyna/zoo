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
    QStringList birdFood = {"Seeds","Millet"};
    foodTypes.push_back(birdFood);
    QStringList mammalFood = {"Grass","Meat","Milk"};
    foodTypes.push_back(mammalFood);
    QStringList snakeFood = {"Insects", "Mouse"};
    foodTypes.push_back(snakeFood);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                      |QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

    QLabel* foodTypeLabel = new QLabel("Choose a type of food:");
    listOfFoodTypes = new QComboBox;
    listOfFoodTypes->addItems(foodTypes[0]);

    connect(animalButtons, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            [=](int id){
                listOfFoodTypes->clear();
                listOfFoodTypes->addItems(foodTypes[id]);
                buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    });

    layout->addWidget(animalTypeLabel,0,0);
    layout->addWidget(birdButton,0,1);
    layout->addWidget(mammalButton,1,1);
    layout->addWidget(snakeButton,2,1);
    layout->addWidget(foodTypeLabel,3,0);
    layout->addWidget(listOfFoodTypes,3,1);
    layout->addWidget(buttonBox,4,1);

    setLayout(layout);
}

const QMap<QString,int> FeedDialog::food = {{ "Seeds", 37 }, { "Millet", 40 },
                                            { "Grass", 15 }, { "Meat", 20 }, { "Milk", 40 },
                                            { "Insects", 15 }, { "Mouse", 20 }};

void FeedDialog::accept(){
    animalType = static_cast<Animaltype>(animalButtons->checkedId());
    foodType = listOfFoodTypes->currentText();
    percentIncrease = food.value(listOfFoodTypes->currentText());
    QDialog::accept();
}

Animaltype FeedDialog::getAnimalType ()const{ return animalType; }

QString FeedDialog::getFoodType ()const{ return foodType; }

int FeedDialog::getPercentIncrease ()const{ return percentIncrease; }

FeedDialog::~FeedDialog() {}
