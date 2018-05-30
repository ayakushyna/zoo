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
#include "movedialog.h"
#include <QMap>
#include <QString>
#include <QtWidgets>

namespace Ui {class Widget;}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QStringList getZooNames() const;

private slots:
    void changeZoo(int index);
    void changeZooNameSlot();
    void feedingSlot();
    void addAnimalSlot();
    void moveAnimalSlot();

private:
    Ui::Widget *ui;

    static QVector <Zoo*> mZoos;
    Zoo* mZoo;
    QComboBox* listOfZoo;

    MoveDialog* moveDialog;
    FeedDialog* feedDialog;
    AnimalWizard* wizard;

    QGroupBox* createZooGroupBox();
    QGroupBox* zooGroupBox;

    QGroupBox* createButtonsGroupBox();
    QGroupBox* buttonsGroupBox;

    QTabWidget* createTabsOfAnimals();
    QTabWidget* tabsOfAnimals;

    void createAnimalGroupBox(Animaltype type);

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
