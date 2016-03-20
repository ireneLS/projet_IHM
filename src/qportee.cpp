#include "qportee.h"

#include<iostream>
using namespace std;

QPortee::QPortee(QWidget *parent) : QWidget(parent) {
    notes = vector<Note>();
    noteActuelle = 0;
    this->setMinimumHeight(100);
    this->setMaximumHeight(100);
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

void QPortee::checkNote(Note n) {
    notes[noteActuelle].check(n);
    ++noteActuelle;
    this->paintEvent();
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
        QImage img = *notes[i].img;
        cout << img.height() << endl;
        painter.drawImage(40 + i * QPortee::largeurNote, noteToHauteur(notes[i]), img,0,0,30,50);
    }

    //Dessin du curseur
    QPoint bas = QPoint(55 + noteActuelle * QPortee::largeurNote, 0);
    QPoint haut = QPoint(55 + noteActuelle * QPortee::largeurNote, 100);
    painter.setPen(Qt::blue);
    painter.drawLine(bas,haut);
}
