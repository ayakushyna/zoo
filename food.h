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
    Food(AnimalType type, const QString& name, int percentIncrease, bool predator);
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
