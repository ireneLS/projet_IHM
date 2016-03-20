#include "qportee.h"

QPortee::QPortee(QWidget *parent) : QWidget(parent) {
    notes = vector<Note>();
    noteActuelle = 0;
    this->setMinimumHeight(100);
    this->setMinimumWidth(40);
}

void QPortee::addNote(Note n) {
    notes.push_back(n);
    this->setMinimumWidth(this->minimumWidth()+ QPortee::largeurNote);
}

int QPortee::nbNotes() {
    return notes.size();
}

int QPortee::noteToHauteur(Note n) {
    int hauteursNote[7];
    if(n.octave == 1) {
        hauteursNote = {-15,-10,-5,0,5,10,15};
    } else {
        hauteursNote = {-15,-10,-5,0,5,10,15};
    }
    return hauteursNote[n.hauteur];
}

bool QPortee::checkNote(Note n) {
    notes[noteActuelle].check(n);
    ++noteActuelle;
    this->update();
    return noteActuelle >= notes.size();
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
    QPixmap pixmapClef = QPixmap(":/img/notes/ressources/images/clefSol.png");
    painter.drawPixmap(0,13,35,79,pixmapClef);

    //Dessin des notes
    for(unsigned int i = 0 ; i < notes.size() ; i++) {
        QPixmap pixmapNote = *notes[i].img;
        painter.drawPixmap(40 + i * QPortee::largeurNote, noteToHauteur(notes[i]),
                           30, 50, pixmapNote);
    }

    //Dessin du curseur
    if(noteActuelle < notes.size()) {
        QPoint bas = QPoint(55 + noteActuelle * QPortee::largeurNote, 0);
        QPoint haut = QPoint(55 + noteActuelle * QPortee::largeurNote, 100);
        painter.setPen(Qt::blue);
        painter.drawLine(bas,haut);
    }
}
