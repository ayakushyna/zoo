#include "middlepage.h"

MiddlePage::MiddlePage( int path, QWidget* parent )
    : QWizardPage( parent ),path( path ) {

        switch (path) {
        case BIRD_PAGE:
        {
            setTitle("Bird");
            setSubTitle("Choose a new bird, please." );
            QHBoxLayout* layout = new QHBoxLayout;

            animalButtons = new QButtonGroup;
            layout->addWidget(createAnimalGroupBox("flamingo",animalButtons,1));
            layout->addWidget(createAnimalGroupBox("parrot",animalButtons,2));
            layout->addWidget(createAnimalGroupBox("peacock",animalButtons,3));
            layout->addWidget(createAnimalGroupBox("penguin",animalButtons,4));

            setLayout(layout);
            break;
        }
        case MAMMAL_PAGE:
        {
            setTitle("Mammal");
            setSubTitle("Choose a new mammal, please." );
            QHBoxLayout* layout = new QHBoxLayout;

            animalButtons = new QButtonGroup;
            layout->addWidget(createAnimalGroupBox("elephant",animalButtons,1));
            layout->addWidget(createAnimalGroupBox("giraffe",animalButtons,2));
            layout->addWidget(createAnimalGroupBox("lion",animalButtons,3));
            layout->addWidget(createAnimalGroupBox("monkey",animalButtons,4));

            setLayout(layout);
            break;
        }
        case SNAKE_PAGE:
        {
            setTitle("Snake");
            setSubTitle("Choose a new snake, please." );
            QHBoxLayout* layout = new QHBoxLayout;

            animalButtons = new QButtonGroup;
            layout->addWidget(createAnimalGroupBox("anaconda",animalButtons,1));
            layout->addWidget(createAnimalGroupBox("cobra",animalButtons,2));

            setLayout(layout);
            break;
        }
        }

}

 QGroupBox* MiddlePage::createAnimalGroupBox(const QString&  animal,QButtonGroup* buttonGroup,int id)
{
    QGroupBox* animalBox = new QGroupBox;
    QVBoxLayout* sublayout = new QVBoxLayout;
    QRadioButton* animalButton = new QRadioButton;
    animalButton->setIcon(QIcon(":/images/" + animal + ".png"));
    animalButton->setIconSize(QSize(140,140));
    buttonGroup->addButton(animalButton);
    buttonGroup->setId(animalButton,id);
    connect(animalButton,SIGNAL(clicked(bool)),SLOT(setAnimalSpecies()));

    QLabel* animalLbl = new QLabel(animal);
    animalLbl->setAlignment(Qt::AlignCenter);

    sublayout->addWidget(animalLbl);
    sublayout->addWidget(animalButton);

    sublayout->setAlignment(Qt::AlignCenter);
    animalBox->setLayout(sublayout);
    return animalBox;
}

 void MiddlePage::setAnimalSpecies(){
     if(path == BIRD_PAGE) {
         switch(animalButtons->checkedId())
         {
         case 1:
         {
             animalSpecies = "flamingo";
             break;
         }
         case 2:
         {
             animalSpecies = "parrot";
             break;
         }
         case 3:
         {
             animalSpecies = "peacock";
             break;
         }
         case 4:
         {
             animalSpecies = "penguin";
             break;
         }
         }
     }
     if(path == MAMMAL_PAGE) {
         switch(animalButtons->checkedId())
         {
         case 1:
         {
             animalSpecies = "elephant";
             break;
         }
         case 2:
         {
             animalSpecies = "giraffe";
             break;
         }
         case 3:
         {
             animalSpecies = "lion";
             break;
         }
         case 4:
         {
             animalSpecies = "monkey";
             break;
         }
         }
     }
     if(path == SNAKE_PAGE){
         switch(animalButtons->checkedId())
         {
         case 1:
         {
             animalSpecies = "anaconda";
             break;
         }
         case 2:
         {
             animalSpecies = "cobra";
             break;
         }
         }
      }

 }

QString MiddlePage::getAnimalSpecies()const{return animalSpecies; }

bool MiddlePage::validatePage(){
    return (animalButtons->checkedId()!= -1);
}

int MiddlePage::nextId() const {
       if(path == BIRD_PAGE) return BIRDINFO_PAGE;
       if(path == MAMMAL_PAGE) return MAMMALINFO_PAGE;
       return SNAKEINFO_PAGE;
}

MiddlePage::~MiddlePage(){}
