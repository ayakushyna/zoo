#ifndef BIRD_H
#define BIRD_H

#include "animal.h"
#include "shared_defs.h"
class Bird: public Animal
{
public:
    Bird();
    Bird(const QString&, int, int, double,
         int, const QString&,double,bool);
    ~Bird();

    double getLengthOfWings()const;
    bool getPredator()const;

    static bool checkLengthOfWings(double);

    bool feed(const Food&);

    void read(const QJsonObject&);
    void write(QJsonObject&) const;

private:
    double mLengthOfWings;
    bool mPredator;
};

#endif // BIRD_H
