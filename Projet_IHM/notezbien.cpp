#include "notezbien.h"
#include "ui_notezbien.h"

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
}
