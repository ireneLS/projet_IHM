#include "notezbien.h"
#include "ui_notezbien.h"
#include <iostream>
#include "qportee.h"
#include <QBoxLayout>
#include <QtXml>
#include <QFile>
#include <QMessageBox>

using namespace std;

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
vector<Note> NotezBien::lirePartition(const string cheminPartition) {

    vector<Note> partition = vector<Note>();

    QDomDocument *dom = new QDomDocument();
    QFile xml_doc(QString::fromStdString(cheminPartition));// initialisation du fichier

    // TODO : peut etre gerer les erreurs autrement si un utilisateur lambda tombe dessus ben c'est pas très comprehensible.
    if(!xml_doc.open(QIODevice::ReadOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return partition;
    }
    if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
            xml_doc.close();
            QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
            return partition;
    }
    xml_doc.close(); // on ferme le document XML : on n'en a plus besoin, tout est compris dans l'objet DOM.

    QDomElement dom_element = dom->documentElement();// pour parcourir le document.
    QDomNode note = dom_element.firstChild();

    while(!note.isNull()){// tant qu'on a des notes dans la partition
        QDomElement elNote = note.toElement();
        partition.push_back(Note(elNote.attribute("hauteur").toStdString(),elNote.attribute("octave").toInt()));
        note = note.nextSibling();
    }

    return partition;
}
