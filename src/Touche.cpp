#include "Touche.h"

#include<iostream>
using namespace std;

Touche::Touche(Note * noteX, bool estNoire, QWidget * parent) : QPushButton(parent) {
    noteAJouer = noteX;
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    if (estNoire){
        this->setStyleSheet("QPushButton { background-color: black;outline:none;border-radius: 1px;}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
    else{
        this->setStyleSheet("QPushButton { background-color: white;outline:none}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
    QObject::connect(this, SIGNAL(clicked(bool)), this, SLOT(jouerTouche()));

}


void Touche::jouerTouche(){
    cout << "clique" << endl;
    string t = noteAJouer->son->fileName().toStdString();
    cout <<  t << endl;
    noteAJouer->son->play();
}


