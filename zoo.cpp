#include "zoo.h"

Zoo::Zoo() : mZooName("Zoo"),mAnimals(){}

Zoo::Zoo(const QString& zooName) : mZooName(zooName),mAnimals(){}

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

QStringList Zoo::getSpecificNames(AnimalType type) const{
    QStringList list;
    for(auto i = mAnimals.begin(); i != mAnimals.end();i++)
    {
         if((i.value()->getType() == type))
             list << i.value()->getName();
    }
    return list;
}


int Zoo::feeding(const Food& food){
    int minPercent = 101;
    Animal* hungryAnimal = nullptr;
    for(auto i = mAnimals.begin(); i != mAnimals.end();i++)
    {
        if((i.value()->getType() == food.getFoodAnimalType()) && (i.value()->getPercentOfFeeding() < minPercent)){
            minPercent = i.value()->getPercentOfFeeding();
            hungryAnimal = i.value();
        }
    }

    if(hungryAnimal != nullptr)
        return hungryAnimal->feed(food);

    return NOANIMAL;
}

void Zoo::addAnimal( Animal* animal){
    mAnimals.insert(animal->getName(),animal);
}

void Zoo::removeAnimal( const QString& name){
    mAnimals.remove(name);
}

Animal* Zoo::getAnimal(const QString& name) const{
    return *(mAnimals.find(name));
}
