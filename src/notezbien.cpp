#include "notezbien.h"
#include "ui_notezbien.h"

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
    connect(pagePartition, SIGNAL(fini()),
            this, SLOT(afficherPageResultat()) );

    // Creer la page résultats
    pageResultats = new QPageResultat();

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
}

void NotezBien::afficherPagePartition() {
    stack->setCurrentIndex(1);
}

void NotezBien::afficherPageResultat() {
    stack->setCurrentIndex(2);
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
