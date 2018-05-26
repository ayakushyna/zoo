#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"
#include "shared_defs.h"
class Mammal:public Animal
{
public:
    Mammal();
    Mammal(const QString& name,Animaltype type, int years, int months, double weight,
           int percentOfFeeding,const QString& species,int milkPeriod);
    ~Mammal();

    void setMilkPeriod(int milkPeriod);
    int getMilkPeriod()const;

    bool feed(const QString& foodType, int percentIncrease);
private:
    int mMilkPeriod;
};

#endif // MAMMAL_H
