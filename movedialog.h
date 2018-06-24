#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include "shared_defs.h"
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include <QtWidgets>
#include <QMap>
#include <QString>

class MoveDialog: public QDialog
{
     Q_OBJECT
public:
    MoveDialog(QStringList list, QString currZooName, QWidget* parent = 0);
    ~MoveDialog();

    QString getSelectedZooName()const;

private:
    QString mSelectedZooName;
};

#endif // MOVEDIALOG_H
