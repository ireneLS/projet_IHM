#include "pageaccueil.h"

QPageAccueil::QPageAccueil(QWidget *parent) : QWidget(parent) {
    // Definition du layout principal
    QLayout * layout = new QVBoxLayout(this);
    this->setLayout(layout);

    // Affichage du titre
    layout->addWidget(titre = creerTitre());

    // Affichage de la selection du menu déroulant
    layout->addWidget(creerSelectionPartition());

    // Affichage de l'option d'ajout de partition
    layout->addWidget(creerAjoutPartition());

    // Affichage du bouton jouer
    boutonJouer = new QPushButton("Jouer !");
    layout->addWidget(boutonJouer);
}

QLabel* QPageAccueil::creerTitre() {
    QLabel * titre = new QLabel("Notez-bien");

    // Definition de la police : Calibri, gras, 20pt
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(20);
    police.setBold(true);
    titre->setFont(police);

    return titre;
}

void QPageAccueil::updateListePartitions() {
    // Remets à zéro la liste
    listePartitions->clear();

    // Lit les noms des partitions, et les ajoutent à la liste
    QDir dir(QString::fromStdString("../ressources/partitions/"));
    for(int i = 2; i < dir.entryInfoList().size() ; i++) {
        QFileInfo fileInfo = dir.entryInfoList().at(i);
        listePartitions->addItem(fileInfo.baseName());
    }
}

QWidget* QPageAccueil::creerSelectionPartition() {

    // Initialisation et ajout du layout principal
    QWidget * selectionPartition = new QWidget();
    QLayout * layout = new QHBoxLayout();
    selectionPartition->setLayout(layout);

    // Definition du label et de sa police : Calibri, 12pt
    QLabel * label = new QLabel("Sélectionnez la partition à jouer : ");
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(12);
    label->setFont(police);
    layout->addWidget(label);

    // Definition de la liste déroulante
    listePartitions = new QComboBox();
    this->updateListePartitions();
    layout->addWidget(listePartitions);

    return selectionPartition;
}

void QPageAccueil::ajouterPartition() {
    // Selection de la partition
    QString chemin = QFileDialog::getOpenFileName(this, "Choississez la partition à ajouter", QDir::homePath(),"*.xml");

    // Lecture du fichier
    QFile * fichier = new QFile(chemin);
    if(fichier->exists()) {

        // Definit le chemin pour copier le fichier
        QString nouveauChemin = QString("../ressources/partitions/");
        chemin.remove(0,chemin.lastIndexOf("/"));
        nouveauChemin.append(chemin);

        // Copie le fichier en verifiant si tout s'est bien passe, et en mettant à jour la liste des partitions disponibles
        if(!fichier->copy(nouveauChemin)) {
            QMessageBox::critical(this, "Erreur", "Impossible de copier le fichier. Il existe déjà une partition du même nom");
        } else {
            this->updateListePartitions();
        }
    } else {
        QMessageBox::critical(this,"Erreur","Impossible de lire le fichier");
    }
}

QWidget* QPageAccueil::creerAjoutPartition() {
    // Initialisation et ajout du layout principal
    QWidget* ajoutPartition = new QWidget();
    QLayout* layout = new QHBoxLayout();
    ajoutPartition->setLayout(layout);

    // Definition du label et sa police : Calibri, 12pt
    QLabel * label = new QLabel("Votre partition n'est pas dans la liste ?");
    QFont police =  QFont();
    police.setFamily("Calibri");
    police.setPointSize(12);
    label->setFont(police);
    layout->addWidget(label);

    // Definition du bouton Ajout
    boutonAjoutPartition = new QPushButton("Ajoutez-la ! ");
    connect(boutonAjoutPartition, SIGNAL(pressed()), this, SLOT(ajouterPartition()));
    layout->addWidget(boutonAjoutPartition);

    return ajoutPartition;
}
