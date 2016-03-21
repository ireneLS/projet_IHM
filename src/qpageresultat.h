#ifndef QPAGERESULTAT_H
#define QPAGERESULTAT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QDate>
#include <QTextStream>

#include <vector>

#include "note.h"
#include "qportee.h"

class QPageResultat : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief QPageResultat constructeur d'une page de résultat
     * @param parent Widget père de la pageResultat
     */
    explicit QPageResultat(QWidget *parent = 0);
    /**
     * @brief setPartition charge la partition jouée précédemment ce qui permettra d'afficher les performances et le score
     * @param p les notes jouées sur la partition
     */
    void setPartition(const vector<Note> &p);

    /**
     * @brief layout layout de la page de résultat
     */
    QLayout * layout;
    /**
     * @brief score le score affiché sur la page de résultat
     */
    QLabel * score;
    /**
     * @brief boutonPerformance le bouton "voir ma perfomance"
     */
    QPushButton * boutonPerformance;
    /**
     * @brief boutonReessayer le bouton "réessayer" de la page
     */
    QPushButton * boutonReessayer;
    /**
     * @brief boutonAccueil le bouton "accueil"
     */
    QPushButton * boutonAccueil;

private:
    /**
     * @brief creerAppreciation créer un widget contenant l'appréciation
     * @return un widget avec l'appréciation du score
     */
    QWidget* creerAppreciation();
    /**
     * @brief creerScore créer un widget contenant le score
     * @return un widget avec le score
     */
    QWidget* creerScore();
    /**
     * @brief creerBoutons créer un widget contenant les boutons accueil, rééssayer et performance
     * @return un widget contenant les trois boutons
     */
    QWidget* creerBoutons();
    /**
     * @brief partition la partition jouée dans l'application qui sera affiché dans l'écran de performance
     */
    vector<Note> partition;

 public slots :
    /**
     * @brief afficherPerformance évenement créant une fenêtre contenant la performance de la partition
     */
    void afficherPerformance();
};

#endif // QPAGERESULTAT_H
