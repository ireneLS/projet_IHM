#include "notezbien.h"
#include "Clavier.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // NotezBien w;
   // w.show();

   // Touche* tn = new Touche(true);
   // tn->show();

    Clavier* clavier = new Clavier();
    clavier->show();
    return a.exec();
}
