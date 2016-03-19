#ifndef NOTE_H
#define NOTE_H

#include <iostream>

using namespace std;

typedef enum {
    DO, RE, MI, FA, SOL, LA, SI
} Hauteur;

class Note
{
public:
    Note(Hauteur h, int octave);
    Note(string h, int octave);

//private:
    Hauteur hauteur;
    int octave;
    string sonPath;
};

#endif // NOTE_H
