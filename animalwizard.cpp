#include "animalwizard.h"
#include "ui_animalwizard.h"

AnimalWizard::AnimalWizard(QList <QString> animalsNames,QWidget *parent) :
    QWizard(parent),
    ui(new Ui::AnimalWizard)
{
    ui->setupUi(this);

    introPage = new IntroPage;
    birdMiddlePage = new MiddlePage(BIRD_PAGE);
    mammalMiddlePage = new MiddlePage(MAMMAL_PAGE);
    snakeMiddlePage = new MiddlePage(SNAKE_PAGE);
    birdInfoPage = new InfoPage(BIRDINFO_PAGE,animalsNames);
    mammalInfoPage = new InfoPage(MAMMALINFO_PAGE, animalsNames);
    snakeInfoPage = new InfoPage(SNAKEINFO_PAGE, animalsNames);
    finalPage = new FinalPage;

    setPage(INTRO_PAGE, introPage);
    setPage(BIRD_PAGE, birdMiddlePage);
    setPage(MAMMAL_PAGE, mammalMiddlePage);
    setPage(SNAKE_PAGE, snakeMiddlePage);
    setPage(BIRDINFO_PAGE, birdInfoPage);
    setPage(MAMMALINFO_PAGE, mammalInfoPage);
    setPage(SNAKEINFO_PAGE, snakeInfoPage);
    setPage(FINAL_PAGE, finalPage);
    setStartId(INTRO_PAGE);

}

int AnimalWizard::getPath()const
{
    if(hasVisitedPage(BIRD_PAGE))
        return BIRD_PAGE;
    if(hasVisitedPage(MAMMAL_PAGE))
        return MAMMAL_PAGE;
    return SNAKE_PAGE;
}

QString AnimalWizard::getAnimalName()const{return animalName;}

int AnimalWizard::getAnimalYears()const{return animalYears;}

int AnimalWizard::getAnimalMonths()const{return animalMonths;}

double AnimalWizard::getAnimalWeight()const{return animalWeight;}

int AnimalWizard::getAnimalPercent()const{return animalPercent;}

QString AnimalWizard::getAnimalSpecies()const{return animalSpecies;}

double AnimalWizard::getAnimalLengthOfWings()const{return animalLengthOfWings;}

bool AnimalWizard::getAnimalPredator()const{ return animalPredator;}

int AnimalWizard::getAnimalMilkPeriod()const{return animalMilkPeriod;}

double AnimalWizard::getAnimalLength()const{return animalLength;}

bool AnimalWizard::getAnimalPoisonous()const{ return animalPoisonous;}

void AnimalWizard::setAnimalInfo(InfoPage* iPage, MiddlePage* mPage){
    animalName = iPage->nameLineEdit->text();
    animalYears = iPage->yearsLineEdit->text().toInt();
    animalMonths = iPage->monthsLineEdit->text().toInt();
    animalWeight = iPage->weightLineEdit->text().toDouble();
    animalPercent = iPage->percentOfFeedingLineEdit->text().toInt();
    animalSpecies = mPage->animalSpecies;
}

void AnimalWizard::accept()
{
    switch(getPath())
    {
    case BIRD_PAGE:
    {
        setAnimalInfo(birdInfoPage,birdMiddlePage);
        animalLengthOfWings = birdInfoPage->lengthOfWingsLineEdit->text().toDouble();
        animalPredator = birdInfoPage->predatorButton->isChecked();
        break;
    }
    case MAMMAL_PAGE:
    {
        setAnimalInfo(mammalInfoPage,mammalMiddlePage);
        animalMilkPeriod = mammalInfoPage->milkPeriodLineEdit->text().toInt();
        animalPredator = mammalInfoPage->predatorButton->isChecked() ;
        break;
    }
    case SNAKE_PAGE:
    {
        setAnimalInfo(snakeInfoPage,snakeMiddlePage);
        animalLength = snakeInfoPage->lengthLineEdit->text().toDouble();
        animalPoisonous = snakeInfoPage->poisonousButton->isChecked();
        break;
    }
    }

    QDialog::accept();
}

AnimalWizard::~AnimalWizard()
{
    delete ui;
}

