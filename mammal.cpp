#include "mammal.h"

Mammal::Mammal(): Animal(), mMilkPeriod(0), mPredator(0) {}

Mammal::Mammal(const QString& name, int years, int months, double weight,
               int percentOfFeeding, const QString& species, int milkPeriod, bool predator)
    :Animal( name, years, months, weight, percentOfFeeding, species),
        mMilkPeriod(milkPeriod), mPredator(predator){

    //if(checkMilkPeriod(milkPeriod) == 0)
    //    throw InvalidData();

    mType = MAMMAL;
}


void Mammal::setMilkPeriod(int milkPeriod){
    mMilkPeriod = milkPeriod;
}

int Mammal::getMilkPeriod()const { return mMilkPeriod; }

void Mammal::setPredator(bool predator){
    mPredator = predator;
}

bool Mammal::getPredator() const { return mPredator;}

bool Mammal::checkMilkPeriod(int milkPeriod){
    return milkPeriod > 0 && milkPeriod <= 6;
}

bool Mammal::feed(const Food& food){
    if(( mYears == 0 && mMonths <= mMilkPeriod && food.getFoodName() != "Milk") ||
      (( mYears > 0 || (mYears == 0 && mMonths >  mMilkPeriod) ) && food.getFoodName() == "Milk"))
        return false;

    if(mPredator && ( mYears > 0 || (mYears == 0 && mMonths >  mMilkPeriod)) && !food.getPredatorFood())
        return false;

    if(!mPredator && food.getPredatorFood())
        return false;

    feedingTimer->stop();
    if(mPercentOfFeeding+food.getFoodPercentIncrease() > 100){
        mPercentOfFeeding = 100;
    }
    else mPercentOfFeeding+=food.getFoodPercentIncrease();
    feedingTimer->start(3000);
    return true;
}


void Mammal::read(const QJsonObject &json){
    Animal::read(json);

    if (json.contains("milkPeriod") && json["milkPeriod"].isDouble()&& checkMilkPeriod(json["milkPeriod"].toInt()))
            mMilkPeriod = json["milkPeriod"].toInt();
    else throw InvalidData();

    if (json.contains("predator") && json["predator"].isBool())
            mPredator = json["predator"].toBool();
    else throw InvalidData();
}

void Mammal::write(QJsonObject &json) const {
    Animal::write(json);
    json["milkPeriod"] = mMilkPeriod;
    json["predator"] = mPredator;
}

Mammal::~Mammal() {}
