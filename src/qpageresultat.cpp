#include "qpageresultat.h"

QPageResultat::QPageResultat(QWidget *parent) : QWidget(parent)
{
    // Definition du layout principal
    QLayout * layout = new QVBoxLayout(this);
    this->setLayout(layout);

    QLabel * t = new QLabel("YEAH");
    layout->addWidget(t);

}
