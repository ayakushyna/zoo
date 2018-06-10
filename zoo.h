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
#include <memory>
class Zoo
{
public:
    Zoo();
    Zoo(const QString& zooName);
    ~Zoo();

    static bool checkZooName(const QString& zooName);
    void setZooName(const QString& zooName);
    QString getZooName()const;
    QStringList getAnimalsNames() const;
    QStringList getSpecificNames(AnimalType type) const;
    void addAnimal( std::shared_ptr<Animal> animal);
    void removeAnimal( const QString& name);

    std::shared_ptr<Animal> getAnimal(const QString& name) const;
    int feeding(const Food& food);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QString mZooName;
    QVector<std::shared_ptr<Animal>> mAnimals;
};

#endif // ZOO_H
