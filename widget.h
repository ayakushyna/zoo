#ifndef WIDGET_H
#define WIDGET_H

#include "shared_defs.h"
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "snake.h"
#include "zoo.h"
#include "animalinfo.h"
#include "snakeinfo.h"
#include "mammalinfo.h"
#include "birdinfo.h"
#include "animalwizard.h"
#include "feeddialog.h"
#include "movedialog.h"
#include "renamedialog.h"
#include <QMap>
#include <QString>
#include <QtWidgets>

namespace Ui {class Widget;}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void changeZooSlot(int index);
    void changeZooNameSlot();
    void feedingSlot();
    void addAnimalSlot();
    void removeAnimalSlot();
    void moveAnimalSlot();

private:
    Ui::Widget *ui;

    static QVector <Zoo*> mZoos;
    Zoo* mZoo;

    QStringList getZooNames() const;
    QComboBox* listOfZoo;

    MoveDialog* moveDialog;
    RenameDialog* renameDialog;
    FeedDialog* feedDialog;
    AnimalWizard* wizard;

    QGroupBox* createZooGroupBox();
    QGroupBox* zooGroupBox;

    QGroupBox* createButtonsGroupBox();
    QGroupBox* buttonsGroupBox;

    QTabWidget* createTabsOfAnimals();
    QTabWidget* tabsOfAnimals;

    template<class T>
    QGroupBox* createAnimalGroupBox(QComboBox* listOfAnimals, T* animalInfo);
    void changeListOfAnimals(QComboBox* listOfAnimals, AnimalType type);
    QGroupBox* birdsGroupBox;
    QComboBox* listOfBirds;
    BirdInfo* birdInfo;

    QGroupBox* mammalsGroupBox;
    QComboBox* listOfMammals;
    MammalInfo* mammalInfo;

    QGroupBox* snakesGroupBox;
    QComboBox* listOfSnakes;
    SnakeInfo* snakeInfo;

    QComboBox* getCurrentListOfAnimals()const;
    QMessageBox* createNameWarningBox();

    void setCurrentAnimalName(QComboBox* listOfAnimals);
    QString currAnimalName;

    void removeCurrentAnimalName(QComboBox* listOfAnimals);
};

#endif // WIDGET_H
