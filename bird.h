#ifndef BIRD_H
#define BIRD_H

#include "animal.h"
#include "shared_defs.h"
class Bird: public Animal
{
public:
    Bird();
    Bird(const QString& name, int years, int months, double weight,
         int percentOfFeeding, const QString& species,double lengthOfWings,bool predator);
    ~Bird();

    void setLengthOfWings(double lengthOfWings);
    double getLengthOfWings()const;
    void setPredator(bool predator);
    bool getPredator()const;

    static bool checkLengthOfWings(double lengthOfWings);

    bool feed(const Food& food);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    double mLengthOfWings;
    bool mPredator;
};

#endif // BIRD_H
