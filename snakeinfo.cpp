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

void SnakeInfo::setAnimalInfo(std::shared_ptr<Animal> animal)
{
    AnimalInfo::setAnimalInfo(animal);
    currLength->setText(QStringLiteral("Length: %1").arg(std::dynamic_pointer_cast<Snake>(animal)->getLength()));
    currPoisonous->setText("Poisonous: " +  QString((std::dynamic_pointer_cast<Snake>(animal)->getPoisonous()? "yes": "no")));
}

void SnakeInfo::clearAnimalInfo(){
    AnimalInfo::clearAnimalInfo();
    currLength->clear();
    currPoisonous->clear();
}
