#include "note.h"

Note::Note(Hauteur h, int octave) {
    this->octave = octave;
    this->hauteur = h;
    // TODO lire son
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
    // TODO lire son
}

