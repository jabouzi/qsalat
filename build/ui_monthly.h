/********************************************************************************
** Form generated from reading UI file 'monthly.ui'
**
** Created: Fri Apr 23 06:45:17 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLY_H
#define UI_MONTHLY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Monthly
{
public:
    QGroupBox *groupBox_2;
    QPushButton *selectButton;
    QLineEdit *pathEdit;
    QLabel *label_4;
    QGroupBox *groupBox;
    QLabel *label_5;
    QLabel *label_2;
    QComboBox *monthBox;
    QSpinBox *yearBox;
    QPushButton *generateButton;
    QLabel *label_7;

    void setupUi(QDialog *Monthly)
    {
        if (Monthly->objectName().isEmpty())
            Monthly->setObjectName(QString::fromUtf8("Monthly"));
        Monthly->resize(352, 305);
        Monthly->setMinimumSize(QSize(352, 305));
        Monthly->setMaximumSize(QSize(352, 305));
        groupBox_2 = new QGroupBox(Monthly);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 331, 80));
        selectButton = new QPushButton(groupBox_2);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(249, 30, 71, 28));
        pathEdit = new QLineEdit(groupBox_2);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setGeometry(QRect(92, 30, 141, 28));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 81, 31));
        groupBox = new QGroupBox(Monthly);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 120, 331, 121));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 70, 91, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 91, 31));
        monthBox = new QComboBox(groupBox);
        monthBox->setObjectName(QString::fromUtf8("monthBox"));
        monthBox->setGeometry(QRect(190, 30, 131, 27));
        yearBox = new QSpinBox(groupBox);
        yearBox->setObjectName(QString::fromUtf8("yearBox"));
        yearBox->setGeometry(QRect(190, 70, 131, 28));
        yearBox->setMinimum(1);
        yearBox->setMaximum(3000);
        yearBox->setValue(2008);
        generateButton = new QPushButton(Monthly);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(260, 260, 80, 28));
        label_7 = new QLabel(Monthly);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 331, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        retranslateUi(Monthly);

        QMetaObject::connectSlotsByName(Monthly);
    } // setupUi

    void retranslateUi(QDialog *Monthly)
    {
        Monthly->setWindowTitle(QApplication::translate("Monthly", "Qsalat - monthly prayers", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Monthly", "Folder", 0, QApplication::UnicodeUTF8));
        selectButton->setText(QApplication::translate("Monthly", "Select", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Monthly", "Select folder", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Monthly", "Monthly generation", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Monthly", "Select a year", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Monthly", "Select a month", 0, QApplication::UnicodeUTF8));
        generateButton->setText(QApplication::translate("Monthly", "Generate", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Monthly", "Generate prayer times for one month", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Monthly: public Ui_Monthly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLY_H
