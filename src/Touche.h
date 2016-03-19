#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>
#include "note.h"

class Touche : public QPushButton
{
public:
        Touche(bool estNoire);

private:
        //Note note; // le son qu'on doit jouer quand on clique sur la touche

};

#endif // TOUCHE_H
