#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"
#include "shared_defs.h"

class Snake:public Animal
{
public:
    Snake();
    Snake(const QString& name, AnimalType type, int years, int months, double weight,
          int percentOfFeeding, const QString& species, double length, bool poisonous);
    ~Snake();

    void setLength(double length);
    double getLength() const;
    void setPoisonous(bool poisonous);
    bool getPoisonous() const;

    bool feed(const Food& food);

private:
    double mLength;
    bool mPoisonous;
};

#endif // SNAKE_H
