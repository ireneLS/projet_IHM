#ifndef NOTEZBIEN_H
#define NOTEZBIEN_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QPoint>

namespace Ui {
class NotezBien;
}

class NotezBien : public QWidget
{
    Q_OBJECT

public:
    explicit NotezBien(QWidget *parent = 0);
    ~NotezBien();
    void paintEvent(QPaintEvent * event);
    void dessineNote(QPainter* painter, int hauteur);

private:
    Ui::NotezBien *ui;
};

#endif // NOTEZBIEN_H
