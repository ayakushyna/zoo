#include "snake.h"

Snake::Snake() :Animal(), mLength(0), mPoisonous(0) {}

Snake::Snake(const QString& name, AnimalType type,  int years, int months ,double weight,
             int percentOfFeeding, const QString& species, double length, bool poisonous)
    :Animal( name, type, years, months, weight,  percentOfFeeding, species),
      mLength(length),mPoisonous(poisonous){}

void Snake::setLength(double length){
    mLength = length;
}

double Snake::getLength() const {return mLength;}

void Snake::setPoisonous(bool poisonous){
    mPoisonous=poisonous;
}

bool Snake::getPoisonous()const {return mPoisonous;}

bool Snake::feed(const Food& food){
    if(mPercentOfFeeding+food.getFoodPercentIncrease() > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=food.getFoodPercentIncrease();

    return true;
}

Snake::~Snake() {}
