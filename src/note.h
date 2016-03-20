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
    Note(Hauteur h, int octave);
    Note(string hauteur, int octave);
    ~Note();

    bool check(Note n);

    Hauteur hauteur;
    int octave;
    QSound * son;
    QPixmap * img;
    bool reussi;

private:
    QTransform * retourner;
};

#endif // NOTE_H
