#include "notezbien.h"
#include "ui_notezbien.h"
#include <iostream>

NotezBien::NotezBien(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotezBien)
{
    ui->setupUi(this);
}

NotezBien::~NotezBien()
{
    delete ui;
}

void NotezBien::paintEvent(QPaintEvent * event){
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

    //Dessin de la note
    dessineNote(&painter,5);
}

void NotezBien::dessineNote(QPainter* painter, int hauteur) {
    QPixmap pixmapNote = QPixmap("../ressources/noire.png");
    int hauteursNotes[10] = {-15,-10,-5,0,5,10,15,20,25,30};
    int hauteurNote = hauteursNotes[hauteur];
    // Pour les notes haute (si et +), on retourne la note
    if(hauteurNote<15) {
        QTransform transform;
        transform.rotate(180);
        pixmapNote = pixmapNote.transformed(transform);
        hauteurNote += 31;
    }
    painter->drawPixmap(40,hauteurNote,30,50,pixmapNote);
}
