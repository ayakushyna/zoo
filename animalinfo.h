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
    AnimalInfo(int type);
    ~AnimalInfo();

    QGroupBox* getBirdInfo();
    QGroupBox* getMammalInfo();
    QGroupBox* getSnakeInfo();

public slots:
    void setAnimalInfo(int type,Animal* animal);

private:
    QLabel* currImage;
    QLabel* currName;
    QLabel* currAge;
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
