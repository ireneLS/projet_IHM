#include "qpagepartition.h"

#include<iostream>
using namespace std;

QPagePartition::QPagePartition(QWidget *parent) : QWidget(parent)
{
    porteeActuelle = 0;
    noteActuelle = 0;

    // Indique le layout
    layout = new QVBoxLayout();
    this->setLayout(layout);
}

void QPagePartition::updatePortees(QString nomPartition){
    if(nomPartition!=0) {
        // On recupere la partition contenu dans le fichier XML
        cheminPartition = QString("../ressources/partitions/");
        cheminPartition.append(nomPartition);
        cheminPartition.append(".xml");
    }

    this->lirePartition(cheminPartition.toStdString());

    // Remise à zéro
    portees = vector<QPortee*>();
    porteeActuelle = 0;
    noteActuelle = 0;
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != 0) {
        item->widget()->deleteLater();
        delete item;
    }

    // Creation et affichage des portées
    QPortee * currentPortee = new QPortee();
    for(unsigned int i = 0 ; i < partition.size() ; i++) {
        currentPortee->addNote(partition[i]);

        // Si la portee est trop large, on fait une nouvelle portee
        if(currentPortee->minimumWidth() >= this->width() - 39) {
            portees.push_back(currentPortee);
            layout->addWidget(currentPortee);
            currentPortee = new QPortee(this);
            currentPortee->setAfficherCurseur(false);
        }
    }
    portees.push_back(currentPortee);
    layout->addWidget(currentPortee);

    // LOGS
    // Utilise la date d'aujourd'hui en tant que nom de fichier log
    QDate today =QDate::currentDate();
    QString fichier = QString("../logs/");
    fichier.append(QString::number(today.day()));
    fichier.append("-");
    fichier.append(QString::number(today.month()));
    fichier.append("-");
    fichier.append(QString::number(today.year()));
    fichier.append("logs.txt");

    QFile file(fichier);
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append)) {
        // Création d'un flux servant à écrire les logs
        QTextStream flux(&file);
        flux.setCodec("UTF-8");

        // Ecriture des logs
        QTime now = QTime::currentTime();
        flux << "[" << now.hour() << "h" << now.minute() << "m" << now.second() << "s]"
             << "Mise a jour des portees affichees sur la page partition" << endl;
    }
    file.close();
}

vector<Note> QPagePartition::recupPartition() {
    vector<Note> result = vector<Note>();
    for(unsigned int i = 0 ; i < portees.size(); i++) {
        for(unsigned int j = 0 ; j < portees[i]->notes.size(); j++) {
            result.push_back(portees[i]->notes[j]);
        }
    }
    return result;
}

void QPagePartition::checkNote(Note n) {
    if(this->isVisible()) {
        bool porteeFini = portees[porteeActuelle]->checkNote(n);
        ++noteActuelle;
        if(porteeFini) {
            ++porteeActuelle;
            if(porteeActuelle >= portees.size()) {
                emit fini(this->recupPartition());
            } else {
                portees[porteeActuelle]->setAfficherCurseur(true);
            }
        }
    }

    // LOGS
    // Utilise la date d'aujourd'hui en tant que nom de fichier log
    QDate today =QDate::currentDate();
    QString fichier = QString("../logs/");
    fichier.append(QString::number(today.day()));
    fichier.append("-");
    fichier.append(QString::number(today.month()));
    fichier.append("-");
    fichier.append(QString::number(today.year()));
    fichier.append("logs.txt");

    QFile file(fichier);
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append)) {
        // Création d'un flux servant à écrire les logs
        QTextStream flux(&file);
        flux.setCodec("UTF-8");

        // Ecriture des logs
        QTime now = QTime::currentTime();
        flux << "[" << now.hour() << "h" << now.minute() << "m" << now.second() << "s]"
             << "Appui du clavier sur la touche : Hauteur "
             << n.hauteur << " Octave " << n.octave << endl;
    }
    file.close();
}

vector<Note> QPagePartition::lirePartition(const string cheminPartition) {

    partition = vector<Note>();

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
        Note n = Note(elNote.attribute("hauteur").toStdString(),elNote.attribute("octave").toInt());
        partition.push_back(n);
        note = note.nextSibling();
    }

    return partition;
}

void QPagePartition::resizeEvent(QResizeEvent *event) {


}
