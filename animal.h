#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <QtWidgets>
#include "shared_defs.h"
#include "food.h"

class Animal
{

public:
    Animal();
    Animal(const QString& name,AnimalType type, int years, int months, double weight, int percentOfFeeding,const QString& species);
    virtual ~Animal();

    void setName(const QString& name);
    QString getName() const;
    void setType(AnimalType type);
    AnimalType getType() const;
    void setYears(int years);
    int getYears() const;
    void setMonths(int months);
    int getMonths() const;
    void setWeight(double weight);
    double getWeight() const;
    void setPercentOfFeeding(int percentOfFeeding);
    int getPercentOfFeeding() const;
    void setSpecies(const QString& species);
    QString getSpecies() const;

    void increaseAge();
    void decreasePercentOfFeeding();
    virtual bool feed(const Food& food) = 0;
    void moveToAnotherZoo();

protected:
    QString mName;
    AnimalType mType;
    int mYears, mMonths;
    double mWeight;
    int mPercentOfFeeding;
    QString mSpecies;
};

#endif // ANIMAL_H
