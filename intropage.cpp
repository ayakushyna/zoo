#include "intropage.h"

IntroPage::IntroPage( QWidget* parent )
    : QWizardPage( parent ) {

    setTitle("Animal Type");
    setSubTitle("Choose type of a new animal, please." );
    QVBoxLayout* layout = new QVBoxLayout;

    birdButton = new QRadioButton("Bird");
    mammalButton = new QRadioButton("Mammal");
    snakeButton = new QRadioButton("Snake");

    birdButton->setChecked(true);

    layout->addWidget(birdButton);
    layout->addWidget(mammalButton);
    layout->addWidget(snakeButton);

    setLayout(layout);
}
IntroPage::~IntroPage() {}

int IntroPage::nextId() const {
    if( birdButton->isChecked() ) { return BIRD_PAGE; };
    if( mammalButton->isChecked() ) { return MAMMAL_PAGE; };
    return SNAKE_PAGE;
}
