#include "Clavier.h"
#include "Touche.h"
#include <QGridLayout>

Clavier::Clavier() :
    QWidget()
{

    Touche* touche1 = new Touche(true);
    Touche* touche2 = new Touche(false);
    Touche* touche3 = new Touche(true);
    Touche* touche4 = new Touche(false);
    Touche* touche5 = new Touche(true);
    Touche* touche6 = new Touche(false);
    Touche* touche7 = new Touche(true);
    Touche* touche8 = new Touche(false);
    Touche* touche9 = new Touche(true);
    Touche* touche10 = new Touche(false);
    QGridLayout* layout= new QGridLayout(this);
//layout->setGeometry(new QRect(0,0,this->width(),this->height()));
    //layout->setSizeConstraint(QLayout::SetMaximumSize);

    //layout->setRowStretch(0,this->height());
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    layout->addWidget(touche1,0,0,3,1); //, Qt::AlignBaseline
    layout->addWidget(touche2,1,1,3,3);
    layout->addWidget(touche3,2,2,3,3);
    layout->addWidget(touche4,3,3,3,1);
    layout->addWidget(touche5,4,4,3,3);
    layout->addWidget(touche6,5,5,3,1);
    layout->addWidget(touche7,6,6,3,3);
    layout->addWidget(touche8,7,7,3,1);
    layout->addWidget(touche9,8,8,3,3);
    layout->addWidget(touche10,9,9,3,1);


}
