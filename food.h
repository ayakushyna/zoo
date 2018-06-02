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
    Food(AnimalType type, const QString& name, int percentIncrease);
    ~Food();

    AnimalType getFoodAnimalType()const;
    QString getFoodName()const;
    int getFoodPercentIncrease()const;

private:
    AnimalType mType;
    QString mName;
    int mPercentIncrease;
};

#endif // FOOD_H
