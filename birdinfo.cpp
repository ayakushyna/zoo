#include "birdinfo.h"

BirdInfo::BirdInfo(): AnimalInfo()
{
    birdInfo = new QGroupBox("Bird Info");
    currLengthOfWings = new QLabel;
    currPredator = new QLabel;

    layout->addWidget(currLengthOfWings);
    layout->addWidget(currPredator);

    birdInfo->setLayout(layout);
}

QGroupBox* BirdInfo::getAnimalInfo() const { return birdInfo;}

void BirdInfo::setAnimalInfo(Animal* animal)
{
    AnimalInfo::setAnimalInfo(animal);
    currLengthOfWings->setText(QStringLiteral("Length of wings: %1").arg(dynamic_cast<Bird*>(animal)->getLengthOfWings()));
    currPredator->setText("Predator: " + QString((dynamic_cast<Bird*>(animal)->getPredator()? "yes":"no")));
}

void BirdInfo::clearAnimalInfo(){
    AnimalInfo::clearAnimalInfo();
    currLengthOfWings->clear();
    currPredator->clear();
}
