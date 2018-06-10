#include "bird.h"

Bird::Bird(): Animal(), mLengthOfWings(0), mPredator(0) {}

Bird::Bird(const QString& name, int years, int months,double weight,
           int percentOfFeeding, const QString& species,double lengthOfWings,bool predator)
    :Animal( name, years, months, weight,   percentOfFeeding, species),
        mLengthOfWings(lengthOfWings),mPredator(predator){
    mType = BIRD;
}

void Bird::setLengthOfWings(double lengthOfWings){
    mLengthOfWings = lengthOfWings;
}
double Bird::getLengthOfWings() const { return mLengthOfWings;}

void Bird::setPredator(bool predator){
    mPredator = predator;
}

bool Bird::getPredator() const { return mPredator;}

bool Bird::checkLengthOfWings(double lengthOfWings){
    return lengthOfWings > 0 && lengthOfWings <=3;
}

bool Bird::feed(const Food& food){
    if(mPredator && !food.getPredatorFood())
        return false;

    if(!mPredator && food.getPredatorFood())
        return false;

    if(mPercentOfFeeding+food.getFoodPercentIncrease() > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=food.getFoodPercentIncrease();

    return true;
}

void Bird::read(const QJsonObject &json){
    Animal::read(json);
    if (json.contains("lengthOfWings") && json["lengthOfWings"].isDouble())
            mLengthOfWings = json["lengthOfWings"].toDouble();

    if (json.contains("predator") && json["predator"].isBool())
            mPredator = json["predator"].toBool();
}

void Bird::write(QJsonObject &json) const {
    Animal::write(json);
    json["lengthOfWings"] = mLengthOfWings;
    json["predator"] = mPredator;
}

Bird::~Bird() {}
