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

    QVector<QPoint> portees = QVector<QPoint>(10);
    portees+=QPoint(0,10);
    portees+=QPoint(width(),10);
    portees+=QPoint(0,20);
    portees+=QPoint(width(),20);
    portees+=QPoint(0,30);
    portees+=QPoint(width(),30);
    portees+=QPoint(0,40);
    portees+=QPoint(width(),40);
    portees+=QPoint(0,50);
    portees+=QPoint(width(),50);

    painter.drawLines(portees);

    QPixmap pixmap_note = QPixmap("/comptes/E115761C/Documents/projets/projet_IHM/noire.png");
    QTransform transform;
    transform.rotate(45);
    pixmap_note = pixmap_note.transformed(transform);
    painter.drawPixmap(70,70,70,70,pixmap_note);
}
