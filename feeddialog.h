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

class FeedDialog: public QDialog
{
    Q_OBJECT
public:
    FeedDialog(QWidget* parent = 0);
    ~FeedDialog();

private:
    Animaltype animalType;
    Foodtype foodType;
};

#endif // FEEDDIALOG_H
