#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <QtWidgets>
#include "shared_defs.h"
#include "food.h"


class InvalidData: public std::exception{

public:
    InvalidData(void){}
    virtual const char* what() const throw(){
        return "Invalid Data";
    }
    ~InvalidData(){}
};

class Animal
{

public:
    Animal();
    Animal(const QString& name, int years, int months, double weight, int percentOfFeeding,const QString& species);
    virtual ~Animal();

    void setName(const QString& name);
    QString getName() const;
    void setType(AnimalType type);
    AnimalType getType() const;
    void setYears(int years);
    int getYears() const;
    void setMonths(int months);
    int getMonths() const;
    void setWeight(double weight);
    double getWeight() const;
    void setPercentOfFeeding(int percentOfFeeding);
    int getPercentOfFeeding() const;
    void setSpecies(const QString& species);
    QString getSpecies() const;

    QTimer* getFeedingTimer() const;
    QTimer* getAgeTimer() const;

    static bool checkName(const QString& name);
    static bool checkYears(int years);
    static bool checkMonths(int months);
    static bool checkWeight(double weight);
    static bool checkPercentOfFeeding(int percentOfFeeding);

    void increaseAge();
    void decreasePercentOfFeeding();

    void moveToAnotherZoo();

    virtual bool feed(const Food& food) = 0;

    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;

protected:
    QString mName;
    AnimalType mType;
    int mYears, mMonths;
    double mWeight;
    int mPercentOfFeeding;
    QString mSpecies;

    QTimer* feedingTimer;
    QTimer* ageTimer;
};

#endif // ANIMAL_H
