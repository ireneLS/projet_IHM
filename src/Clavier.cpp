#include "Clavier.h"
#include "Touche.h"
#include <QGridLayout>

Clavier::Clavier() :
    QWidget()
{
    this->setMinimumSize(800, 300);

    Touche* toucheBlancheDO1 = new Touche(false);
    Touche* toucheBlancheRE1 = new Touche(false);
    Touche* toucheBlancheMI1 = new Touche(false);
    Touche* toucheBlancheFA1 = new Touche(false);
    Touche* toucheBlancheSOL1 = new Touche(false);
    Touche* toucheBlancheLA1 = new Touche(false);
    Touche* toucheBlancheSI1 = new Touche(false);

    Touche* toucheBlancheDO2 = new Touche(false);
    Touche* toucheBlancheRE2 = new Touche(false);
    Touche* toucheBlancheMI2 = new Touche(false);
    Touche* toucheBlancheFA2 = new Touche(false);
    Touche* toucheBlancheSOL2 = new Touche(false);
    Touche* toucheBlancheLA2 = new Touche(false);
    Touche* toucheBlancheSI2 = new Touche(false);

    Touche* toucheBlancheDO3 = new Touche(false);
    Touche* toucheBlancheRE3 = new Touche(false);
    Touche* toucheBlancheMI3 = new Touche(false);
    Touche* toucheBlancheFA3 = new Touche(false);
    Touche* toucheBlancheSOL3 = new Touche(false);
    Touche* toucheBlancheLA3 = new Touche(false);
    Touche* toucheBlancheSI3 = new Touche(false);

    Touche* toucheBlancheDO4 = new Touche(false);


    Touche* toucheNoireDOD1 = new Touche(true);
    Touche* toucheNoireRED1 = new Touche(true);

    Touche* toucheNoireFAD1 = new Touche(true);
    Touche* toucheNoireSOLD1 = new Touche(true);
    Touche* toucheNoireLAD1 = new Touche(true);


    Touche* toucheNoireDOD2 = new Touche(true);
    Touche* toucheNoireRED2 = new Touche(true);

    Touche* toucheNoireFAD2 = new Touche(true);
    Touche* toucheNoireSOLD2 = new Touche(true);
    Touche* toucheNoireLAD2 = new Touche(true);


    Touche* toucheNoireDOD3 = new Touche(true);
    Touche* toucheNoireRED3 = new Touche(true);

    Touche* toucheNoireFAD3 = new Touche(true);
    Touche* toucheNoireSOLD3 = new Touche(true);
    Touche* toucheNoireLAD3 = new Touche(true);


    Touche* toucheNoireDOD4 = new Touche(true);

    QGridLayout* layout= new QGridLayout(this);

    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);

    layout->addWidget(toucheBlancheDO1,0,0,6,3);
    layout->addWidget(toucheBlancheRE1,0,3,6,3);
    layout->addWidget(toucheBlancheMI1,0,6,6,3);
    layout->addWidget(toucheBlancheFA1,0,9,6,3);
    layout->addWidget(toucheBlancheSOL1,0,12,6,3);
    layout->addWidget(toucheBlancheLA1,0,15,6,3);
    layout->addWidget(toucheBlancheSI1,0,18,6,3);

    layout->addWidget(toucheBlancheDO2,0,21,6,3);
    layout->addWidget(toucheBlancheRE2,0,24,6,3);
    layout->addWidget(toucheBlancheMI2,0,27,6,3);
    layout->addWidget(toucheBlancheFA2,0,30,6,3);
    layout->addWidget(toucheBlancheSOL2,0,33,6,3);
    layout->addWidget(toucheBlancheLA2,0,36,6,3);
    layout->addWidget(toucheBlancheSI2,0,39,6,3);

    layout->addWidget(toucheBlancheDO3,0,42,6,3);
    layout->addWidget(toucheBlancheRE3,0,45,6,3);
    layout->addWidget(toucheBlancheMI3,0,48,6,3);
    layout->addWidget(toucheBlancheFA3,0,51,6,3);
    layout->addWidget(toucheBlancheSOL3,0,54,6,3);
    layout->addWidget(toucheBlancheLA3,0,57,6,3);
    layout->addWidget(toucheBlancheSI3,0,60,6,3);

    layout->addWidget(toucheBlancheDO4,0,63,6,3);


    layout->addWidget(toucheNoireDOD1,0,2,3,2);
    layout->addWidget(toucheNoireRED1,0,5,3,2);
    layout->addWidget(toucheNoireFAD1,0,11,3,2);
    layout->addWidget(toucheNoireSOLD1,0,14,3,2);
    layout->addWidget(toucheNoireLAD1,0,17,3,2);

    layout->addWidget(toucheNoireDOD2,0,23,3,2);
    layout->addWidget(toucheNoireRED2,0,26,3,2);
    layout->addWidget(toucheNoireFAD2,0,32,3,2);
    layout->addWidget(toucheNoireSOLD2,0,35,3,2);
    layout->addWidget(toucheNoireLAD2,0,38,3,2);

    layout->addWidget(toucheNoireDOD3,0,44,3,2);
    layout->addWidget(toucheNoireRED3,0,47,3,2);
    layout->addWidget(toucheNoireFAD3,0,53,3,2);
    layout->addWidget(toucheNoireSOLD3,0,56,3,2);
    layout->addWidget(toucheNoireLAD3,0,59,3,2);

   // layout->addWidget(toucheNoireDOD4,0,65,3,1); // je sais pas pourquoi ça bug quand on rajoute celle là.....

}
