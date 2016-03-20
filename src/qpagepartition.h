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
    void resizeEvent(QResizeEvent * event = 0);
    vector<Note> recupPartition();


private :
    QVBoxLayout * layout;
    QString cheminPartition;

    vector<QPortee*> portees;
    int porteeActuelle;

    vector<Note> partition;
    int noteActuelle;

signals:
    void fini(vector<Note> partition);

public slots:
    void updatePortees(QString cheminPartition = 0);
    void checkNote(Note n);
};

#endif // QPAGEPARTITION_H
