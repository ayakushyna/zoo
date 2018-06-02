#include "snakeinfo.h"

SnakeInfo::SnakeInfo(): AnimalInfo()
{
    snakeInfo = new QGroupBox("Snake Info");
    currLength = new QLabel;
    currPoisonous = new QLabel;

    layout->addWidget(currLength);
    layout->addWidget(currPoisonous);

    snakeInfo->setLayout(layout);
}

QGroupBox* SnakeInfo::getAnimalInfo() const { return snakeInfo;}

void SnakeInfo::setAnimalInfo(Animal* animal)
{
    AnimalInfo::setAnimalInfo(animal);
    currLength->setText(QStringLiteral("Length: %1").arg(dynamic_cast<Snake*>(animal)->getLength()));
    currPoisonous->setText("Poisonous: " +  QString((dynamic_cast<Snake*>(animal)->getPoisonous()? "yes": "no")));
}

void SnakeInfo::clearAnimalInfo(){
    AnimalInfo::clearAnimalInfo();
    currLength->clear();
    currPoisonous->clear();
}
