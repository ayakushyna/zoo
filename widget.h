#ifndef WIDGET_H
#define WIDGET_H

#include "shared_defs.h"
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include "animalinfo.h"
#include "animalwizard.h"
#include "feeddialog.h"
#include <QtWidgets>

namespace Ui {class Widget;}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void changeZooNameSlot();
    void feedingSlot();
    void addAnimalSlot();

private:
    Ui::Widget *ui;

    Zoo* zoo;
    FeedDialog* feedDialog;
    AnimalWizard* wizard;

    void createButtonsGroupBox();
    void createTabsOfAnimals();
    void createAnimalGroupBox(Animaltype type);

    QGroupBox* buttonsGroupBox;

    QTabWidget* tabsOfAnimals;

    QGroupBox* birdsGroupBox;
    QComboBox* listOfBirds;
    AnimalInfo* birdInfo;

    QGroupBox* mammalsGroupBox;
    QComboBox* listOfMammals;
    AnimalInfo* mammalInfo;

    QGroupBox* snakesGroupBox;
    QComboBox* listOfSnakes;
    AnimalInfo* snakeInfo;
};

#endif // WIDGET_H
