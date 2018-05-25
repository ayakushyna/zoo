#include "bird.h"

Bird::Bird(): Animal(), mLengthOfWings(0), mPredator(0) {}

Bird::Bird(const QString& name, int age,double weight, int percentOfFeeding,
           const QString& species,double lengthOfWings,bool predator)
    :Animal( name, age, weight,   percentOfFeeding, species),
      mLengthOfWings(lengthOfWings),mPredator(predator){}

void Bird::setLengthOfWings(double lengthOfWings){
    mLengthOfWings = lengthOfWings;
}
double Bird::getLengthOfWings() const { return mLengthOfWings;}

void Bird::setPredator(bool predator){
    mPredator=predator;
}

bool Bird::getPredator() const { return mPredator;}

Bird::~Bird() {}

bool  Bird::feed(const QString& foodType, double foodWeight){}
