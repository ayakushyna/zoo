#include "bird.h"

Bird::Bird(): Animal(), mLengthOfWings(0), mPredator(0) {}

Bird::Bird(const QString& name,Animaltype type, int years, int months,double weight,
           int percentOfFeeding, const QString& species,double lengthOfWings,bool predator)
    :Animal( name, type, years, months, weight,   percentOfFeeding, species),
      mLengthOfWings(lengthOfWings),mPredator(predator){}

void Bird::setLengthOfWings(double lengthOfWings){
    mLengthOfWings = lengthOfWings;
}
double Bird::getLengthOfWings() const { return mLengthOfWings;}

void Bird::setPredator(bool predator){
    mPredator = predator;
}

bool Bird::getPredator() const { return mPredator;}

bool Bird::feed(const QString& foodType, int percentIncrease){
    if(mPredator && foodType != "Fish")
        return false;

    if(!mPredator && foodType == "Fish")
        return false;

    if(mPercentOfFeeding+percentIncrease > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=percentIncrease;

    return true;
}

Bird::~Bird() {}
