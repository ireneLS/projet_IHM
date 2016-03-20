#ifndef QPORTEE_H
#define QPORTEE_H

#include <QWidget>
#include <QPainter>
#include <QPoint>

#include <vector>

#include "note.h"

using namespace std;

class QPortee : public QWidget
{
    Q_OBJECT
public:
    static const int largeurNote = 30;

    explicit QPortee(QWidget *parent = 0);
    void addNote(Note n);
    int noteToHauteur(Note n);
    void paintEvent(QPaintEvent * event = 0);

public slots:
    void checkNote(Note n);

private:
    vector<Note> notes;
    int noteActuelle;


};

#endif // QPORTEE_H
