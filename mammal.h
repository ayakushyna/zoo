#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"
class Mammal:public Animal
{
public:
    Mammal();
    Mammal(const QString& name, int age,double weight, int percentOfFeeding,
           const QString& species,int milkPeriod);
    ~Mammal();

    void setMilkPeriod(int milkPeriod);
    int getMilkPeriod()const;

    bool feed(const QString& foodType, double foodWeight);
private:
    int mMilkPeriod;
};

#endif // MAMMAL_H
