#ifndef ANIMALWIZARD_H
#define ANIMALWIZARD_H

#include "intropage.h"
#include "middlepage.h"
#include "infopage.h"
#include "finalpage.h"
#include <QtWidgets>
#include "shared_defs.h"


namespace Ui {class AnimalWizard;}

class AnimalWizard : public QWizard
{
    Q_OBJECT

public:
    explicit AnimalWizard(QList <QString> animalsNames, QWidget *parent = 0);
    void accept();
    ~AnimalWizard();

    int getPath()const;
    QString getAnimalName()const;
    int getAnimalYears()const;
    int getAnimalMonths()const;
    double getAnimalWeight()const;
    int getAnimalPercent()const;
    QString getAnimalSpecies()const;
    double getAnimalLengthOfWings()const;
    bool getAnimalPredator()const;
    int getAnimalMilkPeriod()const;
    double getAnimalLength()const;
    bool getAnimalPoisonous()const;

private:
    Ui::AnimalWizard *ui;

    void setAnimalInfo(InfoPage* iPage, MiddlePage* mPage);

    IntroPage* introPage;
    MiddlePage* birdMiddlePage;
    MiddlePage* mammalMiddlePage;
    MiddlePage* snakeMiddlePage;
    InfoPage* birdInfoPage;
    InfoPage* mammalInfoPage;
    InfoPage* snakeInfoPage;
    FinalPage* finalPage;

    QString animalName;
    int animalYears, animalMonths;
    double animalWeight;
    int animalPercent;
    QString animalSpecies;

    double animalLengthOfWings;
    bool animalPredator;

    int animalMilkPeriod;

    double animalLength;
    bool animalPoisonous;
};

#endif // ANIMALWIZARD_H
