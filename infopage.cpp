#include "infopage.h"

InfoPage::InfoPage( int path,const QList <QString>& animalsNames,QWidget* parent)
: QWizardPage( parent ), path( path ), mAnimalsNames(animalsNames) {

    setCommitPage(true);
    setTitle("Animal Info");
    setSubTitle("Input information of a new animal, please." );

    QGridLayout *layout = new QGridLayout;

    QLabel *nameLabel = new QLabel("Name: ");
    nameErrorLabel = new QLabel;
    nameErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
    nameLineEdit = new QLineEdit;

    QLabel *yearsLabel = new QLabel("Years: ");
    yearsErrorLabel = new QLabel;
    yearsErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
    yearsLineEdit = new QLineEdit;

    QLabel *monthsLabel = new QLabel("Months: ");
    monthsErrorLabel = new QLabel;
    monthsErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
    monthsLineEdit = new QLineEdit;

    QLabel *weightLabel = new QLabel("Weight, kilos: ");
    weightErrorLabel = new QLabel;
    weightErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
    weightLineEdit = new QLineEdit;

    QLabel *percentOfFeedingLabel = new QLabel("Percent of feeding, %: ");
    percentOfFeedingErrorLabel = new QLabel;
    percentOfFeedingErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
    percentOfFeedingLineEdit = new QLineEdit;

    layout->setHorizontalSpacing(30);
    layout->setVerticalSpacing(10);

    layout->addWidget(nameLabel,0,0);
    layout->addWidget(nameLineEdit,0,1,1,2);
    layout->addWidget(nameErrorLabel,1,1);

    layout->addWidget(yearsLabel,2,0);
    layout->addWidget(yearsLineEdit,2,1);
    layout->addWidget(yearsErrorLabel,3,1);

    layout->addWidget(monthsLabel,2,2);
    layout->addWidget(monthsLineEdit,2,3);
    layout->addWidget(monthsErrorLabel,3,3);

    layout->addWidget(weightLabel,2,4);
    layout->addWidget(weightLineEdit,2,5);
    layout->addWidget(weightErrorLabel,3,5);

    layout->addWidget(percentOfFeedingLabel,2,6);
    layout->addWidget(percentOfFeedingLineEdit,2,7);
    layout->addWidget(percentOfFeedingErrorLabel,3,7);


    switch(path)
    {
    case BIRDINFO_PAGE:
    {

        QLabel *lengthOfWingsLabel = new QLabel("Length of wings, meters: ");
        lengthOfWingsErrorLabel = new QLabel;
        lengthOfWingsErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
        lengthOfWingsLineEdit = new QLineEdit;

        QLabel *predatorLabel = new QLabel("Predator?");
        predatorButton = new QCheckBox;

        layout->addWidget(lengthOfWingsLabel,4,0);
        layout->addWidget(lengthOfWingsLineEdit,4,1);
        layout->addWidget(lengthOfWingsErrorLabel,5,1);

        layout->addWidget(predatorLabel,4,2);
        layout->addWidget(predatorButton,4,3);

        break;
    }

    case MAMMALINFO_PAGE:
    {
        QLabel *milkPeriodLabel = new QLabel("Milk period, months: ");
        milkPeriodErrorLabel = new QLabel;
        milkPeriodErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
        milkPeriodLineEdit = new QLineEdit;

        QLabel *predatorLabel = new QLabel("Predator?");
        predatorButton = new QCheckBox;

        layout->addWidget(milkPeriodLabel,4,0);
        layout->addWidget(milkPeriodLineEdit,4,1);
        layout->addWidget(milkPeriodErrorLabel,5,1);registerField( "animalMilkPeriod*", milkPeriodLineEdit );

        layout->addWidget(predatorLabel,4,2);
        layout->addWidget(predatorButton,4,3);

        break;
    }

    case SNAKEINFO_PAGE:
    {

        QLabel *lengthLabel = new QLabel("Length, meters: ");
        lengthErrorLabel = new QLabel;
        lengthErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
        lengthLineEdit = new QLineEdit;

        QLabel *poisonousLabel = new QLabel("Poisonous?");
        poisonousButton = new QCheckBox;

        layout->addWidget(lengthLabel,4,0);
        layout->addWidget(lengthLineEdit,4,1);
        layout->addWidget(lengthErrorLabel,5,1);

        layout->addWidget(poisonousLabel,4,2);
        layout->addWidget(poisonousButton,4,3);

        break;
    }
    }

    setLayout(layout);
}

InfoPage::~InfoPage(){}

bool InfoPage::checkName(const QString& name){
     QRegExp rxpName( "[A-Z][a-z]{1,14}" );
     return rxpName.exactMatch(name)&&!mAnimalsNames.contains(name);
}

bool InfoPage::checkYears(int years){
    return years >= 0 && years < 100;
}

bool InfoPage::checkMonths(int months){
    return months >= 0 && months < 12;
}

bool InfoPage::checkWeight(double weight){
    return weight > 0 && weight<= 5000;
}

bool InfoPage::checkPercentOfFeeding(int percentOfFeeding){
    return percentOfFeeding > 0 && percentOfFeeding <= 100;
}

bool InfoPage::checkLengthOfWings(double lengthOfWings){
    return lengthOfWings > 0 && lengthOfWings <=3;
}

bool InfoPage::checkMilkPeriod(int milkPeriod){
    return milkPeriod > 0 && milkPeriod <= 6;
}

bool InfoPage::checkLength(double length){
    return length > 0 && length <= 12;
}

bool InfoPage::validatePage(){

    bool b1 = checkName(nameLineEdit->text());
    nameErrorLabel->setText(b1? "" : "Invalid name.");
    nameLineEdit->setFocus();

    bool b2 = checkYears(yearsLineEdit->text().toInt());
    yearsErrorLabel->setText(b2? "" : "Invalid years.");
    yearsLineEdit->setFocus();

    bool b3 = checkMonths(monthsLineEdit->text().toInt());
    monthsErrorLabel->setText(b3? "" : "Invalid months.");
    monthsLineEdit->setFocus();

    bool b4 = checkWeight(weightLineEdit->text().toDouble());
    weightErrorLabel->setText(b4? "" : "Invalid weight.");
    weightLineEdit->setFocus();

    bool b5 = checkPercentOfFeeding(percentOfFeedingLineEdit->text().toInt());
    percentOfFeedingErrorLabel->setText(b5? "" : "Invalid percent.");
    percentOfFeedingLineEdit->setFocus();

    bool b6;

    switch(path)
    {
    case BIRDINFO_PAGE:
    {
        b6 = checkLengthOfWings(lengthOfWingsLineEdit->text().toDouble());
        lengthOfWingsErrorLabel->setText(b6? "" : "Invalid length of wings.");
        lengthOfWingsLineEdit->setFocus();
        break;
    }

    case MAMMALINFO_PAGE:
    {
        b6 = checkMilkPeriod(milkPeriodLineEdit->text().toInt());
        milkPeriodErrorLabel->setText(b6? "" : "Invalid milk period.");
        milkPeriodLineEdit->setFocus();
        break;
    }

    case SNAKEINFO_PAGE:
    {
        b6 = checkLength(lengthLineEdit->text().toDouble());
        lengthErrorLabel->setText(b6? "" : "Invalid length.");
        lengthLineEdit->setFocus();
        break;
    }
    }

    return b1 && b2 && b3 && b4 && b5 && b6;

}

int InfoPage::nextId() const {
        return FINAL_PAGE;
}
