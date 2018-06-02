#ifndef FEEDDIALOG_H
#define FEEDDIALOG_H

#include "shared_defs.h"
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include "food.h"
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

    Food getSelectedFood() const;

private:
    static const QVector<Food> mFoods ;

    Food mFood;

    QButtonGroup* animalButtons;
    QComboBox* listOfFood;
};

#endif // FEEDDIALOG_H
