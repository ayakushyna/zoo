#include "animal.h"

Animal::Animal(): mName(),mType(UNKNOWN), mYears(0), mMonths(0), mWeight(0),  mPercentOfFeeding(0), mSpecies(){}

Animal::Animal(const QString& name,AnimalType type, int years, int months,
               double weight, int percentOfFeeding,const QString& species)
  : mName(name), mType(type), mYears(years), mMonths(months),
    mWeight(weight), mPercentOfFeeding(percentOfFeeding), mSpecies(species){}

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

void Animal::increaseAge(){
    if(++mMonths > 11){
        mMonths = 0;
        ++mYears;
    }
}

void Animal::decreasePercentOfFeeding(){
    --mPercentOfFeeding;
}

Animal::~Animal() {}
