/**
 * \file notezbien.h
 * \brief Définition de l'application Notez Bien et de ses différents composants
 * \author Léo Cassiau, Irène Le Squer
 * \version 0.1
 */

#ifndef NOTEZBIEN_H
#define NOTEZBIEN_H

#include <QWidget>
#include <QStackedWidget>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDate>
#include <QTextStream>

#include <vector>
#include <string>

#include "pageaccueil.h"
#include "qpagepartition.h"
#include "qpageresultat.h"
#include "note.h"
#include "qportee.h"
#include "Clavier.h"

using namespace std;

namespace Ui {
class NotezBien;
}

class NotezBien : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de NotezBien
     * @param parent Père du widget
     */
    explicit NotezBien(QWidget *parent = 0);

    /**
     * @brief Destructeur de NotezBien
     */
    ~NotezBien();

    /**
     * @brief Lit la partition contenu dans le fichier indiqué par cheminPartition
     * @param cheminPartition Chemin du fichier contenant la partition
     * @return La partition lu dans le fichier
     */
    vector<Note> lirePartition(const string cheminPartition);

public slots:
    /**
     * @brief Evenement produit lors de la fermeture de la page
     * @param event Evenement produit
     */
    void closeEvent(QCloseEvent * event);

    /**
     * @brief Affiche la page d'accueil de NotezBien
     */
    void afficherPageAccueil();

    /**
     * @brief Affiche la page contenant la partition
     */
    void afficherPagePartition();

    /**
     * @brief Affiche la page de résultat de NotezBien
     * @param partitions Partition joué par l'utilisateur
     */
    void afficherPageResultat(const vector<Note> & partitions);

signals:
    /**
     * @brief Signal émit lors l'on ferme NotezBien
     */
    void fermer();

private:
    /**
     * @brief Interface correspondant au fichier notezbien.ui
     */
    Ui::NotezBien *ui;

    /**
     * @brief Gestionnaire de widget permettant d'afficher une page à la fois
     */
    QStackedWidget * stack;

    /**
     * @brief Page d'accueil de NotezBien
     */
    QPageAccueil * pageAccueil;

    /**
     * @brief Page affichant les partitions
     */
    QPagePartition * pagePartition;

    /**
     * @brief Page des résultats de NotezBien
     */
    QPageResultat * pageResultats;

    /**
     * @brief Clavier de piano affiché
     */
    Clavier * clavier;

    /**
     * @brief Connecte les différentes touches du clavier à l'application
     */
    void connectPiano();
};

#endif // NOTEZBIEN_H
