#include "mammalinfo.h"


MammalInfo::MammalInfo(): AnimalInfo()
{
    mammalInfo = new QGroupBox("Mammal Info");
    currMilkPeriod = new QLabel;
    currPredator = new QLabel;

    layout->addWidget(currMilkPeriod);
    layout->addWidget(currPredator);

    mammalInfo->setLayout(layout);
}

QGroupBox* MammalInfo::getAnimalInfo() const { return mammalInfo;}

void MammalInfo::setAnimalInfo(Animal* animal)
{
    AnimalInfo::setAnimalInfo(animal);
    currMilkPeriod->setText(QStringLiteral("Milk period: %1").arg(dynamic_cast<Mammal*>(animal)->getMilkPeriod()));
    currPredator->setText("Predator: " + QString((dynamic_cast<Mammal*>(animal)->getPredator()? "yes":"no")));
}

void MammalInfo::clearAnimalInfo(){
    AnimalInfo::clearAnimalInfo();
    currMilkPeriod->clear();
    currPredator->clear();
}
