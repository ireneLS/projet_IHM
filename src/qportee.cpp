#include "qportee.h"

QPortee::QPortee(QWidget *parent) : QWidget(parent) {
    notes = vector<Note>();
    this->setMinimumHeight(100);
    this->setMinimumWidth(40);
}

void QPortee::addNote(Note n) {
    notes.push_back(n);
    this->setMinimumWidth(this->minimumWidth()+ QPortee::largeurNote);
}

int QPortee::noteToHauteur(Note n) {
    int hauteursNote[7] = {-15,-10,-5,0,5,10,15};
    int hauteurNote = hauteursNote[n.hauteur];
    if(hauteurNote<15) {
        hauteurNote += 31;
    }
    return hauteurNote;
}

void QPortee::paintEvent(QPaintEvent * event) {
    QPainter painter(this);

    //Dessin des portées
    int hauteursPortees[5] = {30,40,50,60,70};
    QVector<QPoint> portees = QVector<QPoint>(10);
    for(int h = 0 ; h < 5 ; h++) {
        portees+=QPoint(0,hauteursPortees[h]);
        portees+=QPoint(width(),hauteursPortees[h]);
    }
    painter.drawLines(portees);

    //Dessin de la clef
    QPixmap pixmapClef = QPixmap("../ressources/clefSol.png");
    painter.drawPixmap(0,13,35,79,pixmapClef);

    //Dessin des notes
    QPixmap pixmapNote = QPixmap("../ressources/noire.png");
    for(unsigned int i = 0 ; i < notes.size() ; i++) {
        // Pour les notes haute (si et +), on retourne la note
        if(notes[i].hauteur == SI || notes[i].octave > 1) {
            QTransform transform;
            transform.rotate(180);
            pixmapNote = pixmapNote.transformed(transform);
        }
        painter.drawPixmap(40 + i * QPortee::largeurNote,noteToHauteur(notes[i]),30,50,pixmapNote);
    }
}
