#ifndef MAMMALINFO_H
#define MAMMALINFO_H
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

class MammalInfo:public AnimalInfo
{
public:
    MammalInfo();
    ~MammalInfo();
    QGroupBox* getAnimalInfo() const;

public slots:
    void setAnimalInfo(std::shared_ptr<Animal> animal);
    void clearAnimalInfo();

private:
    QLabel* currMilkPeriod;
    QLabel* currPredator;
    QGroupBox* mammalInfo;
};

#endif // MAMMALINFO_H
