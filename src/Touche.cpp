#include "Touche.h"

Touche::Touche(Note * note, bool estNoire, QWidget * parent) : QPushButton(parent) {
    this->noteJouee = note;
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    if (estNoire){
        this->setStyleSheet("QPushButton { background-color: black;outline:none;border-radius: 1px;}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
    else{
        this->setStyleSheet("QPushButton { background-color: white;outline:none}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
    connect(this,SIGNAL(pressed()),
            this,SLOT(jouee()));
}

void Touche::jouee(){
    noteJouee->son->play();
    emit jouee(*noteJouee);
}


