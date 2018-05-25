#ifndef FINALPAGE_H
#define FINALPAGE_H
#include <QWizardPage>
#include "shared_defs.h"
#include "animalwizard.h"
#include <QWizard>
#include <QtWidgets>
class QVBoxLayout;
class FinalPage:public QWizardPage {
    Q_OBJECT

public:
    FinalPage( QWidget* parent = 0 );

    ~FinalPage();

};

#endif // FINALPAGE_H
