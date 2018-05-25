#ifndef BIRD_H
#define BIRD_H

#include "animal.h"
class Bird: public Animal
{
public:
    Bird();
    Bird(const QString& name,int age, double weight, int percentOfFeeding,
         const QString& species,double lengthOfWings,bool predator);
    void setLengthOfWings(double lengthOfWings0);
    double getLengthOfWings()const;
    void setPredator(bool predator0);
    bool getPredator()const;
    ~Bird();

private:
    double mLengthOfWings;
    bool mPredator;
};

#endif // BIRD_H
