#ifndef TOUCHE_H
#define TOUCHE_H
#include "note.h"
#include <QPushButton>


class Touche : public QPushButton
{
public:
        Touche(Note noteX, bool estNoire);

public slots:
        void jouerTouche();

private:
        Note * noteAJouer; // le son qu'on doit jouer quand on clique sur la touche

};

#endif // TOUCHE_H
