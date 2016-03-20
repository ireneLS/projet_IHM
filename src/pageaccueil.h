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

#include <iostream>

using namespace std;

class QPageAccueil : public QWidget
{
    Q_OBJECT
public:
    explicit QPageAccueil(QWidget *parent = 0);
    QLabel * titre;
    QComboBox * listePartitions;
    QPushButton * boutonAjoutPartition;
    QPushButton * boutonJouer;

public slots:
    void ajouterPartition();
    void updateListePartitions();

private:
    QWidget * creerTitre();
    QWidget * creerSelectionPartition();
    QWidget * creerAjoutPartition();
    QWidget * creerBoutonJouer();
};

#endif // PAGEACCUEIL_H
