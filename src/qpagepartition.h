#ifndef QPAGEPARTITION_H
#define QPAGEPARTITION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDomDocument>
#include <QFile>

#include <vector>
#include <string>

#include "note.h"
#include "qportee.h"

using namespace std;

class QPagePartition : public QWidget
{
    Q_OBJECT
public:
    explicit QPagePartition(QWidget *parent = 0);
    vector<Note> lirePartition(const string chemin);

    //Note currentNote;

private :
    QVBoxLayout * layout;
    vector<QPortee*> portees;

public slots:
    void updatePortees(QString cheminPartition);
    void nextNote();
};

#endif // QPAGEPARTITION_H
