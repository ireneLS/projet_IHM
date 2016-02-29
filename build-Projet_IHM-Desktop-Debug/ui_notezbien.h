/********************************************************************************
** Form generated from reading UI file 'notezbien.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEZBIEN_H
#define UI_NOTEZBIEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotezBien
{
public:

    void setupUi(QWidget *NotezBien)
    {
        if (NotezBien->objectName().isEmpty())
            NotezBien->setObjectName(QString::fromUtf8("NotezBien"));
        NotezBien->resize(400, 300);

        retranslateUi(NotezBien);

        QMetaObject::connectSlotsByName(NotezBien);
    } // setupUi

    void retranslateUi(QWidget *NotezBien)
    {
        NotezBien->setWindowTitle(QApplication::translate("NotezBien", "NotezBien", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NotezBien: public Ui_NotezBien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEZBIEN_H
