#ifndef QPORTEE_H
#define QPORTEE_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QPixmap>

#include <vector>

#include "note.h"

using namespace std;

class QPortee : public QWidget
{
    Q_OBJECT
public:
    static const int largeurNote = 30;
    vector<Note> notes;

    explicit QPortee(QWidget *parent = 0);
    void addNote(Note n);
    int nbNotes();
    int noteToHauteur(Note n);
    void paintEvent(QPaintEvent * event = 0);
    void setAfficherCurseur(bool value);

public slots:
    bool checkNote(Note n);

private:
    int noteActuelle;
    bool afficherCurseur;

};

#endif // QPORTEE_H
