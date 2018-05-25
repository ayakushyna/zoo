#include "zoo.h"

Zoo::Zoo() : mZooName("Zoo"),mAnimals(){}

bool Zoo::checkZooName(const QString& zooName){
    QRegExp rxpName( "[A-Z][a-z]{1,14}" );
    return rxpName.exactMatch(zooName);
}

void Zoo::setZooName(const QString&  zooName){
    mZooName = zooName;
}

QString Zoo::getZooName()const{return mZooName;}

QList<QString> Zoo::getAnimalsNames() const{
    return mAnimals.uniqueKeys();
}

void Zoo::feeding(Animaltype type,const QString&  foodType, double foodWeight ){}

void Zoo::addAnimal( Animal* animal){

    mAnimals.insert(animal->getName(),animal);
}


Animal* Zoo::getAnimal(const QString& name) const{
    return *(mAnimals.find(name));
}
