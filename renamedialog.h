#ifndef RENAMEDIALOG_H
#define RENAMEDIALOG_H

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

class RenameDialog: public QDialog
{
    Q_OBJECT
public:
    RenameDialog(Animal* animal,Zoo* zoo,QWidget* parent = 0);
    ~RenameDialog();
private:
    bool checkName(const QString& name,Zoo* zoo);
};

#endif // RENAMEDIALOG_H
