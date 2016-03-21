/**
 * \file Clavier.h
 * \brief Définition du widget clavier affichant un clavier de piano
 * \author Léo Cassiau, Irène Le Squer
 * \version 0.1
 */

#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QGridLayout>
#include <QCloseEvent>
#include <QMessageBox>

#include "Touche.h"
#include "note.h"

class Clavier : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief Constructeur de clavier
     * @param parent Widget père du clavier
     */
    Clavier(QWidget * parent = 0);

    /**
     * @brief Evenement produit lors de la fermeture du widget
     * @param event Evenement fermant la fenetre
     */
    void closeEvent(QCloseEvent * event);

    /**
     * @brief Touche DO du piano d'octave 1
     */
    Touche* toucheBlancheDO1;

    /**
     * @brief Touche RE du piano d'octave 1
     */
    Touche* toucheBlancheRE1;

    /**
     * @brief Touche MI du piano d'octave 1
     */
    Touche* toucheBlancheMI1;

    /**
     * @brief Touche FA du piano d'octave 1
     */
    Touche* toucheBlancheFA1;

    /**
     * @brief Touche SOL du piano d'octave 1
     */
    Touche* toucheBlancheSOL1;

    /**
     * @brief Touche LA du piano d'octave 1
     */
    Touche* toucheBlancheLA1;

    /**
     * @brief Touche SI du piano d'octave 1
     */
    Touche* toucheBlancheSI1;

    /**
     * @brief Touche DO du piano d'octave 2
     */
    Touche* toucheBlancheDO2;

    /**
     * @brief Touche RE du piano d'octave 2
     */
    Touche* toucheBlancheRE2;

    /**
     * @brief Touche MI du piano d'octave 2
     */
    Touche* toucheBlancheMI2;

    /**
     * @brief Touche FA du piano d'octave 2
     */
    Touche* toucheBlancheFA2;

    /**
     * @brief Touche SOL du piano d'octave 2
     */
    Touche* toucheBlancheSOL2;

    /**
     * @brief Touche LA du piano d'octave 2
     */
    Touche* toucheBlancheLA2;

    /**
     * @brief Touche SI du piano d'octave 2
     */
    Touche* toucheBlancheSI2;

    /**
     * @brief Touche DO# du piano d'octave 1
     */
    Touche* toucheNoireDOD1;

    /**
     * @brief Touche RE# du piano d'octave 1
     */
    Touche* toucheNoireRED1;

    /**
     * @brief Touche FA# du piano d'octave 1
     */
    Touche* toucheNoireFAD1;

    /**
     * @brief Touche SOL# du piano d'octave 1
     */
    Touche* toucheNoireSOLD1;

    /**
     * @brief Touche LA# du piano d'octave 1
     */
    Touche* toucheNoireLAD1;

    /**
     * @brief Touche DO# du piano d'octave 2
     */
    Touche* toucheNoireDOD2;

    /**
     * @brief Touche RE# du piano d'octave 2
     */
    Touche* toucheNoireRED2;

    /**
     * @brief Touche FA# du piano d'octave 2
     */
    Touche* toucheNoireFAD2;

    /**
     * @brief Touche SOL# du piano d'octave 2
     */
    Touche* toucheNoireSOLD2;

    /**
     * @brief Touche LA# du piano d'octave 2
     */
    Touche* toucheNoireLAD2;

signals:
    /**
     * @brief Signale émit lorsque l'on souhaite fermer le widget
     */
    void fermer();

};

#endif // CLAVIER_H
