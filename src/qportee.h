#ifndef QPORTEE_H
#define QPORTEE_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QPixmap>

#include <vector>

#include "note.h"

using namespace std;

class QPortee : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief largeurNote la largeur d'une note sur la portée
     */
    static const int largeurNote = 30;
    /**
     * @brief notes les notes a afficher sur la portée
     */
    vector<Note> notes;

    /**
     * @brief QPortee constructeur d'une portée
     * @param parent Widget père de la portée
     */
    explicit QPortee(QWidget *parent = 0);
    /**
     * @brief addNote ajoute une note à la portée
     * @param n la note a ajouter
     */
    void addNote(Note n);
    /**
     * @brief nbNotes nombre de note de la portée
     * @return le nombre de note de la portée
     */
    int nbNotes();
    /**
     * @brief noteToHauteur converti la note en sa hauteur sur la portée
     * @param n la note a afficher
     * @return la hauteur de la note sur la portée
     */
    int noteToHauteur(Note n);
    /**
     * @brief paintEvent évènement qui dessine une portée
     * @param event
     */
    void paintEvent(QPaintEvent * event = 0);
    /**
     * @brief setAfficherCurseur fonction permettant d'afficher ou de supprimer le curseur pour une portée
     * @param value true si le curseur doit être affiché, false s'il doit être supprimé
     */
    void setAfficherCurseur(bool value);

public slots:
    /**
     * @brief checkNote verifie si la note jouée est bien la bonne pour l'affichage en couleur rouge ou vert
     * @param n la note a vérifier
     * @return true si la note est ok, false sinon
     */
    bool checkNote(Note n);

private:
    /**
     * @brief noteActuelle la position dans notes de la prochaine note jouée
     */
    int noteActuelle;
    /**
     * @brief afficherCurseur true si le curseur doit être affiché sur cette portée, false sinon
     */
    bool afficherCurseur;

};

#endif // QPORTEE_H
