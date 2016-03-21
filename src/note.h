/**
 * \file note.h
 * \brief Définition de la classe Note réprésentant une note de musique
 * \author Léo Cassiau, Irène Le Squer
 * \version 0.1
 */

#ifndef NOTE_H
#define NOTE_H

#include <QSound>
#include <QPixmap>

#include <string>

using namespace std;

typedef enum {
    DO, RE, MI, FA, SOL, LA, SI
} Hauteur;

class Note {

public:

    /**
     * @brief Constructeur de Note
     * @param h Hauteur de la note (DO, RE, MI, FA, SOL ,LA, SI)
     * @param octave Octave de la note (1 ou 2)
     */
    Note(Hauteur h, int octave);

    /**
     * @brief Surcharge du constructeur de Note
     * @param hauteur Hauteur de la note (do, re, mi, fa, sol , la, si)
     * @param octave Octave de la note (1 ou 2)
     */
    Note(string hauteur, int octave);

    /**
     * @brief Desctructeur de Note
     */
    ~Note();

    /**
     * @brief Vérifie si n est égale à la note. Si oui, alors la note est notifié réussi, sinon elle est notifié échouée
     * @param n Note à vérifier
     * @return Vrai si n == this, faux sinon
     */
    bool check(Note n);

    /**
     * @brief Hauteur de la note (DO, RE, MI, FA, SOL ,LA, SI)
     */
    Hauteur hauteur;

    /**
     * @brief Octave de la note (1,2)
     */
    int octave;

    /**
     * @brief Son de la note
     */
    QSound * son;

    /**
     * @brief Image répresentant la note. Verte si réussie, rouge sinon
     */
    QPixmap * img;

    /**
     * @brief Indique si la note a été bien jouée ou non
     */
    bool reussi;

private:
    /**
     * @brief Transformation de img retournant la note si elle est égale à SI ou son octave est à 2
     */
    QTransform * retourner;
};

#endif // NOTE_H
