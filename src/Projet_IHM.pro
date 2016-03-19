#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:16:35
#
#-------------------------------------------------

QT += core gui \
        xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_IHM
TEMPLATE = app


SOURCES += main.cpp\
        notezbien.cpp \
    Touche.cpp \
    Clavier.cpp \
    note.cpp \
    qportee.cpp \
    pageaccueil.cpp

HEADERS  += notezbien.h \
    Touche.h \
    Clavier.h \
    note.h \
    qportee.h \
    pageaccueil.h

FORMS    += notezbien.ui \
    piano.ui

DISTFILES += \
    ../ressources/partition_1.xml
