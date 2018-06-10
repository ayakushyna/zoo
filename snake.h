#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"
#include "shared_defs.h"

class Snake:public Animal
{
public:
    Snake();
    Snake(const QString& name, int years, int months, double weight,
          int percentOfFeeding, const QString& species, double length, bool poisonous);
    ~Snake();

    void setLength(double length);
    double getLength() const;
    void setPoisonous(bool poisonous);
    bool getPoisonous() const;

    static bool checkLength(double length);

    bool feed(const Food& food);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    double mLength;
    bool mPoisonous;
};

#endif // SNAKE_H
