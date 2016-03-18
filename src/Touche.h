#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>

class Touche : public QPushButton
{
public:
        Touche(bool estNoire);

private:
        QString son; // le son qu'on doit jouer quand on clique sur la touche

};

#endif // TOUCHE_H
