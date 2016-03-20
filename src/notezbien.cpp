#include "notezbien.h"
#include "ui_notezbien.h"

#include <iostream>
using namespace std;

NotezBien::NotezBien(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotezBien)
{
    // Initialisation
    this->setMinimumSize(908,255);
    QVBoxLayout * mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);

    // Creer le piano
    clavier = new Clavier();
    connect(clavier,SIGNAL(fermer()),
            this,SLOT(close()));
    QDesktopWidget bureau;
    QRect dimensionBureau = bureau.screenGeometry();
    clavier->move(dimensionBureau.center().x() - clavier->width() / 2,
                  dimensionBureau.bottom() - clavier->height() + 100);
    clavier->show();

    // Creer la page d'accueil et indique que le bouton jouer affichage la page des partitions
    pageAccueil = new QPageAccueil();
    connect(pageAccueil->boutonJouer, SIGNAL(pressed()),
            this, SLOT(afficherPagePartition()));

    // Creer la page des partitions, et indique la partition à afficher
    pagePartition = new QPagePartition();
    pagePartition->updatePortees( pageAccueil->listePartitions->currentText());
    connect(pageAccueil->listePartitions, SIGNAL(currentIndexChanged(QString)),
            pagePartition, SLOT(updatePortees(QString)) );
    connect(pageAccueil->boutonJouer, SIGNAL(pressed()),
            pagePartition, SLOT(updatePortees()) );


    // Creer la page résultats
    pageResultats = new QPageResultat();
    connect(pageResultats->boutonAccueil, SIGNAL(pressed()),
            this, SLOT(afficherPageAccueil()) );
    connect(pageResultats->boutonReessayer, SIGNAL(pressed()),
            pagePartition, SLOT(updatePortees()) );
    connect(pageResultats->boutonReessayer, SIGNAL(pressed()),
            this, SLOT(afficherPagePartition()) );
    connect(pagePartition, SIGNAL(fini(vector<Note>)),
            this, SLOT(afficherPageResultat(vector<Note>)) );

    // Connection
    this->connectPiano();

    // Gestionnaire des pages
    stack = new QStackedWidget(this);
    stack->addWidget(pageAccueil);
    stack->addWidget(pagePartition);
    stack->addWidget(pageResultats);
    mainLayout->addWidget(stack);
}

NotezBien::~NotezBien()
{
    delete ui;
}

void NotezBien::afficherPageAccueil() {
    stack->setCurrentIndex(0);

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
             << "Affichage page d'accueil" << endl;
    }
    file.close();
}

void NotezBien::afficherPagePartition() {
    stack->setCurrentIndex(1);

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
             << "Affichage page partition" << endl;
    }
    file.close();
}

void NotezBien::afficherPageResultat(const vector<Note> & partitions) {
    pageResultats->setPartition(partitions);
    stack->setCurrentIndex(2);

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
             << "Affichage page resultat" << endl;
    }
    file.close();
}

void NotezBien::connectPiano() {
    connect(clavier->toucheBlancheDO1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheRE1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheMI1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheFA1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheSOL1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheLA1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheSI1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));

    connect(clavier->toucheBlancheDO2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheRE2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheMI2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheFA2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheSOL2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheLA2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheBlancheSI2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));

    connect(clavier->toucheNoireDOD1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheNoireRED1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));

    connect(clavier->toucheNoireFAD1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheNoireSOLD1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheNoireLAD1, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));

    connect(clavier->toucheNoireDOD2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheNoireRED2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));

    connect(clavier->toucheNoireFAD2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheNoireSOLD2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
    connect(clavier->toucheNoireLAD2, SIGNAL(jouee(Note)),
            pagePartition, SLOT(checkNote(Note)));
}

void NotezBien::closeEvent(QCloseEvent * event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "",
                                                                tr("Êtes-vous sûr de vouloir quitter Notez-Bien?\n"),
                                                                QMessageBox::Ok | QMessageBox::No,
                                                                QMessageBox::Ok);
    if (resBtn == QMessageBox::Ok) {
        event->setAccepted(false);
        clavier->closeEvent(event);
        event->accept();
    } else {
        event->ignore();
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
             << "Fermerture de l'application" << endl;
    }
    file.close();

}
