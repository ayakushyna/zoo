#ifndef ZOO_H
#define ZOO_H
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include <QString>
#include <QList>
#include <QVector>
#include <iterator>
#include "shared_defs.h"
#include <QtAlgorithms>

class Zoo
{
public:
    Zoo();
    Zoo(const QString& zooName);

    bool checkZooName(const QString& zooName);
    void setZooName(const QString& zooName);
    QString getZooName()const;
    QStringList getAnimalsNames() const;
    QStringList getSpecificNames(AnimalType type) const;
    void addAnimal( Animal* animal);
    void removeAnimal( const QString& name);
    Animal* getAnimal(const QString& name) const;
    int feeding(const Food& food);

private:
    QString mZooName;
    QVector<Animal*> mAnimals;
};

#endif // ZOO_H
