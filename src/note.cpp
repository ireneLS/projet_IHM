#include "note.h"
#include<iostream>

using namespace std;

Note::Note(Hauteur h, int octave) {
    this->octave = octave;
    this->hauteur = h;

    if(hauteur == DO){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (1).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (13).wav"));
        }
    }
    else if(hauteur == RE){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (3).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (15).wav"));
        }
    }
    else if(hauteur == MI){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (5).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (17).wav"));
        }
    }
    else if(hauteur == FA){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (6).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (18).wav"));
        }
    }
    else if(hauteur == SOL){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (8).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (20).wav"));
        }
    }
    else if(hauteur == LA){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (10).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (22).wav"));
        }
    }
    else if(hauteur == SI){
        if (octave == 1){
            cout << "ok" ;
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (12).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (24).wav"));
        }
    }
}

Note::Note(string h, int octave) {
    if(h == "do") {this->hauteur = DO;}
    else if(h == "re") {this->hauteur = RE;}
    else if(h == "mi") {this->hauteur = MI;}
    else if(h == "fa") {this->hauteur = FA;}
    else if(h == "sol") {this->hauteur = SOL;}
    else if(h == "la") {this->hauteur = LA;}
    else if(h == "si") {this->hauteur = SI;}
    else {this->hauteur = DO;}

    this->octave = octave;

    if(hauteur == DO){
        if (octave == 1){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (1).wav"));
        }
        else if (octave == 2){
            this->son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (13).wav"));
        }
    }
}

