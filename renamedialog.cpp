#include "renamedialog.h"

RenameDialog::RenameDialog(Animal* animal,Zoo* zoo,QWidget *parent)
: QDialog(parent)
{
    setWindowIcon(QIcon(":/images/zoo_icon.png"));
    setWindowTitle("Input name");
    QGridLayout* layout = new QGridLayout;

    QLabel* nameLabel = new QLabel("New name:");
    QLineEdit* nameLineEdit = new QLineEdit;
    QLabel* nameErrorLabel = new QLabel;
    nameErrorLabel->setStyleSheet( "color: red; font-size: 8pt;");
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);

    connect(buttonBox, QDialogButtonBox::accepted,[=](){
        if(checkName(nameLineEdit->text(), zoo)){
            animal->setName(nameLineEdit->text());
            accept();
        } else {
            nameErrorLabel->setText("Invalid name.");
            nameLineEdit->setFocus();
        }
    });

     layout->addWidget(nameLabel);
     layout->addWidget(nameLineEdit);
     layout->addWidget(nameErrorLabel);
     layout->addWidget(buttonBox);

     setLayout(layout);
}

bool RenameDialog::checkName(const QString& name, Zoo* zoo){
    QRegExp rxpName( "[A-Z][a-z]{1,14}" );
    bool b = !(zoo->getAnimalsNames().contains(name));
    return rxpName.exactMatch(name) && b;
}

RenameDialog::~RenameDialog(){}
