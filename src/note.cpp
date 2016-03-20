#include "note.h"

#include<iostream>
using namespace std;

Note::Note(Hauteur hauteur, int octave) {
    this->octave = octave;
    this->hauteur = hauteur;
    img = new QImage(":/img/notes/ressources/images/noire.png");

    // Pour les notes haute (si et +), on retourne la note
    retourner = new QTransform();
    if(hauteur == SI || octave > 1) {
        retourner->rotate(180);
    }
    QImage imgTransformed = img->transformed(*retourner);
    img = &imgTransformed;

    // Associe au son
    if(hauteur == DO){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (1).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (13).wav"));
        }
    }
    else if(hauteur == RE){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (3).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (15).wav"));
        }
    }
    else if(hauteur == MI){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (5).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (17).wav"));
        }
    }
    else if(hauteur == FA){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (6).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (18).wav"));
        }
    }
    else if(hauteur == SOL){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (8).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (20).wav"));
        }
    }
    else if(hauteur == LA){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (10).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (22).wav"));
        }
    }
    else if(hauteur == SI){
        if (octave == 1){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (12).wav"));
        }
        else if (octave == 2){
            son = new QSound(QString::fromStdString(":/son/piano/ressources/son/piano (24).wav"));
        }
    }

}

Note::Note(string hauteur, int octave) : Note(DO,octave){
    if(hauteur == "re") {this->hauteur = RE;}
    else if(hauteur == "mi") {this->hauteur = MI;}
    else if(hauteur == "fa") {this->hauteur = FA;}
    else if(hauteur == "sol") {this->hauteur = SOL;}
    else if(hauteur == "la") {this->hauteur = LA;}
    else if(hauteur == "si") {this->hauteur = SI;}
}

Note::~Note() {

}

bool Note::check(Note n) {
    if(hauteur == n.hauteur && octave == n.octave) {
        img = new QImage(":/");
        QImage imgTransformed = img->transformed(*retourner);
        img = &imgTransformed;
        return true;
    }
    img = new QImage(":/");
    QImage imgTransformed = img->transformed(*retourner);
    img = &imgTransformed;
    return false;
}

