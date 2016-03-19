#ifndef NOTEZBIEN_H
#define NOTEZBIEN_H

#include <QWidget>
#include <vector>
#include <iostream>
#include "note.h"

using namespace std;

namespace Ui {
class NotezBien;
}

class NotezBien : public QWidget
{
    Q_OBJECT

public:
    explicit NotezBien(QWidget *parent = 0);
    ~NotezBien();
    vector<Note> lirePartition(const string cheminPartition);


private:
    Ui::NotezBien *ui;
};

#endif // NOTEZBIEN_H
