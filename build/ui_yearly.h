/********************************************************************************
** Form generated from reading UI file 'yearly.ui'
**
** Created: Tue Jan 5 22:39:36 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YEARLY_H
#define UI_YEARLY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Yearly
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QSpinBox *yearBox;
    QPushButton *generateButton;
    QGroupBox *groupBox_2;
    QPushButton *selectButton;
    QLineEdit *pathEdit;
    QLabel *label;
    QLabel *label_7;

    void setupUi(QDialog *Yearly)
    {
        if (Yearly->objectName().isEmpty())
            Yearly->setObjectName(QString::fromUtf8("Yearly"));
        Yearly->resize(352, 266);
        Yearly->setMinimumSize(QSize(352, 266));
        Yearly->setMaximumSize(QSize(352, 400));
        groupBox = new QGroupBox(Yearly);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 120, 331, 81));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 91, 31));
        yearBox = new QSpinBox(groupBox);
        yearBox->setObjectName(QString::fromUtf8("yearBox"));
        yearBox->setGeometry(QRect(190, 30, 131, 28));
        yearBox->setMinimum(1900);
        yearBox->setMaximum(2100);
        yearBox->setValue(2008);
        generateButton = new QPushButton(Yearly);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(260, 220, 80, 28));
        groupBox_2 = new QGroupBox(Yearly);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 331, 80));
        selectButton = new QPushButton(groupBox_2);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(249, 30, 71, 28));
        pathEdit = new QLineEdit(groupBox_2);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setGeometry(QRect(92, 30, 141, 28));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 31));
        label_7 = new QLabel(Yearly);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 331, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        retranslateUi(Yearly);

        QMetaObject::connectSlotsByName(Yearly);
    } // setupUi

    void retranslateUi(QDialog *Yearly)
    {
        Yearly->setWindowTitle(QApplication::translate("Yearly", "Qsalat - yearly prayer times", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Yearly", "Yearly generation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Yearly", "Select a year", 0, QApplication::UnicodeUTF8));
        generateButton->setText(QApplication::translate("Yearly", "Generate", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Yearly", "Folder", 0, QApplication::UnicodeUTF8));
        selectButton->setText(QApplication::translate("Yearly", "Select", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Yearly", "Select folder", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Yearly", "Generate prayer times for one year", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Yearly: public Ui_Yearly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YEARLY_H
