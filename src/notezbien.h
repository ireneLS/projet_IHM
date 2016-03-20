#ifndef NOTEZBIEN_H
#define NOTEZBIEN_H

#include <QWidget>
#include <QStackedWidget>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QCloseEvent>

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
    explicit NotezBien(QWidget *parent = 0);
    ~NotezBien();
    QWidget * creerPartition();
    QWidget * creerMenu();
    vector<Note> lirePartition(const string cheminPartition);

public slots:
    void closeEvent(QCloseEvent * event);
    void afficherPageAccueil();
    void afficherPagePartition();
    void afficherPageResultat(const vector<Note> & partitions);

private:
    Ui::NotezBien *ui;
    QStackedWidget * stack;
    QPageAccueil * pageAccueil;
    QPagePartition * pagePartition;
    QPageResultat * pageResultats;
    Clavier * clavier;

    void connectPiano();
};

#endif // NOTEZBIEN_H
