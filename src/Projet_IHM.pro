#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:16:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_IHM
TEMPLATE = app


SOURCES += main.cpp\
        notezbien.cpp \
    Touche.cpp \
    Clavier.cpp

HEADERS  += notezbien.h \
    Touche.h \
    Clavier.h

FORMS    += notezbien.ui \
    piano.ui
