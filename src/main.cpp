#include "notezbien.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotezBien * fenetre = new NotezBien();
    QDesktopWidget bureau;
    QRect dimensionBureau = bureau.screenGeometry();
    fenetre->move(dimensionBureau.center().x() - fenetre->width() / 2,
                  dimensionBureau.top() );
    fenetre->show();

    return a.exec();
}
