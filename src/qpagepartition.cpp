#include "qpagepartition.h"

#include<iostream>
using namespace std;

QPagePartition::QPagePartition(QWidget *parent) : QWidget(parent)
{
    // Indique le layout
    layout = new QVBoxLayout();
    this->setLayout(layout);
}

void QPagePartition::updatePortees(QString nomPartition){
    // On recupere la partition contenu dans le fichier XML
    QString cheminPartition = QString("../ressources/partitions/");
    cheminPartition.append(nomPartition);
    cheminPartition.append(".xml");
    vector<Note> partition = this->lirePartition(cheminPartition.toStdString());

    // Creation et affichage des portées
    QPortee * currentPortee = new QPortee(this);
    for(unsigned int i = 0 ; i < partition.size() ; i++) {
        currentPortee->addNote(partition[i]);
        //cout << partition[i].img->height() << endl;

        // Si la portee est trop large, on fait une nouvelle portee
        if(currentPortee->width() == this->width()) {
            portees.push_back(currentPortee);
            layout->addWidget(currentPortee);
            currentPortee = new QPortee(this);
        }
    }
    portees.push_back(currentPortee);
    layout->addWidget(currentPortee);

    //On remet à zero la note position de la note courante
    //currentNote = partition[0];
}

void QPagePartition::nextNote() {
    //currentNote = ;
}

vector<Note> QPagePartition::lirePartition(const string cheminPartition) {

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
