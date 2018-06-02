#ifndef FEEDDIALOG_H
#define FEEDDIALOG_H

#include "shared_defs.h"
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include "animalinfo.h"
#include "animalwizard.h"
#include <QtWidgets>
#include <QMap>
#include <QString>

class FeedDialog: public QDialog
{
    Q_OBJECT
public:
    FeedDialog(QWidget* parent = 0);
    ~FeedDialog();
    void accept();

    Animaltype getAnimalType() const;
    QString getFoodType() const;
    int getPercentIncrease() const;

private:
    static const QMap<QString,int> mFood ;

    Animaltype mAnimalType;
    QString mFoodType;
    int mPercentIncrease;

    QButtonGroup* animalButtons;
    QComboBox* listOfFoodTypes;
};

#endif // FEEDDIALOG_H
