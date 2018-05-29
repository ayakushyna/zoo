#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <QtWidgets>
#include "shared_defs.h"

class Animal
{

public:
    Animal();
    Animal(const QString& name,Animaltype type, int years, int months, double weight, int percentOfFeeding,const QString& species);
    virtual ~Animal();

    void setName(const QString& name);
    QString getName() const;
    void setType(Animaltype type);
    Animaltype getType() const;
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

    void riseAge();
    void declinePercentOfFeeding();
    virtual bool feed(const QString& foodType, int percentIncrease) = 0;
    void moveToAnotherZoo();

protected:
    QString mName;
    Animaltype mType;
    int mYears, mMonths;
    double mWeight;
    int mPercentOfFeeding;
    QString mSpecies;
};

#endif // ANIMAL_H
