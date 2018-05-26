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

AnimalWizard::~AnimalWizard()
{
    delete ui;
}

void AnimalWizard::accept()
{
    switch(getPath())
    {
    case BIRD_PAGE:
    {
        animalName = birdInfoPage->nameLineEdit->text();
        animalYears = birdInfoPage->yearsLineEdit->text().toInt();
        animalMonths = birdInfoPage->monthsLineEdit->text().toInt();
        animalWeight = birdInfoPage->weightLineEdit->text().toDouble();
        animalPercent = birdInfoPage->percentOfFeedingLineEdit->text().toInt();
        animalSpecies = birdMiddlePage->animalSpecies;

        animalLengthOfWings = birdInfoPage->lengthOfWingsLineEdit->text().toDouble();
        animalPredator = birdInfoPage->predatorButton->isChecked() ;
        break;
    }
    case MAMMAL_PAGE:
    {
        animalName = mammalInfoPage->nameLineEdit->text();
        animalYears = mammalInfoPage->yearsLineEdit->text().toInt();
        animalMonths = mammalInfoPage->monthsLineEdit->text().toInt();
        animalWeight = mammalInfoPage->weightLineEdit->text().toDouble();
        animalPercent = mammalInfoPage->percentOfFeedingLineEdit->text().toInt();
        animalSpecies = mammalMiddlePage->animalSpecies;

        animalMilkPeriod = mammalInfoPage->milkPeriodLineEdit->text().toInt();
        break;
    }
    case SNAKE_PAGE:
    {
        animalName = snakeInfoPage->nameLineEdit->text();
        animalYears = snakeInfoPage->yearsLineEdit->text().toInt();
        animalMonths = snakeInfoPage->monthsLineEdit->text().toInt();
        animalWeight = snakeInfoPage->weightLineEdit->text().toDouble();
        animalPercent = snakeInfoPage->percentOfFeedingLineEdit->text().toInt();
        animalSpecies = snakeMiddlePage->animalSpecies;

        animalLength = snakeInfoPage->lengthLineEdit->text().toDouble();
        animalPoisonous = snakeInfoPage->poisonousButton->isChecked();
        break;
    }
    }

    QDialog::accept();
}


