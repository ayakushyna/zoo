#include "zoo.h"

Zoo::Zoo() : mZooName("Zoo"),mAnimals(){}

bool Zoo::checkZooName(const QString& zooName){
    QRegExp rxpName( "[A-Z][a-z]{1,14}" );
    return rxpName.exactMatch(zooName);
}

void Zoo::setZooName(const QString&  zooName){
    mZooName = zooName;
}

QString Zoo::getZooName()const{ return mZooName; }

QList<QString> Zoo::getAnimalsNames() const{
    return mAnimals.uniqueKeys();
}

int Zoo::feeding(Animaltype type,const QString&  foodType,int percentIncrease){
    int minPercent = 101;
    Animal* hungryAnimal = nullptr;
    for(auto i = mAnimals.begin(); i != mAnimals.end();i++)
    {
        if((i.value()->getType() == type) && (i.value()->getPercentOfFeeding() < minPercent)){
            minPercent = i.value()->getPercentOfFeeding();
            hungryAnimal = i.value();
        }
    }

    if(hungryAnimal != nullptr)
        return hungryAnimal->feed(foodType, percentIncrease);

    return -1;
}

void Zoo::addAnimal( Animal* animal){
    mAnimals.insert(animal->getName(),animal);
}


Animal* Zoo::getAnimal(const QString& name) const{
    return *(mAnimals.find(name));
}
