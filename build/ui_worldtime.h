/********************************************************************************
** Form generated from reading UI file 'worldtime.ui'
**
** Created: Tue Jan 5 22:39:36 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORLDTIME_H
#define UI_WORLDTIME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WorldTime
{
public:
    QLabel *label;

    void setupUi(QDialog *WorldTime)
    {
        if (WorldTime->objectName().isEmpty())
            WorldTime->setObjectName(QString::fromUtf8("WorldTime"));
        WorldTime->resize(640, 320);
        WorldTime->setMinimumSize(QSize(640, 320));
        WorldTime->setMaximumSize(QSize(640, 320));
        WorldTime->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(WorldTime);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 640, 320));
        label->setMinimumSize(QSize(640, 320));
        label->setMaximumSize(QSize(640, 320));

        retranslateUi(WorldTime);

        QMetaObject::connectSlotsByName(WorldTime);
    } // setupUi

    void retranslateUi(QDialog *WorldTime)
    {
        WorldTime->setWindowTitle(QApplication::translate("WorldTime", "Qsalat - world time", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WorldTime: public Ui_WorldTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORLDTIME_H
