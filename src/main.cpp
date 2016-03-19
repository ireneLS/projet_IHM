#include "notezbien.h"
#include "Clavier.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotezBien w;
    string str = "C:\\Users\\Jean Theodore\\Documents\\GitHub\\projet_IHM\\ressources\\partition_1.xml";
    w.lirePartition(str);
    w.show();


    Clavier* clavier = new Clavier();
    clavier->show();
    return a.exec();
}
