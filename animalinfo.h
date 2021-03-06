#ifndef ANIMALINFO_H
#define ANIMALINFO_H
#include <memory>
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

    virtual QGroupBox* getAnimalInfo() const = 0;

public slots:
    virtual void setAnimalInfo(std::shared_ptr<Animal> animal);
    virtual void clearAnimalInfo();

protected:
    QVBoxLayout *layout;

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
