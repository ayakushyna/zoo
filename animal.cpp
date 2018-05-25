#include "animal.h"

Animal::Animal(): mName(), mAge(0), mWeight(0),  mPercentOfFeeding(0), mSpecies(){}

Animal::Animal(const QString& name, int age, double weight, int percentOfFeeding,const QString& species)
  : mName(name), mAge(age), mWeight(weight), mPercentOfFeeding(percentOfFeeding), mSpecies(species){}

bool Animal::feed(const QString& foodType, double foodWeight){}

void Animal::moveToAnotherZoo(){}

void Animal::setName(const QString& name){
    mName = name;
}

QString Animal::getName() const{return mName;}

void Animal::setWeight(double weight){
    mWeight = weight;
}

double Animal::getWeight() const {return mWeight;}

void Animal::setAge(int age){
    mAge = age;
}

int Animal::getAge()const {return mAge;}

void Animal::setPercentOfFeeding(int percentOfFeeding){
    mPercentOfFeeding=percentOfFeeding;
}

int Animal::getPercentOfFeeding()const {return mPercentOfFeeding;}

void Animal::declinePercentOfFeeding(){
    --mPercentOfFeeding;
}

void Animal::setSpecies(const QString& species){
    mSpecies = species;
}

QString Animal::getSpecies() const{return mSpecies;}

Animal::~Animal() {}
