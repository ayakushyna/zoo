#ifndef INFOPAGE_H
#define INFOPAGE_H

#include <QWizardPage>
#include "shared_defs.h"
#include "animalwizard.h"
#include "zoo.h"
#include <QWizard>
#include <QtWidgets>
#include <QRegExp>
#include <QString>
#include <QList>

    class AnimalWizard;

class InfoPage:public QWizardPage {
    Q_OBJECT

public:
    InfoPage(int path,const QList <QString>& animalsNames, QWidget* parent = 0 );
    ~InfoPage();

    friend  class AnimalWizard;
protected:
    int nextId() const;
    bool validatePage();

private:
    int path;
    QList <QString> mAnimalsNames;

    bool checkName(const QString& name);
    QLineEdit *nameLineEdit;
    QLabel *nameErrorLabel;

    bool checkAge(int age);
    QLineEdit *ageLineEdit;
    QLabel *ageErrorLabel;

    bool checkWeight(double weight);
    QLineEdit *weightLineEdit;
    QLabel *weightErrorLabel;

    bool checkPercentOfFeeding(int percentOfFeeding);
    QLineEdit *percentOfFeedingLineEdit;
    QLabel *percentOfFeedingErrorLabel;

    bool checkLengthOfWings(double lengthOfWings);
    QLineEdit *lengthOfWingsLineEdit;
    QLabel *lengthOfWingsErrorLabel;

    QCheckBox *predatorButton;

    bool checkMilkPeriod(int milkPeriod);
    QLineEdit *milkPeriodLineEdit;
    QLabel *milkPeriodErrorLabel;

    bool checkLength(double length);
    QLineEdit *lengthLineEdit;
    QLabel *lengthErrorLabel;

    QCheckBox *poisonousButton;
};

#endif // INFOPAGE_H
