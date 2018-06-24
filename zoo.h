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
    Zoo(const QString&);
    ~Zoo();

    static bool checkZooName(const QString&);
    void setZooName(const QString&);
    QString getZooName()const;
    QStringList getAnimalsNames() const;
    QStringList getSpecificNames(AnimalType) const;
    void addAnimal( std::shared_ptr<Animal>);
    void removeAnimal( const QString&);

    std::shared_ptr<Animal> getAnimal(const QString&) const;
    Message feeding(const Food&);

    void read(const QJsonObject&);
    void write(QJsonObject&) const;

private:
    QString mZooName;
    QVector<std::shared_ptr<Animal>> mAnimals;
};

#endif // ZOO_H
