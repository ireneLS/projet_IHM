#ifndef QPORTEE_H
#define QPORTEE_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QPoint>
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
    void paintEvent(QPaintEvent * event);

private:
    vector<Note> notes;


};

#endif // QPORTEE_H
