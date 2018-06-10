#ifndef BIRDINFO_H
#define BIRDINFO_H
#include <memory>
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

class BirdInfo:public AnimalInfo
{
public:
    BirdInfo();
    ~BirdInfo();
    QGroupBox* getAnimalInfo() const;

public slots:
    void setAnimalInfo(std::shared_ptr<Animal> animal);
    void clearAnimalInfo();

private:
    QLabel* currLengthOfWings;
    QLabel* currPredator;
    QGroupBox* birdInfo;
};

#endif // BIRDINFO_H
