#include "animalinfo.h"

AnimalInfo::AnimalInfo()
{
    layout = new QVBoxLayout;
    currImage = new QLabel;
    currImage->setAlignment(Qt::AlignCenter);

    currName = new QLabel;
    currYears = new QLabel;
    currMonths = new QLabel;
    currWeight = new QLabel;
    currPercentOfFeeding = new QLabel;
    currSpecies = new QLabel;

    layout->addWidget(currImage);
    layout->addWidget(currName);
    layout->addWidget(currYears);
    layout->addWidget(currMonths);
    layout->addWidget(currWeight);
    layout->addWidget(currPercentOfFeeding);
    layout->addWidget(currSpecies);

}

void AnimalInfo::setAnimalInfo(Animal* animal)
{
    currImage->setPixmap(QPixmap(":/images/" + animal->getSpecies() + ".png"));
    currName->setText("Name: "+ animal->getName());
    currYears->setText( QStringLiteral("Years: %1").arg(animal->getYears()));
    currMonths->setText( QStringLiteral("Months: %1").arg(animal->getMonths()));
    currWeight->setText(QStringLiteral("Weight: %1").arg(animal->getWeight()));
    currPercentOfFeeding->setText(QStringLiteral("Percent of feeding: %1").arg(animal->getPercentOfFeeding()));
    currSpecies->setText("Species: "+ animal->getSpecies());

}

void AnimalInfo::clearAnimalInfo(){
    currImage->clear();
    currName->clear();
    currYears->clear();
    currMonths->clear();
    currWeight->clear();
    currPercentOfFeeding->clear();
    currSpecies->clear();

}

AnimalInfo::~AnimalInfo(){}
