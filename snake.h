#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"
#include "shared_defs.h"

class Snake:public Animal
{
public:
    Snake();
    Snake(const QString&, int, int, double,
          int, const QString&, double, bool);
    ~Snake();

    double getLength() const;
    bool getPoisonous() const;

    static bool checkLength(double);

    bool feed(const Food&);

    void read(const QJsonObject&);
    void write(QJsonObject&) const;

private:
    double mLength;
    bool mPoisonous;
};

#endif // SNAKE_H
