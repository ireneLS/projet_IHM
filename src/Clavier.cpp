#include "Clavier.h"

Clavier::Clavier(QWidget * parent) : QWidget(parent) {
    this->setMinimumSize(800, 300);

    Touche* toucheBlancheDO1 = new Touche(new Note(DO,1), false);
    Touche* toucheBlancheRE1 = new Touche(new Note(RE,1), false);
    Touche* toucheBlancheMI1 = new Touche(new Note(MI,1),false);
    Touche* toucheBlancheFA1 = new Touche(new Note(FA,1),false);
    Touche* toucheBlancheSOL1 = new Touche(new Note(SOL,1),false);
    Touche* toucheBlancheLA1 = new Touche(new Note(LA,1),false);
    Touche* toucheBlancheSI1 = new Touche(new Note(SI,1),false);

    Touche* toucheBlancheDO2 = new Touche(new Note(DO,2),false);
    Touche* toucheBlancheRE2 = new Touche(new Note(RE,2),false);
    Touche* toucheBlancheMI2 = new Touche(new Note(MI,2),false);
    Touche* toucheBlancheFA2 = new Touche(new Note(FA,2),false);
    Touche* toucheBlancheSOL2 = new Touche(new Note(SOL,2),false);
    Touche* toucheBlancheLA2 = new Touche(new Note(LA,2),false);
    Touche* toucheBlancheSI2 = new Touche(new Note(SI,2),false);

    //Touche* toucheBlancheDO3 = new Touche(new Note(DO,3),false);


    Touche* toucheNoireDOD1 = new Touche(new Note(DO,1),true);
    Touche* toucheNoireRED1 = new Touche(new Note(DO,1),true);

    Touche* toucheNoireFAD1 = new Touche(new Note(DO,1),true);
    Touche* toucheNoireSOLD1 = new Touche(new Note(DO,1),true);
    Touche* toucheNoireLAD1 = new Touche(new Note(DO,1),true);


    Touche* toucheNoireDOD2 = new Touche(new Note(DO,1),true);
    Touche* toucheNoireRED2 = new Touche(new Note(DO,1),true);

    Touche* toucheNoireFAD2 = new Touche(new Note(DO,1),true);
    Touche* toucheNoireSOLD2 = new Touche(new Note(DO,1),true);
    Touche* toucheNoireLAD2 = new Touche(new Note(DO,1),true);

    //Touche* toucheNoireDOD3 = new Touche(new Note(DO,1),true);

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

    //layout->addWidget(toucheBlancheDO3,0,42,6,3);

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

    // layout->addWidget(toucheNoireDOD3,0,44,3,1);// je sais pas pourquoi ça bug quand on rajoute celle là.....

}
