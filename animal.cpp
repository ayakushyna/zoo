#include "animal.h"

Animal::Animal(): mName(),mType(UNKNOWN), mYears(0), mMonths(0), mWeight(0),  mPercentOfFeeding(0), mSpecies(){
    mFeedingTimer = new QTimer;
    mAgeTimer = new QTimer;
}

Animal::Animal(const QString& name, int years, int months,
               double weight, int percentOfFeeding,const QString& species)
  : mName(name), mType(UNKNOWN), mYears(years), mMonths(months),
    mWeight(weight), mPercentOfFeeding(percentOfFeeding), mSpecies(species){

/*
    if((checkName(name) && checkYears(years) && checkMonths(months)
      && checkWeight(weight) && checkPercentOfFeeding(percentOfFeeding)) == 0)
        throw InvalidData();
*/
    mFeedingTimer = new QTimer;
    mAgeTimer = new QTimer;
}

QString Animal::getName() const{return mName;}

void Animal::setName(const QString& name){
    mName = name;
}

AnimalType Animal::getType() const{return mType;}

int Animal::getYears()const {return mYears;}

int Animal::getMonths()const {return mMonths;}

double Animal::getWeight() const {return mWeight;}

int Animal::getPercentOfFeeding()const {return mPercentOfFeeding;}

QString Animal::getSpecies() const{return mSpecies;}

QTimer* Animal::getFeedingTimer() const{return mFeedingTimer;}

QTimer* Animal::getAgeTimer() const{return mAgeTimer;}

bool Animal::checkName(const QString& name){
     QRegExp rxpName( "[A-Z][a-z]{1,14}" );
     return rxpName.exactMatch(name);
}

bool Animal::checkYears(int years){
    return years >= 0 && years < 100;
}

bool Animal::checkMonths(int months){
    return months >= 0 && months < 12;
}

bool Animal::checkWeight(double weight){
    return weight > 0 && weight<= 5000;
}

bool Animal::checkPercentOfFeeding(int percentOfFeeding){
    return percentOfFeeding >= 0 && percentOfFeeding <= 100;
}

void Animal::increaseAge(){
    if(++mMonths > 11){
        mMonths = 0;
        ++mYears;
    }
}

void Animal::decreasePercentOfFeeding(){
    --mPercentOfFeeding;
}

void Animal::read(const QJsonObject &json){
    if (json.contains("name") && json["name"].isString() && checkName(json["name"].toString()))
            mName = json["name"].toString();
    else throw InvalidData();

    if (json.contains("type") && json["type"].isDouble())
            mType = AnimalType(json["type"].toInt());
    else throw InvalidData();

    if (json.contains("years") && json["years"].isDouble() && checkYears(json["years"].toInt()))
            mYears = json["years"].toInt();
    else throw InvalidData();

    if (json.contains("months") && json["months"].isDouble() && checkMonths(json["months"].toInt()))
            mMonths = json["months"].toInt();
    else throw InvalidData();

    if (json.contains("weight") && json["weight"].isDouble() && checkWeight(json["weight"].toDouble()))
            mWeight = json["weight"].toDouble();
    else throw InvalidData();

    if (json.contains("percent") && json["percent"].isDouble()&& checkPercentOfFeeding(json["percent"].toInt()))
            mPercentOfFeeding = json["percent"].toInt();
    else throw InvalidData();

    if (json.contains("species") && json["species"].isString())
            mSpecies = json["species"].toString();
    else throw InvalidData();

}

void Animal::write(QJsonObject &json) const {
    json["name"] = mName;
    json["type"] = mType;
    json["years"] = mYears;
    json["months"] = mMonths;
    json["weight"] = mWeight;
    json["percent"] = mPercentOfFeeding;
    json["species"] = mSpecies;
}

Animal::~Animal() {
    delete mFeedingTimer;
    delete mAgeTimer;
}
