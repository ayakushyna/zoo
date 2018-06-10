#include "animal.h"

Animal::Animal(): mName(),mType(UNKNOWN), mYears(0), mMonths(0), mWeight(0),  mPercentOfFeeding(0), mSpecies(){
    feedingTimer = new QTimer;
    ageTimer = new QTimer;
}

Animal::Animal(const QString& name, int years, int months,
               double weight, int percentOfFeeding,const QString& species)
  : mName(name), mType(UNKNOWN), mYears(years), mMonths(months),
    mWeight(weight), mPercentOfFeeding(percentOfFeeding), mSpecies(species){

    feedingTimer = new QTimer;
    ageTimer = new QTimer;
}

void Animal::moveToAnotherZoo(){}

void Animal::setName(const QString& name){
    mName = name;
}

QString Animal::getName() const{return mName;}

void Animal::setType(AnimalType type){
    mType = type;
}

AnimalType Animal::getType() const{return mType;}

void Animal::setYears(int years){
    mYears = years;
}

int Animal::getYears()const {return mYears;}

void Animal::setMonths(int months){
    mMonths = months;
}

int Animal::getMonths()const {return mMonths;}

void Animal::setWeight(double weight){
    mWeight = weight;
}

double Animal::getWeight() const {return mWeight;}

void Animal::setPercentOfFeeding(int percentOfFeeding){
    mPercentOfFeeding=percentOfFeeding;
}

int Animal::getPercentOfFeeding()const {return mPercentOfFeeding;}

void Animal::setSpecies(const QString& species){
    mSpecies = species;
}

QString Animal::getSpecies() const{return mSpecies;}

QTimer* Animal::getFeedingTimer() const{return feedingTimer;}

QTimer* Animal::getAgeTimer() const{return ageTimer;}

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
    return percentOfFeeding > 0 && percentOfFeeding <= 100;
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
    if (json.contains("name") && json["name"].isString())
            mName = json["name"].toString();

    if (json.contains("type") && json["type"].isDouble())
            mType = AnimalType(json["type"].toInt());

    if (json.contains("years") && json["years"].isDouble())
            mYears = json["years"].toInt();

    if (json.contains("months") && json["months"].isDouble())
            mMonths = json["months"].toInt();

    if (json.contains("weight") && json["weight"].isDouble())
            mWeight = json["weight"].toDouble();

    if (json.contains("percent") && json["percent"].isDouble())
            mPercentOfFeeding = json["percent"].toInt();

    if (json.contains("species") && json["species"].isString())
            mSpecies = json["species"].toString();

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
    delete feedingTimer;
    delete ageTimer;
}
