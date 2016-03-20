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
    Clavier(QWidget * parent = 0);
    void closeEvent(QCloseEvent * event);

    Touche* toucheBlancheDO1;
    Touche* toucheBlancheRE1;
    Touche* toucheBlancheMI1;
    Touche* toucheBlancheFA1;
    Touche* toucheBlancheSOL1;
    Touche* toucheBlancheLA1;
    Touche* toucheBlancheSI1;

    Touche* toucheBlancheDO2;
    Touche* toucheBlancheRE2;
    Touche* toucheBlancheMI2;
    Touche* toucheBlancheFA2;
    Touche* toucheBlancheSOL2;
    Touche* toucheBlancheLA2;
    Touche* toucheBlancheSI2;

    Touche* toucheNoireDOD1;
    Touche* toucheNoireRED1;

    Touche* toucheNoireFAD1;
    Touche* toucheNoireSOLD1;
    Touche* toucheNoireLAD1;

    Touche* toucheNoireDOD2;
    Touche* toucheNoireRED2;

    Touche* toucheNoireFAD2;
    Touche* toucheNoireSOLD2;
    Touche* toucheNoireLAD2;

signals:
    void fermer();

};

#endif // CLAVIER_H
