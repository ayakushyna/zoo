#ifndef FOOD_H
#define FOOD_H

#include "shared_defs.h"
#include <QtWidgets>
#include <QMap>
#include <QString>

class Food
{
public:
    Food();
    Food(AnimalType, const QString&, int);
    Food(AnimalType, const QString&, int, bool);
    ~Food();

    AnimalType getFoodAnimalType()const;
    QString getFoodName()const;
    int getFoodPercentIncrease()const;
    bool getPredatorFood()const;

private:
    AnimalType mType;
    QString mName;
    int mPercentIncrease;
    bool mPredator;
};

#endif // FOOD_H
