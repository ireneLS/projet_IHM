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

class PageAccueil : public QWidget
{
    Q_OBJECT
public:
    explicit PageAccueil(QWidget *parent = 0);
    QLabel * titre;
    QComboBox * listePartitions;
    QPushButton * boutonAjoutPartition;
    QPushButton * boutonJouer;

public slots:
    void ajouterPartition();
    void updateListePartitions();

private:
    QLabel * creerTitre();
    QWidget * creerSelectionPartition();
    QWidget * creerAjoutPartition();
};

#endif // PAGEACCUEIL_H
