#include "snake.h"

Snake::Snake() :Animal(), mLength(0), mPoisonous(0) {}

Snake::Snake(const QString& name, int age,double weight, int percentOfFeeding,
     const QString& species,double length,bool poisonous)
    :Animal( name,  age, weight,  percentOfFeeding, species),
      mLength(length),mPoisonous(poisonous){}

void Snake::setLength(double length){
    mLength = length;
}

double Snake::getLength() const {return mLength;}

void Snake::setPoisonous(bool poisonous){
    mPoisonous=poisonous;
}

bool Snake::getPoisonous()const {return mPoisonous;}

Snake::~Snake() {}

bool  Snake::feed(const QString& foodType, double foodWeight){}
