#include "notezbien.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotezBien w;
    w.show();

    return a.exec();
}
