#ifndef NOTEZBIEN_H
#define NOTEZBIEN_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include <QStackedWidget>
#include <QWidget>
#include "note.h"
#include "pageaccueil.h"

using namespace std;

namespace Ui {
class NotezBien;
}

class NotezBien : public QWidget
{
    Q_OBJECT

public:
    explicit NotezBien(QWidget *parent = 0);
    ~NotezBien();
    QWidget * creerPartition();
    QWidget * creerMenu();
    vector<Note> lirePartition(const string cheminPartition);

public slots:
    void afficherPageAccueil();
    void afficherPagePartition();
    void afficherPageResultat();

private:
    Ui::NotezBien *ui;
    QStackedWidget * stack;
    PageAccueil * pageAccueil;
    QWidget * pagePartition;
    QWidget * pageResultats;
};

#endif // NOTEZBIEN_H
