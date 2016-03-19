#include "notezbien.h"
#include "ui_notezbien.h"
#include <iostream>
#include "qportee.h"
#include <QBoxLayout>
#include <QtXml>
#include <QFile>
#include <QMessageBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include "pageaccueil.h"

using namespace std;

NotezBien::NotezBien(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotezBien)
{
    // Initialisation
    this->setMinimumSize(908,255);
    QVBoxLayout * mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);

    // Creer les différentes pages à afficher
    pageAccueil = new PageAccueil();
    connect(pageAccueil->boutonJouer, SIGNAL( pressed()), this, SLOT(afficherPagePartition()));

    pagePartition = creerPartition();
    // pageResultats = creerResultats();

    // Gestionnaire des pages
    stack = new QStackedWidget(this);
    stack->addWidget(pageAccueil);
    stack->addWidget(pagePartition);
    mainLayout->addWidget(stack);

}

NotezBien::~NotezBien()
{
    delete ui;
}

void NotezBien::afficherPageAccueil() {
    stack->setCurrentIndex(0);
}

void NotezBien::afficherPagePartition() {
    stack->setCurrentIndex(1);
}

void NotezBien::afficherPageResultat() {
    stack->setCurrentIndex(2);
}

QWidget * NotezBien::creerPartition() {
    // Init
    QWidget * widgetPartition = new QWidget();
    QLayout * layoutPartition = new QVBoxLayout();
    widgetPartition->setLayout(layoutPartition);

    vector<Note> partition = this->lirePartition("../ressources/partition_1.xml");
    QPortee * q = new QPortee(this);
    for(unsigned int i = 0 ; i < partition.size() ; i++) {
        q->addNote(partition[i]);
    }
    layoutPartition->addWidget(q);

    return widgetPartition;
}

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
