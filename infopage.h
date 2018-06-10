#ifndef INFOPAGE_H
#define INFOPAGE_H

#include <QWizardPage>
#include "shared_defs.h"
#include "zoo.h"
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include <QWizard>
#include <QtWidgets>
#include <QRegExp>
#include <QString>
#include <QList>

class AnimalWizard;

class InfoPage:public QWizardPage {
    Q_OBJECT

public:
    InfoPage(int path,const QStringList& animalsNames, QWidget* parent = 0 );
    ~InfoPage();

    friend  class AnimalWizard;
protected:
    int nextId() const;
    bool validatePage();

private:
    int path;
    QStringList mAnimalsNames;

    QLineEdit *nameLineEdit;
    QLabel *nameErrorLabel;

    QLineEdit *yearsLineEdit;
    QLabel *yearsErrorLabel;

    QLineEdit *monthsLineEdit;
    QLabel *monthsErrorLabel;

    QLineEdit *weightLineEdit;
    QLabel *weightErrorLabel;

    QLineEdit *percentOfFeedingLineEdit;
    QLabel *percentOfFeedingErrorLabel;

    QLineEdit *lengthOfWingsLineEdit;
    QLabel *lengthOfWingsErrorLabel;

    QCheckBox *predatorButton;

    QLineEdit *milkPeriodLineEdit;
    QLabel *milkPeriodErrorLabel;

    QLineEdit *lengthLineEdit;
    QLabel *lengthErrorLabel;

    QCheckBox *poisonousButton;
};

#endif // INFOPAGE_H
