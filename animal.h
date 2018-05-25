#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <QtWidgets>
class Animal
{

public:
    Animal();
    Animal(const QString& name, int age,double weight, int percentOfFeeding,const QString& species);
    virtual ~Animal();

    void setName(const QString& name);
    QString getName() const;
    void setWeight(double weight);
    double getWeight() const;
    void setAge(int age);
    int getAge() const;
    void setPercentOfFeeding(int percentOfFeeding);
    int getPercentOfFeeding() const;
    void setSpecies(const QString& species);
    QString getSpecies() const;

    void declinePercentOfFeeding();
    virtual bool feed(const QString& foodType, double foodWeight) = 0;
    void moveToAnotherZoo();

protected:
    QString mName;
    int mAge;
    double mWeight;
    int mPercentOfFeeding;
    QString mSpecies;
};

#endif // ANIMAL_H
