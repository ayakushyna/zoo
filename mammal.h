#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"
#include "shared_defs.h"
class Mammal:public Animal
{
public:
    Mammal();
    Mammal(const QString&, int, int, double,
           int,const QString&,int, bool);
    ~Mammal();

    int getMilkPeriod()const;
    bool getPredator()const;

    static bool checkMilkPeriod(int);

    bool feed(const Food&);

    void read(const QJsonObject&);
    void write(QJsonObject&) const;

private:
    int mMilkPeriod;
    bool mPredator;
};

#endif // MAMMAL_H
