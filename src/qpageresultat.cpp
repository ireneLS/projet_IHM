#include "qpageresultat.h"

#include <iostream>
using namespace std;

QPageResultat::QPageResultat(QWidget *parent) : QWidget(parent)
{
    // Definition du layout principal
    layout = new QVBoxLayout(this);
    this->setLayout(layout);

    // Affichage de l'appreciation
    layout->addWidget(creerAppreciation());

    // Affiche le score
    layout->addWidget(creerScore());

    // Affiche les différents boutons
    layout->addWidget(creerBoutons());
}

void QPageResultat::setPartition(const vector<Note> & p) {
    partition = p;

    // Définition du texte à afficher
    int nbNotesReussis = 0;
    for(int i = 0 ; i < partition.size() ; i++) {
        if(partition[i].reussi) {
            ++nbNotesReussis;
        }
    }

    QString texte = QString::number(nbNotesReussis);
    texte.append(" sur ");
    texte.append(QString::number(partition.size()));
    texte.append(" notes trouvées !");
    score->setText(texte);
}

QWidget* QPageResultat::creerAppreciation() {
    QWidget * widget = new QWidget();
    QLayout * layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    widget->setLayout(layout);

    QLabel * appreciation = new QLabel("Fini ! ");
    layout->addWidget(appreciation);

    // Definition de la police : Calibri, 18pt
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(18);
    appreciation->setFont(police);

    return widget;
}

QWidget* QPageResultat::creerScore() {
    QWidget * widget = new QWidget();
    QLayout * layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    widget->setLayout(layout);

    // Définition du texte à afficher
    int nbNotesReussis = 0;
    for(int i = 0 ; i < partition.size() ; i++) {
        if(partition[i].reussi) {
            ++nbNotesReussis;
        }
    }

    QString texte = QString::number(nbNotesReussis);
    texte.append(" sur ");
    texte.append(QString::number(partition.size()));
    texte.append(" notes trouvées !");
    score = new QLabel(texte);
    layout->addWidget(score);

    // Definition de la police : Calibri, 14pt
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(14);
    score->setFont(police);

    return widget;
}

QWidget* QPageResultat::creerBoutons() {
    QWidget * boutons = new QWidget(this);
    QLayout * layout = new QHBoxLayout(boutons);
    layout->setAlignment(Qt::AlignCenter);
    boutons->setLayout(layout);

    // Affiche le bouton "Voir ma performance"
    boutonPerformance = new QPushButton("Voir ma performance",this);
    //boutonPerformance->setMaximumSize(30,20);
    layout->addWidget(boutonPerformance);
    connect(boutonPerformance, SIGNAL(pressed()),
            this, SLOT(afficherPerformance()));

    // Affiche le bouton "Réessayer"
    boutonReessayer = new QPushButton("Réssayer",this);
    //boutonPerformance->setMaximumSize(30,20);
    layout->addWidget(boutonReessayer);

    // Affiche le bouton "Accueil"
    boutonAccueil = new QPushButton("Accueil",this);
    //boutonPerformance->setMaximumSize(30,20);
    layout->addWidget(boutonAccueil);

    return boutons;
}

void QPageResultat::afficherPerformance() {
    QWidget * widget = new QWidget();
    QVBoxLayout * layout = new QVBoxLayout();
    widget->setLayout(layout);

    QPortee * portees = new QPortee();
    for(int i = 0 ; i < partition.size() ; i++) {
        portees->addNote(partition[i]);
    }
    portees->setAfficherCurseur(false);
    layout->addWidget(portees);

    widget->show();

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
             << "Affiche les performances" << endl;
    }
    file.close();
}
