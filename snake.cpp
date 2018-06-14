#include "snake.h"

Snake::Snake() :Animal(), mLength(0), mPoisonous(0) {}

Snake::Snake(const QString& name, int years, int months ,double weight,
             int percentOfFeeding, const QString& species, double length, bool poisonous)
    :Animal( name, years, months, weight,  percentOfFeeding, species),
        mLength(length),mPoisonous(poisonous){

    //if(checkLength(length) == 0)
    //    throw InvalidData();

    mType = SNAKE;
}

void Snake::setLength(double length){
    mLength = length;
}

double Snake::getLength() const {return mLength;}

void Snake::setPoisonous(bool poisonous){
    mPoisonous=poisonous;
}

bool Snake::getPoisonous()const {return mPoisonous;}

bool Snake::checkLength(double length){
    return length > 0. && length <= 12.;
}

bool Snake::feed(const Food& food){
    feedingTimer->stop();
    if(mPercentOfFeeding+food.getFoodPercentIncrease() > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=food.getFoodPercentIncrease();
    feedingTimer->start(3000);
    return true;
}

void Snake::read(const QJsonObject &json){
    Animal::read(json);

    if (json.contains("length") && json["length"].isDouble() && checkLength(json["length"].toDouble()))
            mLength = json["length"].toDouble();
    else throw InvalidData();

    if (json.contains("poisonous") && json["poisonous"].isBool())
            mPoisonous = json["poisonous"].toBool();
    else throw InvalidData();
}

void Snake::write(QJsonObject &json) const {
    Animal::write(json);
    json["length"] = mLength;
    json["poisonous"] = mPoisonous;
}

Snake::~Snake() {}
