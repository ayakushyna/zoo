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
    foreach(auto animal,mAnimals)
    {
        list << animal->getName();
    }
    return list;
}

QStringList Zoo::getSpecificNames(AnimalType type) const{
    QStringList list;
    foreach(auto animal,mAnimals)
    {
         if((animal->getType() == type))
             list << animal->getName();
    }
    return list;
}


int Zoo::feeding(const Food& food){
    std::shared_ptr<Animal> hungryAnimal (nullptr) ;

    std::sort(mAnimals.begin(),mAnimals.end(),
         [](std::shared_ptr<Animal> left, std::shared_ptr<Animal> right){
        return left->getPercentOfFeeding() < right->getPercentOfFeeding();
    });

    foreach(auto animal,mAnimals)
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

void Zoo::addAnimal( std::shared_ptr<Animal> animal){
    mAnimals.push_back(animal);
     qDebug()<< "After add1" <<  animal.use_count();

}

void Zoo::removeAnimal( const QString& name ){
    for(auto i = mAnimals.begin(); i != mAnimals.end();i++){
        if((*i)->getName() == name ){
            qDebug()<< "Before remove" <<  (*i).use_count();
            mAnimals.remove(i-mAnimals.begin());
            break;
        }
    }
}

std::shared_ptr<Animal> Zoo::getAnimal(const QString& name) const{
    foreach(auto animal,mAnimals)
    {
        if(animal->getName() == name)
            return animal;
    }
    return nullptr;
}

void Zoo::read(const QJsonObject &json){
    if (json.contains("zooName") && json["zooName"].isString())
            mZooName = json["zooName"].toString();

    if (json.contains("animals") && json["animals"].isArray()) {
            QJsonArray animalsArray = json["animals"].toArray();

            /*for(auto i = mAnimals.begin();i!= mAnimals.end();i++){
                if((*i) != nullptr) delete *i;
            }
            */
            mAnimals.clear();
            mAnimals.reserve(animalsArray.size());

            for (int animalIndex = 0; animalIndex < animalsArray.size(); ++animalIndex) {
                QJsonObject animalObject = animalsArray[animalIndex].toObject();

                if(animalObject.contains("type")&& animalObject["type"].isDouble()){
                    std::shared_ptr<Animal> animal (nullptr);

                    switch( animalObject["type"].toInt()){
                    case BIRD:
                    {
                        animal.reset(new Bird);
                        break;
                    }
                    case MAMMAL:
                    {
                        animal.reset(new Mammal);
                        break;
                    }
                    case SNAKE:
                    {
                         animal.reset(new Snake);
                         break;
                    }
                    }

                animal->read(animalObject);
                addAnimal(animal);
                }
            }
        }
}

void Zoo::write(QJsonObject &json) const
{
    json["zooName"] = mZooName;

    QJsonArray animalsArray;
    foreach (auto animal, mAnimals) {
        QJsonObject animalObject;
        animal->write(animalObject);
        animalsArray.append(animalObject);
    }
    json["animals"] = animalsArray;
}

Zoo::~Zoo(){
    /*
    for(auto i = mAnimals.begin();i!= mAnimals.end();i++){
        if((*i) != nullptr) delete *i;
    }
    */
}
