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

QStringList Zoo::getAnimalsNames() const{
    QStringList list;
    foreach(Animal* animal,mAnimals)
    {
        list << animal->getName();
    }
    return list;
}

QStringList Zoo::getSpecificNames(AnimalType type) const{
    QStringList list;
    foreach(Animal* animal,mAnimals)
    {
         if((animal->getType() == type))
             list << animal->getName();
    }
    return list;
}


int Zoo::feeding(const Food& food){
    Animal* hungryAnimal = nullptr;

    std::sort(mAnimals.begin(),mAnimals.end(),
         [](Animal* left, Animal* right){
        return left->getPercentOfFeeding() < right->getPercentOfFeeding();
    });

    foreach(Animal* animal,mAnimals)
    {
        if((animal->getType() == food.getFoodAnimalType()))
        {
            hungryAnimal = animal;
            if(hungryAnimal->feed(food)) return FED;
        }
    }

    if(hungryAnimal == nullptr)
        return NOANIMAL;

    return UNFED;
}

void Zoo::addAnimal( Animal* animal){
    mAnimals.push_back(animal);
}

void Zoo::removeAnimal( const QString& name ){
    for(auto i = mAnimals.begin(); i != mAnimals.end();i++){
        if((*i)->getName() == name ){
            mAnimals.remove(i-mAnimals.begin());
            break;
        }
    }
}

Animal* Zoo::getAnimal(const QString& name) const{
    foreach(Animal* animal,mAnimals)
    {
        if(animal->getName() == name)
            return animal;
    }
    return nullptr;
}

Zoo::~Zoo(){
    qDeleteAll(mAnimals);
}
