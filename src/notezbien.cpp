#include "notezbien.h"
#include "ui_notezbien.h"
#include <iostream>
#include "qportee.h"
#include <QBoxLayout>
#include <QtXml/QDomDocument>
#include <QFile>

NotezBien::NotezBien(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotezBien)
{
    ui->setupUi(this);
    QBoxLayout * t = new QVBoxLayout();
    this->setLayout(t);
    QPortee * q = new QPortee(this);
    q->addNote(Note(SI,0));
    q->addNote(Note(LA,0));
    t->addWidget(q);
    q = new QPortee(this);
    t->addWidget(q);

}

NotezBien::~NotezBien()
{
    delete ui;
}

//TODO lit une partition et retourne les notes de la partition
vector<Note> NotezBien::lirePartition(const char * cheminPartition) {
    //QFile xml_doc(cheminPartition);

}

