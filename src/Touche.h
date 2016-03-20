#ifndef TOUCHE_H
#define TOUCHE_H

#include <QPushButton>

#include "note.h"

class Touche : public QPushButton
{
    Q_OBJECT
public:
        Touche(Note * noteX, bool estNoire, QWidget * parent = nullptr);

public slots:
        void jouerTouche();

private:
        Note * noteAJouer; // le son qu'on doit jouer quand on clique sur la touche

};

#endif // TOUCHE_H
