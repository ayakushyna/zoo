#include "animalinfo.h"

AnimalInfo::AnimalInfo(Animaltype type)
{
    currImage = new QLabel;
    currImage->setAlignment(Qt::AlignCenter);

    currName = new QLabel;
    currYears = new QLabel;
    currMonths = new QLabel;
    currWeight = new QLabel;
    currPercentOfFeeding = new QLabel;
    currSpecies = new QLabel;
    switch(type)
    {
    case BIRD:
    {
        birdInfo = new QGroupBox("Bird Info");
        QVBoxLayout *layout = new QVBoxLayout;
        currLengthOfWings = new QLabel;
        currPredator = new QLabel;

        layout->addWidget(currImage);
        layout->addWidget(currName);
        layout->addWidget(currYears);
        layout->addWidget(currMonths);
        layout->addWidget(currWeight);
        layout->addWidget(currPercentOfFeeding);
        layout->addWidget(currSpecies);
        layout->addWidget(currLengthOfWings);
        layout->addWidget(currPredator);

        birdInfo->setLayout(layout);
        break;
    }
    case MAMMAL:
    {
        mammalInfo = new QGroupBox("Mammal Info");
        QVBoxLayout *layout = new QVBoxLayout;
        currMilkPeriod = new QLabel;

        layout->addWidget(currImage);
        layout->addWidget(currName);
        layout->addWidget(currYears);
        layout->addWidget(currMonths);
        layout->addWidget(currWeight);
        layout->addWidget(currPercentOfFeeding);
        layout->addWidget(currSpecies);
        layout->addWidget(currMilkPeriod);

        mammalInfo->setLayout(layout);
        break;
    }
    case SNAKE:
    {
        snakeInfo = new QGroupBox("Snake Info");
        QVBoxLayout *layout = new QVBoxLayout;

        currLength = new QLabel;
        currPoisonous = new QLabel;

        layout->addWidget(currImage);
        layout->addWidget(currName);
        layout->addWidget(currYears);
        layout->addWidget(currMonths);
        layout->addWidget(currWeight);
        layout->addWidget(currPercentOfFeeding);
        layout->addWidget(currSpecies);
        layout->addWidget(currLength);
        layout->addWidget(currPoisonous);


        snakeInfo->setLayout(layout);
        break;
    }
    }
}

QGroupBox* AnimalInfo::getBirdInfo(){ return birdInfo;}

QGroupBox* AnimalInfo::getMammalInfo(){ return mammalInfo;}

QGroupBox* AnimalInfo::getSnakeInfo(){ return snakeInfo;}

void AnimalInfo::setAnimalInfo(Animaltype type,Animal* animal)
{
    currImage->setPixmap(QPixmap(":/images/" + animal->getSpecies() + ".png"));
    currName->setText("Name: "+ animal->getName());
    currYears->setText( QStringLiteral("Years: %1").arg(animal->getYears()));
    currMonths->setText( QStringLiteral("Months: %1").arg(animal->getMonths()));
    currWeight->setText(QStringLiteral("Weight: %1").arg(animal->getWeight()));
    currPercentOfFeeding->setText(QStringLiteral("Percent of feeding: %1").arg(animal->getPercentOfFeeding()));
    currSpecies->setText("Species: "+ animal->getSpecies());
    switch(type)
    {
    case BIRD:
    {
        currLengthOfWings->setText(QStringLiteral("Length of wings: %1").arg(dynamic_cast<Bird*>(animal)->getLengthOfWings()));
        currPredator->setText("Predator: " + QString((dynamic_cast<Bird*>(animal)->getPredator()? "yes":"no")));
        break;
    }
    case MAMMAL:
    {
        currMilkPeriod->setText(QStringLiteral("Milk period: %1").arg(dynamic_cast<Mammal*>(animal)->getMilkPeriod()));
        break;
    }
    case SNAKE:
    {
        currLength->setText(QStringLiteral("Length: %1").arg(dynamic_cast<Snake*>(animal)->getLength()));
        currPoisonous->setText("Poisonous: " +  QString((dynamic_cast<Snake*>(animal)->getPoisonous()? "yes": "no")));
        break;
    }
    }

}


AnimalInfo::~AnimalInfo(){}
