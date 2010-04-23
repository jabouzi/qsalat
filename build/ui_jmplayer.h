/********************************************************************************
** Form generated from reading UI file 'jmplayer.ui'
**
** Created: Sun Jan 3 20:55:55 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JMPLAYER_H
#define UI_JMPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jmplayer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *timePlay;
    QSlider *timeSlider;
    QLabel *totalTime;
    QPushButton *prev_button;
    QPushButton *play_button;
    QPushButton *next_button;
    QSpacerItem *horizontalSpacer;
    QSlider *volumeSlider;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Jmplayer)
    {
        if (Jmplayer->objectName().isEmpty())
            Jmplayer->setObjectName(QString::fromUtf8("Jmplayer"));
        Jmplayer->resize(294, 272);
        centralwidget = new QWidget(Jmplayer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 65);"));

        gridLayout->addWidget(widget, 0, 0, 1, 7);

        timePlay = new QLabel(centralwidget);
        timePlay->setObjectName(QString::fromUtf8("timePlay"));

        gridLayout->addWidget(timePlay, 1, 0, 1, 2);

        timeSlider = new QSlider(centralwidget);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(timeSlider, 1, 2, 1, 4);

        totalTime = new QLabel(centralwidget);
        totalTime->setObjectName(QString::fromUtf8("totalTime"));

        gridLayout->addWidget(totalTime, 1, 6, 1, 1);

        prev_button = new QPushButton(centralwidget);
        prev_button->setObjectName(QString::fromUtf8("prev_button"));

        gridLayout->addWidget(prev_button, 2, 0, 1, 1);

        play_button = new QPushButton(centralwidget);
        play_button->setObjectName(QString::fromUtf8("play_button"));

        gridLayout->addWidget(play_button, 2, 1, 1, 2);

        next_button = new QPushButton(centralwidget);
        next_button->setObjectName(QString::fromUtf8("next_button"));

        gridLayout->addWidget(next_button, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(159, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 4, 1, 1);

        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeSlider, 2, 5, 1, 2);

        Jmplayer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Jmplayer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 294, 24));
        Jmplayer->setMenuBar(menubar);

        retranslateUi(Jmplayer);

        QMetaObject::connectSlotsByName(Jmplayer);
    } // setupUi

    void retranslateUi(QMainWindow *Jmplayer)
    {
        Jmplayer->setWindowTitle(QApplication::translate("Jmplayer", "MainWindow", 0, QApplication::UnicodeUTF8));
        timePlay->setText(QApplication::translate("Jmplayer", "00:00:00", 0, QApplication::UnicodeUTF8));
        totalTime->setText(QApplication::translate("Jmplayer", "00:00:00", 0, QApplication::UnicodeUTF8));
        prev_button->setText(QString());
        play_button->setText(QString());
        next_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Jmplayer: public Ui_Jmplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JMPLAYER_H
