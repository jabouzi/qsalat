/********************************************************************************
** Form generated from reading UI file 'qibla.ui'
**
** Created: Fri Apr 23 09:03:27 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIBLA_H
#define UI_QIBLA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Qibla
{
public:
    QLabel *label;

    void setupUi(QDialog *Qibla)
    {
        if (Qibla->objectName().isEmpty())
            Qibla->setObjectName(QString::fromUtf8("Qibla"));
        Qibla->resize(300, 400);
        Qibla->setMinimumSize(QSize(300, 400));
        Qibla->setMaximumSize(QSize(300, 400));
        Qibla->setStyleSheet(QString::fromUtf8("background-image: url(/usr/share/qsalat/images/boussole.png);\n"
""));
        label = new QLabel(Qibla);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 7, 281, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Qibla);

        QMetaObject::connectSlotsByName(Qibla);
    } // setupUi

    void retranslateUi(QDialog *Qibla)
    {
        Qibla->setWindowTitle(QApplication::translate("Qibla", "Qsalat - qibla direction", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Qibla", "Qibla angle direction : 57,6N", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Qibla: public Ui_Qibla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIBLA_H
