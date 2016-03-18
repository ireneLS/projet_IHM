#include "Touche.h"

Touche::Touche(bool estNoire)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    if (estNoire){
        this->setStyleSheet("QPushButton { background-color: black;outline:none;border-radius: 1px;}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
    else{
        this->setStyleSheet("QPushButton { background-color: white;outline:none}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
}

