#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T17:48:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zoozee
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    animal.cpp \
    bird.cpp \
    snake.cpp \
    mammal.cpp \
    zoo.cpp \
    animalwizard.cpp \
    intropage.cpp \
    middlepage.cpp \
    finalpage.cpp \
    infopage.cpp \
    animalinfo.cpp \
    feeddialog.cpp \
    movedialog.cpp


HEADERS += \
        widget.h \
    animal.h \
    bird.h \
    snake.h \
    mammal.h \
    zoo.h \
    animalwizard.h \
    intropage.h \
    middlepage.h \
    finalpage.h \
    shared_defs.h \
    infopage.h \
    animalinfo.h \
    feeddialog.h \
    movedialog.h

FORMS += \
        widget.ui \
    animalwizard.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
