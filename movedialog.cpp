#include "movedialog.h"

MoveDialog::MoveDialog(QStringList list,QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Move Animal");
    QGridLayout* layout = new QGridLayout;

    QLabel* selectedZooLabel = new QLabel("Select new zoo:");

    QComboBox* listOfZoos = new QComboBox;
    listOfZoos->addItems(list);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                      |QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    connect(listOfZoos, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            [=](const QString &text){ mSelectedZooName = text; });

    layout->addWidget(selectedZooLabel);
    layout->addWidget(listOfZoos);
    layout->addWidget(buttonBox);

    setLayout(layout);
    setWindowIcon(QIcon(":/images/zoo_icon.png"));

}

QString MoveDialog::getSelectedZooName()const{return mSelectedZooName;}

MoveDialog::~MoveDialog() {}
