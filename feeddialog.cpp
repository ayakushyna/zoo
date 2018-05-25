#include "feeddialog.h"

FeedDialog::FeedDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Animal Feeding");
    QGridLayout* layout = new QGridLayout;

    QLabel* animalTypeLabel = new QLabel("Choose a type of animals:");
    QStringList animalTypes= {"Bird","Mammal","Snake"};
    QComboBox* listOfAnimalTypes = new QComboBox;
    listOfAnimalTypes->addItems(animalTypes);

    QList <QStringList> foodTypes;
    QStringList birdFood = {"Seeds","Millet"};
    foodTypes.push_back(birdFood);
    QStringList mammalFood = {"Grass","Meat","Milk"};
    foodTypes.push_back(mammalFood);
    QStringList snakeFood = {"Insects", "Mouse"};
    foodTypes.push_back(snakeFood);

    QLabel* foodTypeLabel = new QLabel("Choose a type of food:");
    QComboBox* listOfFoodTypes = new QComboBox;
    listOfFoodTypes->addItems(foodTypes[0]);

    connect(listOfAnimalTypes, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [=](int index){
                listOfFoodTypes->clear();
                listOfFoodTypes->addItems(foodTypes[index]);
    });

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton("OK", QDialogButtonBox::AcceptRole);
    buttonBox->addButton("Cancel",QDialogButtonBox::RejectRole);

    layout->addWidget(animalTypeLabel,0,0);
    layout->addWidget(listOfAnimalTypes,0,1);
    layout->addWidget(foodTypeLabel,1,0);
    layout->addWidget(listOfFoodTypes,1,1);
    layout->addWidget(buttonBox,2,1);

    setLayout(layout);
}

FeedDialog::~FeedDialog() {}
