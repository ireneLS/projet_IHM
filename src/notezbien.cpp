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

    // Creer la page d'accueil et indique que le bouton jouer affichage la page des partitions
    pageAccueil = new QPageAccueil();
    connect(pageAccueil->boutonJouer, SIGNAL(pressed()),
            this, SLOT(afficherPagePartition()));

    // Creer la page des partitions, et indique la partition à afficher
    pagePartition = new QPagePartition();
    pagePartition->updatePortees(pageAccueil->listePartitions->currentText());
    connect(pageAccueil->listePartitions, SIGNAL(currentIndexChanged(QString)),
            pagePartition, SLOT(updatePortees(QString)) );


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
