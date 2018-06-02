#ifndef SNAKEINFO_H
#define SNAKEINFO_H

#include "animal.h"
#include "animalinfo.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include "shared_defs.h"
#include "animalwizard.h"
#include <QtWidgets>
#include <QString>

class SnakeInfo:public AnimalInfo
{
public:
    SnakeInfo();
    ~SnakeInfo();
    QGroupBox* getAnimalInfo() const;

public slots:
    void setAnimalInfo(Animal* animal);
    void clearAnimalInfo();

private:
    QLabel* currLength;
    QLabel* currPoisonous;
    QGroupBox* snakeInfo;
};

#endif // SNAKEINFO_H
