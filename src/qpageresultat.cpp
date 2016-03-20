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
    score = new QLabel(texte);
    layout->replaceWidget(score,score);
}

QLabel* QPageResultat::creerAppreciation() {
    QLabel * appreciation = new QLabel("Bravo ! ");

    // Definition de la police : Calibri, 18pt
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(18);
    appreciation->setFont(police);

    return appreciation;
}

QLabel* QPageResultat::creerScore() {
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

    // Definition de la police : Calibri, 14pt
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(14);
    score->setFont(police);

    return score;
}

QWidget* QPageResultat::creerBoutons() {
    QWidget * boutons = new QWidget(this);
    QLayout * layout = new QHBoxLayout(boutons);
    boutons->setLayout(layout);

    // Affiche le bouton "Voir ma performance"
    boutonPerfomance = new QPushButton("Voir ma performance",this);
    layout->addWidget(boutonPerfomance);

    // Affiche le bouton "Réessayer"
    boutonReessayer = new QPushButton("Réssayer",this);
    layout->addWidget(boutonReessayer);

    // Affiche le bouton "Accueil"
    boutonAccueil = new QPushButton("Accueil",this);
    layout->addWidget(boutonAccueil);

    return boutons;
}
