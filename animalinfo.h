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
    AnimalInfo();
    ~AnimalInfo();

    QVBoxLayout *layout;
public slots:
    void setAnimalInfo(Animal* animal);
    void clearAnimalInfo();

private:
    QLabel* currImage;
    QLabel* currName;
    QLabel* currYears;
    QLabel* currMonths;
    QLabel* currWeight;
    QLabel* currPercentOfFeeding;
    QLabel* currSpecies;

};

#endif // ANIMALINFO_H
