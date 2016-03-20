#ifndef TOUCHE_H
#define TOUCHE_H

#include <QPushButton>

#include "note.h"

class Touche : public QPushButton
{
    Q_OBJECT
public:
        Touche(Note * note, bool estNoire, QWidget * parent = nullptr);

signals:
        void jouee(Note n);

public slots:
        void jouee();

private:
        Note * noteJouee; // la note jouée quand on clique sur la touche

};

#endif // TOUCHE_H
