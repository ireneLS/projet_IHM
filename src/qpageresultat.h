#ifndef QPAGERESULTAT_H
#define QPAGERESULTAT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <vector>

#include "note.h"
#include "qportee.h"

class QPageResultat : public QWidget
{
    Q_OBJECT
public:
    explicit QPageResultat(QWidget *parent = 0);
    void setPartition(const vector<Note> &p);

    QLayout * layout;
    QLabel * score;
    QPushButton * boutonPerformance;
    QPushButton * boutonReessayer;
    QPushButton * boutonAccueil;

private:
    QWidget* creerAppreciation();
    QWidget* creerScore();
    QWidget* creerBoutons();
    vector<Note> partition;

 public slots :
    void afficherPerformance();
};

#endif // QPAGERESULTAT_H
