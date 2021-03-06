#include "pageaccueil.h"

QPageAccueil::QPageAccueil(QWidget *parent) : QWidget(parent) {
    // Definition du layout principal
    QLayout * layout = new QVBoxLayout(this);
    this->setLayout(layout);

    // Affichage du titre
    layout->addWidget(creerTitre());

    // Affichage de la selection du menu déroulant
    layout->addWidget(creerSelectionPartition());

    // Affichage de l'option d'ajout de partition
    layout->addWidget(creerAjoutPartition());

    // Affichage du bouton jouer
    layout->addWidget(creerBoutonJouer());
}

QWidget * QPageAccueil::creerTitre() {
    // Initialisation et ajout du layout principal
    QWidget * widgetAccueil = new QWidget();
    QLayout * layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    widgetAccueil->setLayout(layout);

    // Creation du titre
    titre = new QLabel("Notez - bien");
    layout->addWidget(titre);

    // Definition de la police : Calibri, gras, 30pt
    QFont police = QFont();
    police.setFamily("Calibri");
    police.setPointSize(30);
    police.setBold(true);
    titre->setFont(police);

    return widgetAccueil;
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
             << "MAJ de la liste des partitions" << endl;
    }
    file.close();
}

QWidget* QPageAccueil::creerSelectionPartition() {

    // Initialisation et ajout du layout principal
    QWidget * selectionPartition = new QWidget();
    QLayout * layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
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

    // LOGS
    // Utilise la date d'aujourd'hui en tant que nom de fichier log
    QDate today =QDate::currentDate();
    QString fichierLog = QString("../logs/");
    fichierLog.append(QString::number(today.day()));
    fichierLog.append("-");
    fichierLog.append(QString::number(today.month()));
    fichierLog.append("-");
    fichierLog.append(QString::number(today.year()));
    fichierLog.append("logs.txt");

    QFile file(fichierLog);
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append)) {
        // Création d'un flux servant à écrire les logs
        QTextStream flux(&file);
        flux.setCodec("UTF-8");

        // Ecriture des logs
        QTime now = QTime::currentTime();
        flux << "[" << now.hour() << "h" << now.minute() << "m" << now.second() << "s]"
             << "Ajout d'une partition" << endl;
    }
    file.close();
}

QWidget* QPageAccueil::creerAjoutPartition() {
    // Initialisation et ajout du layout principal
    QWidget* ajoutPartition = new QWidget();
    QLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
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

QWidget * QPageAccueil::creerBoutonJouer() {
    // Initialisation et ajout du layout principal
    QWidget * widgetJouer = new QWidget();
    QLayout* layout = new QHBoxLayout();
    widgetJouer ->setLayout(layout);

    boutonJouer = new QPushButton("Jouer !");
    boutonJouer->setMaximumWidth(100);
    boutonJouer->setMinimumHeight(50);
    layout->addWidget(boutonJouer);

    QFont police = QFont();
    police.setBold(true);
    police.setPointSize(12);
    boutonJouer->setFont(police);

    return widgetJouer;
}
