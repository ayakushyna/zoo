#ifndef ANIMALINFO_H
#define ANIMALINFO_H

#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include "shared_defs.h"
#include "animalwizard.h"
#include <QtWidgets>
#include <QString>

class AnimalInfo
{
public:
    AnimalInfo(Animaltype type);
    ~AnimalInfo();

    QGroupBox* getBirdInfo() const;
    QGroupBox* getMammalInfo() const;
    QGroupBox* getSnakeInfo() const;

public slots:
    void setAnimalInfo(Animaltype type,Animal* animal);
    void clearAnimalInfo(Animaltype type);

private:
    QLabel* currImage;
    QLabel* currName;
    QLabel* currYears;
    QLabel* currMonths;
    QLabel* currWeight;
    QLabel* currPercentOfFeeding;
    QLabel* currSpecies;

    QLabel* currLengthOfWings;
    QLabel* currPredator;

    QLabel* currMilkPeriod;

    QLabel* currLength;
    QLabel* currPoisonous;

    QGroupBox* birdInfo;
    QGroupBox* mammalInfo;
    QGroupBox* snakeInfo;

};

#endif // ANIMALINFO_H
