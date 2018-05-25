#ifndef BIRD_H
#define BIRD_H

#include "animal.h"
class Bird: public Animal
{
public:
    Bird();
    Bird(const QString& name,int age, double weight, int percentOfFeeding,
         const QString& species,double lengthOfWings,bool predator);
    ~Bird();

    void setLengthOfWings(double lengthOfWings);
    double getLengthOfWings()const;
    void setPredator(bool predator);
    bool getPredator()const;

    bool feed(const QString& foodType, double foodWeight);

private:
    double mLengthOfWings;
    bool mPredator;
};

#endif // BIRD_H
