#ifndef QPAGERESULTAT_H
#define QPAGERESULTAT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <vector>

#include "note.h"

class QPageResultat : public QWidget
{
    Q_OBJECT
public:
    explicit QPageResultat(QWidget *parent = 0);
    void setPartition(const vector<Note> &p);

    QLayout * layout;
    QLabel * score;
    QPushButton * boutonPerfomance;
    QPushButton * boutonReessayer;
    QPushButton * boutonAccueil;

private:
    QLabel* creerAppreciation();
    QLabel* creerScore();
    QWidget* creerBoutons();
    vector<Note> partition;
};

#endif // QPAGERESULTAT_H
