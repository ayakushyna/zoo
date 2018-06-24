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
    Animal(const QString&, int, int, double, int,const QString&);
    virtual ~Animal();

    QString getName() const;
    void setName(const QString&);

    AnimalType getType() const;
    int getYears() const;
    int getMonths() const;
    double getWeight() const;
    int getPercentOfFeeding() const;
    QString getSpecies() const;

    QTimer* getFeedingTimer() const;
    QTimer* getAgeTimer() const;

    static bool checkName(const QString&);
    static bool checkYears(int);
    static bool checkMonths(int);
    static bool checkWeight(double);
    static bool checkPercentOfFeeding(int);

    void increaseAge();
    void decreasePercentOfFeeding();

    virtual bool feed(const Food&) = 0;

    virtual void read(const QJsonObject&);
    virtual void write(QJsonObject&) const;

protected:
    QString mName;
    AnimalType mType;
    int mYears, mMonths;
    double mWeight;
    int mPercentOfFeeding;
    QString mSpecies;

    QTimer* mFeedingTimer;
    QTimer* mAgeTimer;
};

#endif // ANIMAL_H
