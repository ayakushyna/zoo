#ifndef INTROPAGE_H
#define INTROPAGE_H
#include <QWizardPage>
#include <QtWidgets>
#include "shared_defs.h"
class QRadioButton;
class QBoxLayout;


class IntroPage: public QWizardPage {
    Q_OBJECT

public:
    IntroPage( QWidget* parent = 0 );
    ~IntroPage();

protected:
    int nextId() const;

private:
    QRadioButton* birdButton;
    QRadioButton* mammalButton;
    QRadioButton* snakeButton;

};

#endif // INTROPAGE_H
