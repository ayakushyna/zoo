#ifndef MIDDLEPAGE_H
#define MIDDLEPAGE_H
#include "shared_defs.h"
#include "animalwizard.h"
#include <QWizardPage>
#include <QWizard>
#include <QVector>
#include <QString>
#include <QtWidgets>

class MiddlePage: public QWizardPage {
    Q_OBJECT

public:
    MiddlePage( int path,QWidget* parent = 0 );
    ~MiddlePage();
    friend  class AnimalWizard;

    QString getAnimalSpecies()const;

private slots:
     void setAnimalSpecies();

protected:
    int nextId() const;
    bool validatePage();

private:
    static const QMap <QString,Animaltype> species ;
    QGroupBox* createAnimalGroupBox(const QString& animal,QButtonGroup* buttonGroup, int id);

    int path;
    QString animalSpecies;
    QButtonGroup* animalButtons;


};

#endif // MIDDLEPAGE_H
