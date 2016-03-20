#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QGridLayout>

#include "Touche.h"
#include "note.h"

class Clavier : public QWidget
{
    Q_OBJECT
public:
    Clavier(QWidget * parent = 0);

signals:

public slots:

};

#endif // CLAVIER_H
