#ifndef WIDGET_H
#define WIDGET_H
#include <memory>
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

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private slots:
    void changeZooSlot(int index);
    void changeZooNameSlot();
    void feedingSlot();
    void addAnimalSlot();
    void removeAnimalSlot();
    void moveAnimalSlot();

    bool loadApp();
    bool saveApp();
    void aboutApp();

private:
    Ui::Widget *ui;

    QVector <std::shared_ptr<Zoo>> mZoos;
    std::shared_ptr<Zoo> mZoo;

    QStringList getZooNames() const;
    QComboBox* listOfZoos;

    void createActions();
    QAction *openAct;
    QAction *saveAct;
    QAction *aboutAct;

    void createMenus();
    QMenu *fileMenu;
    QMenu *helpMenu;

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

    QGroupBox* createAnimalGroupBox(QComboBox* listOfAnimals, AnimalInfo* animalInfo);
    void changeListOfAnimals(std::shared_ptr<Zoo> zoo,QComboBox* listOfAnimals, AnimalType type);
    void changeListOfZoos();

    QTimer* updateTimer;

    QGroupBox* birdsGroupBox;
    QComboBox* listOfBirds;
    AnimalInfo* birdInfo;

    QGroupBox* mammalsGroupBox;
    QComboBox* listOfMammals;
    AnimalInfo* mammalInfo;

    QGroupBox* snakesGroupBox;
    QComboBox* listOfSnakes;
    AnimalInfo* snakeInfo;

    void setTimers(Animal& animal);
    void addAnimal( std::shared_ptr<Animal> animal, QComboBox* listOfAnomals);

    QComboBox* getCurrentListOfAnimals()const;
    //QMessageBox* createNameWarningBox();

    //void setCurrentAnimalName(QComboBox* listOfAnimals);
    //void removeCurrentAnimalName(QComboBox* listOfAnimals);
    //QString currAnimalName;
};

#endif // WIDGET_H
