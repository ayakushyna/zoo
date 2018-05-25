#include "mammal.h"

Mammal::Mammal(): Animal(), mMilkPeriod(0) {}

Mammal::Mammal(const QString& name, int age,double weight, int percentOfFeeding,
               const QString& species,int milkPeriod)
    :Animal( name,  age,  weight, percentOfFeeding, species),
      mMilkPeriod(milkPeriod){}


void Mammal::setMilkPeriod(int milkPeriod){
    mMilkPeriod = milkPeriod;
}

int Mammal::getMilkPeriod()const { return mMilkPeriod; }

Mammal::~Mammal() {}

bool  Mammal::feed(const QString& foodType, double foodWeight){}
