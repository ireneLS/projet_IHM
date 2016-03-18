#include "Touche.h"

Touche::Touche(bool estNoire)
{
    if (estNoire){
        this->setStyleSheet("QPushButton { background-color: black;outline:none}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
    else{
        this->setStyleSheet("QPushButton { background-color: white;outline:none}"
                            "QPushButton:hover {background-color: grey; border-style: none;}");
    }
}
