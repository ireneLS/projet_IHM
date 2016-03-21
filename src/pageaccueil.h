/**
 * \file pageaccueil.h
 * \brief Définition du widget QPageAccueil affichant la page d'accueil de NotezBien
 * \author Léo Cassiau, Irène Le Squer
 * \version 0.1
 */

#ifndef PAGEACCUEIL_H
#define PAGEACCUEIL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDate>
#include <QTextStream>

#include <iostream>

using namespace std;

class QPageAccueil : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur de QPageAccueil
     * @param parent Père du widget
     */
    explicit QPageAccueil(QWidget *parent = 0);

    /**
     * @brief Titre affiché sur la page
     */
    QLabel * titre;

    /**
     * @brief Liste des partitions que l'utilisateur peut sélectionner
     */
    QComboBox * listePartitions;

    /**
     * @brief Bouton ajoutant une partition à la liste des partitions
     */
    QPushButton * boutonAjoutPartition;

    /**
     * @brief Bouton lançant le jeu
     */
    QPushButton * boutonJouer;

public slots:
    /**
     * @brief Evenement d'ajouts d'une partition
     */
    void ajouterPartition();

    /**
     * @brief Evenement mettant à jour la liste des partitions jouables
     */
    void updateListePartitions();

private:
    /**
     * @brief Créer le widget mettant en forme le titre
     * @return Widget créé
     */
    QWidget * creerTitre();

    /**
     * @brief Créer le widget mettant en forme la liste de sélection des partitions
     * @return Widget créé
     */
    QWidget * creerSelectionPartition();

    /**
     * @brief Créer le widget mettant en forme le bouton d'ajout des partitions
     * @return Widget créé
     */
    QWidget * creerAjoutPartition();

    /**
     * @brief Créer le widget mettant en forme le bouton jouer
     * @return Widget créé
     */
    QWidget * creerBoutonJouer();
};

#endif // PAGEACCUEIL_H
