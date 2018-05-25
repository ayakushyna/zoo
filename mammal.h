#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"
class Mammal:public Animal
{
public:
    Mammal();
    Mammal(const QString& name, int age,double weight, int percentOfFeeding,
           const QString& species,int milkPeriod);
    void setMilkPeriod(int milkPeriod);
    int getMilkPeriod()const;
    ~Mammal();

private:
    int mMilkPeriod;
};

#endif // MAMMAL_H
