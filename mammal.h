#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"
#include "shared_defs.h"
class Mammal:public Animal
{
public:
    Mammal();
    Mammal(const QString& name, int years, int months, double weight,
           int percentOfFeeding,const QString& species,int milkPeriod, bool predator);
    ~Mammal();

    void setMilkPeriod(int milkPeriod);
    int getMilkPeriod()const;
    void setPredator(bool predator);
    bool getPredator()const;

    static bool checkMilkPeriod(int milkPeriod);

    bool feed(const Food& food);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    int mMilkPeriod;
    bool mPredator;
};

#endif // MAMMAL_H
