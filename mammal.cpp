#include "mammal.h"

Mammal::Mammal(): Animal(), mMilkPeriod(0), mPredator(0) {}

Mammal::Mammal(const QString& name,AnimalType type,  int years, int months, double weight,
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

bool Mammal::feed(const Food& food){
    if(( mYears == 0 && mMonths <= mMilkPeriod && food.getFoodName() != "Milk") ||
      (( mYears > 0 || (mYears == 0 && mMonths >  mMilkPeriod) ) && food.getFoodName() == "Milk"))
        return false;

    if(mPredator && ( mYears > 0 || (mYears == 0 && mMonths >  mMilkPeriod)) && !food.getPredatorFood())
        return false;

    if(!mPredator && food.getPredatorFood())
        return false;

    if(mPercentOfFeeding+food.getFoodPercentIncrease() > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=food.getFoodPercentIncrease();

    return true;
}

Mammal::~Mammal() {}
