#include "middlepage.h"

const QMap<QString,Animaltype> MiddlePage::species = {{ "flamingo",BIRD }, { "parrot",BIRD }, {"peacock", BIRD }, { "penguin",BIRD },
                                                      { "elephant",MAMMAL }, { "giraffe",MAMMAL },{ "lion",MAMMAL }, { "monkey",MAMMAL },
                                                      { "anaconda",SNAKE }, { "cobra",SNAKE }};

MiddlePage::MiddlePage( int path, QWidget* parent )
    : QWizardPage( parent ),path( path ) {

        switch (path) {
        case BIRD_PAGE:
        {
            setTitle("Bird");
            setSubTitle("Choose a new bird, please." );
            QHBoxLayout* layout = new QHBoxLayout;

            animalButtons = new QButtonGroup;
            int id = 0;

            for( auto i =  species.begin(); i != species.end(); i++)
            {
                if(i.value() == BIRD)
                {
                    layout->addWidget(createAnimalGroupBox(i.key(),animalButtons, id));
                }
                id++;
            }

            setLayout(layout);
            break;
        }
        case MAMMAL_PAGE:
        {
            setTitle("Mammal");
            setSubTitle("Choose a new mammal, please." );
            QHBoxLayout* layout = new QHBoxLayout;

            animalButtons = new QButtonGroup;
            int id = 0;

            for( auto i =  species.begin(); i != species.end(); i++)
            {
                if(i.value() == MAMMAL)
                {
                    layout->addWidget(createAnimalGroupBox(i.key(),animalButtons, id));
                }
                id++;
            }

            setLayout(layout);
            break;
        }
        case SNAKE_PAGE:
        {
            setTitle("Snake");
            setSubTitle("Choose a new snake, please." );
            QHBoxLayout* layout = new QHBoxLayout;

            animalButtons = new QButtonGroup;
            int id = 0;

            for( auto i =  species.begin(); i != species.end(); i++)
            {
                if(i.value() == SNAKE)
                {
                    layout->addWidget(createAnimalGroupBox(i.key(),animalButtons, id));
                }
                id++;
            }

            setLayout(layout);
            break;
        }
        }

}

 QGroupBox* MiddlePage::createAnimalGroupBox(const QString&  animal,QButtonGroup* buttonGroup, int id)
{
    QGroupBox* animalBox = new QGroupBox;
    QVBoxLayout* sublayout = new QVBoxLayout;

    QRadioButton* animalButton = new QRadioButton;
    animalButton->setIcon(QIcon(":/images/" + animal + ".png"));
    animalButton->setIconSize(QSize(140,140));
    buttonGroup->addButton(animalButton, id);
    connect(animalButton,SIGNAL(clicked()),SLOT(setAnimalSpecies()));

    QLabel* animalLbl = new QLabel(animal);
    animalLbl->setAlignment(Qt::AlignCenter);

    sublayout->addWidget(animalLbl);
    sublayout->addWidget(animalButton);

    sublayout->setAlignment(Qt::AlignCenter);
    animalBox->setLayout(sublayout);
    return animalBox;
}

 void MiddlePage::setAnimalSpecies(){
     auto it = species.begin() + animalButtons->checkedId();
     animalSpecies = it.key();
 }

QString MiddlePage::getAnimalSpecies()const{ return animalSpecies; }

bool MiddlePage::validatePage(){
    return (animalButtons->checkedId()!= -1);
}

int MiddlePage::nextId() const {
       if(path == BIRD_PAGE) return BIRDINFO_PAGE;
       if(path == MAMMAL_PAGE) return MAMMALINFO_PAGE;
       return SNAKEINFO_PAGE;
}

MiddlePage::~MiddlePage(){}
