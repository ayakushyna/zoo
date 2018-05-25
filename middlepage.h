#ifndef MIDDLEPAGE_H
#define MIDDLEPAGE_H
#include "shared_defs.h"
#include "animalwizard.h"
#include <QWizardPage>
#include <QWizard>
#include <QtWidgets>
class QVBoxLayout;
class QRadioButton;



class MiddlePage: public QWizardPage {
    Q_OBJECT

public:
    MiddlePage( int path,QWidget* parent = 0 );
    QString getAnimalSpecies()const;
    ~MiddlePage();

    friend  class AnimalWizard;

protected:
    int nextId() const;
    bool validatePage();

private slots:
     void setAnimalSpecies();

private:

    QGroupBox* createAnimalGroupBox(const QString& animal,QButtonGroup* buttonGroup,int id);

    int path;
    QString animalSpecies;
    QButtonGroup* animalButtons;


};

#endif // MIDDLEPAGE_H
