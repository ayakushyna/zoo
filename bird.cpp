#include "bird.h"

Bird::Bird(): Animal(), mLengthOfWings(0), mPredator(0) {}

Bird::Bird(const QString& name, int age,double weight, int percentOfFeeding,
           const QString& species,double lengthOfWings,bool predator)
    :Animal( name, age, weight,   percentOfFeeding, species),
      mLengthOfWings(lengthOfWings),mPredator(predator){}

void Bird::setLengthOfWings(double lengthOfWings0){
    mLengthOfWings = lengthOfWings0;
}
double Bird::getLengthOfWings() const { return mLengthOfWings;}

void Bird::setPredator(bool predator0){
    mPredator=predator0;
}

bool Bird::getPredator() const { return mPredator;}

Bird::~Bird() {}
