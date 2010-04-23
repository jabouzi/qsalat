/********************************************************************************
** Form generated from reading UI file 'hijri.ui'
**
** Created: Fri Apr 23 09:03:27 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIJRI_H
#define UI_HIJRI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Hijri
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *hmonthBox;
    QSpinBox *hyearBox;
    QGroupBox *groupBox_2;
    QComboBox *jmonthBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *jyearBox;
    QPushButton *convertButton;
    QGroupBox *groupBox_3;
    QRadioButton *hijriButton;
    QRadioButton *georgianButton;
    QLabel *label_7;
    QSpinBox *hdayBox;
    QSpinBox *jdayBox;

    void setupUi(QDialog *Hijri)
    {
        if (Hijri->objectName().isEmpty())
            Hijri->setObjectName(QString::fromUtf8("Hijri"));
        Hijri->resize(300, 411);
        Hijri->setMinimumSize(QSize(300, 411));
        Hijri->setMaximumSize(QSize(300, 411));
        groupBox = new QGroupBox(Hijri);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 281, 111));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 54, 18));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 30, 54, 18));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 54, 18));
        hmonthBox = new QComboBox(groupBox);
        hmonthBox->setObjectName(QString::fromUtf8("hmonthBox"));
        hmonthBox->setEnabled(true);
        hmonthBox->setGeometry(QRect(94, 60, 111, 27));
        hyearBox = new QSpinBox(groupBox);
        hyearBox->setObjectName(QString::fromUtf8("hyearBox"));
        hyearBox->setGeometry(QRect(10, 60, 71, 28));
        hyearBox->setMinimum(0);
        hyearBox->setMaximum(3000);
        groupBox_2 = new QGroupBox(Hijri);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 150, 281, 111));
        jmonthBox = new QComboBox(groupBox_2);
        jmonthBox->setObjectName(QString::fromUtf8("jmonthBox"));
        jmonthBox->setEnabled(false);
        jmonthBox->setGeometry(QRect(94, 60, 111, 27));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 30, 54, 18));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 30, 54, 18));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 30, 54, 18));
        jyearBox = new QSpinBox(groupBox_2);
        jyearBox->setObjectName(QString::fromUtf8("jyearBox"));
        jyearBox->setEnabled(false);
        jyearBox->setGeometry(QRect(10, 60, 71, 28));
        jyearBox->setMinimum(621);
        jyearBox->setMaximum(3000);
        convertButton = new QPushButton(Hijri);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));
        convertButton->setGeometry(QRect(210, 370, 80, 28));
        groupBox_3 = new QGroupBox(Hijri);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 270, 281, 80));
        hijriButton = new QRadioButton(groupBox_3);
        hijriButton->setObjectName(QString::fromUtf8("hijriButton"));
        hijriButton->setGeometry(QRect(20, 30, 111, 24));
        hijriButton->setChecked(true);
        georgianButton = new QRadioButton(groupBox_3);
        georgianButton->setObjectName(QString::fromUtf8("georgianButton"));
        georgianButton->setGeometry(QRect(150, 30, 111, 24));
        georgianButton->setChecked(false);
        label_7 = new QLabel(Hijri);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 281, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        hdayBox = new QSpinBox(Hijri);
        hdayBox->setObjectName(QString::fromUtf8("hdayBox"));
        hdayBox->setGeometry(QRect(230, 90, 51, 28));
        hdayBox->setMinimum(1);
        hdayBox->setMaximum(30);
        jdayBox = new QSpinBox(Hijri);
        jdayBox->setObjectName(QString::fromUtf8("jdayBox"));
        jdayBox->setEnabled(false);
        jdayBox->setGeometry(QRect(230, 210, 51, 28));
        jdayBox->setMinimum(1);
        jdayBox->setMaximum(31);

        retranslateUi(Hijri);

        QMetaObject::connectSlotsByName(Hijri);
    } // setupUi

    void retranslateUi(QDialog *Hijri)
    {
        Hijri->setWindowTitle(QApplication::translate("Hijri", "Qsalat - date conversion", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Hijri", "Hijri", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Hijri", "Day", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Hijri", "Month", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Hijri", "Year", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Hijri", "Georgian", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Hijri", "Year", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Hijri", "Month", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Hijri", "Day", 0, QApplication::UnicodeUTF8));
        convertButton->setText(QApplication::translate("Hijri", "Convert", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Hijri", "Convertion", 0, QApplication::UnicodeUTF8));
        hijriButton->setText(QApplication::translate("Hijri", "Hijri to georgian", 0, QApplication::UnicodeUTF8));
        georgianButton->setText(QApplication::translate("Hijri", "georgian to hijri", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Hijri", "Hijri - georgian date conversion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Hijri: public Ui_Hijri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIJRI_H
