#ifndef ZOO_H
#define ZOO_H
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include <QString>
#include <QList>
#include <QMap>
#include <iterator>
#include "shared_defs.h"


class Zoo
{
public:
    Zoo();
    Zoo(const QString& zooName);
    bool checkZooName(const QString& zooName);
    void setZooName(const QString& zooName);
    QString getZooName()const;
    QList<QString> getAnimalsNames() const;
    void addAnimal( Animal* animal);
    Animal* getAnimal(const QString& name) const;
    int feeding(Animaltype type,const QString&  foodType,int percentIncrease);

private:
    QString mZooName;
    QMap<QString,Animal*> mAnimals;
};

#endif // ZOO_H
