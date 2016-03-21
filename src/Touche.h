/**
 * \file Touche.h
 * \brief Définition d'une classe touche héritant de QPushButton représentant une touche de clavier
 * \author Léo Cassiau, Irène Le Squer
 * \version 0.1
 */

#ifndef TOUCHE_H
#define TOUCHE_H

#include <QPushButton>

#include "note.h"

class Touche : public QPushButton
{
    Q_OBJECT
public:
        /**
        * @brief Constructeur de touche
        * @param parent Widget père de la touche
        * @param note la note correspondant à la touche du clavier
        * @param estNoire bool indiquant si la touche est une touche noire
        */
        Touche(Note * note, bool estNoire, QWidget * parent = 0);

signals:
        /**
         * @brief jouee signal emis après l'activation d'une touche et l'emission du son
         * @param n la note qui a été jouée
         */
        void jouee(Note n);

public slots:
        /**
         * @brief jouee l'évenèment déclenché par l'appui d'une touche sur le clavier
         */
        void jouee();

private:
        /**
         * @brief noteJouee la note a jouer quand on clique sur la touche
         */
        Note * noteJouee;

};

#endif // TOUCHE_H
