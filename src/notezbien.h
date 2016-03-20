#ifndef NOTEZBIEN_H
#define NOTEZBIEN_H

#include <QWidget>
#include <QStackedWidget>

#include <vector>
#include <string>

#include "pageaccueil.h"
#include "qpagepartition.h"
#include "qportee.h"
#include "note.h"

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
    QPageAccueil * pageAccueil;
    QPagePartition * pagePartition;
    QWidget * pageResultats;
};

#endif // NOTEZBIEN_H
