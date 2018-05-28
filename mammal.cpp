#include "mammal.h"

Mammal::Mammal(): Animal(), mMilkPeriod(0), mPredator(0) {}

Mammal::Mammal(const QString& name,Animaltype type,  int years, int months, double weight,
               int percentOfFeeding, const QString& species, int milkPeriod, bool predator)
    :Animal( name, type, years, months, weight, percentOfFeeding, species),
      mMilkPeriod(milkPeriod), mPredator(predator){}


void Mammal::setMilkPeriod(int milkPeriod){
    mMilkPeriod = milkPeriod;
}

int Mammal::getMilkPeriod()const { return mMilkPeriod; }

void Mammal::setPredator(bool predator){
    mPredator = predator;
}

bool Mammal::getPredator() const { return mPredator;}

bool Mammal::feed(const QString& foodType, int percentIncrease){
    if(( mYears == 0 && mMonths <= mMilkPeriod && foodType != "Milk") ||
      (( mYears > 0 || (mYears == 0 && mMonths >  mMilkPeriod) ) && foodType == "Milk"))
        return false;

    if(mPredator && ( mYears > 0 || (mYears == 0 && mMonths >  mMilkPeriod)) && foodType != "Meat")
        return false;

    if(mPercentOfFeeding+percentIncrease > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=percentIncrease;

    return true;
}

Mammal::~Mammal() {}
