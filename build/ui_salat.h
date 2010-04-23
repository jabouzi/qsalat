/********************************************************************************
** Form generated from reading UI file 'salat.ui'
**
** Created: Tue Jan 5 22:47:34 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALAT_H
#define UI_SALAT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Salat
{
public:
    QAction *actionHide;
    QAction *actionQuit;
    QAction *actionHijri_date;
    QAction *actionQibla_direction;
    QAction *actionLocation;
    QAction *actionAudio;
    QAction *actionCustom_option;
    QAction *actionWorld_time;
    QAction *actionAbout_Qsalat;
    QAction *actionAbout_QT;
    QAction *actionCalculation_options;
    QAction *actionWorldtime;
    QAction *actionGenerate_monthly_prayer_times;
    QAction *actionGenerate_yearly_prayer_times;
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label_fajr;
    QLabel *label_asr;
    QLabel *label_isha;
    QLabel *label_duhr;
    QLabel *label_maghreb;
    QLabel *label_location;
    QLabel *label_hijri;
    QLabel *label_hijri_2;
    QLabel *label_shourouk;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuPrayer_times_options;
    QMenu *menuExtra;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Salat)
    {
        if (Salat->objectName().isEmpty())
            Salat->setObjectName(QString::fromUtf8("Salat"));
        Salat->resize(300, 487);
        Salat->setMinimumSize(QSize(300, 487));
        Salat->setMaximumSize(QSize(300, 487));
        Salat->setStyleSheet(QString::fromUtf8(""));
        actionHide = new QAction(Salat);
        actionHide->setObjectName(QString::fromUtf8("actionHide"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/usr/share/qsalat/images/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHide->setIcon(icon);
        actionQuit = new QAction(Salat);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/usr/share/qsalat/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionHijri_date = new QAction(Salat);
        actionHijri_date->setObjectName(QString::fromUtf8("actionHijri_date"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/usr/share/qsalat/images/hijri.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHijri_date->setIcon(icon2);
        actionQibla_direction = new QAction(Salat);
        actionQibla_direction->setObjectName(QString::fromUtf8("actionQibla_direction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/usr/share/qsalat/images/qibla.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQibla_direction->setIcon(icon3);
        actionLocation = new QAction(Salat);
        actionLocation->setObjectName(QString::fromUtf8("actionLocation"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/usr/share/qsalat/images/world.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLocation->setIcon(icon4);
        actionAudio = new QAction(Salat);
        actionAudio->setObjectName(QString::fromUtf8("actionAudio"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/usr/share/qsalat/images/mp3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAudio->setIcon(icon5);
        actionCustom_option = new QAction(Salat);
        actionCustom_option->setObjectName(QString::fromUtf8("actionCustom_option"));
        actionWorld_time = new QAction(Salat);
        actionWorld_time->setObjectName(QString::fromUtf8("actionWorld_time"));
        actionAbout_Qsalat = new QAction(Salat);
        actionAbout_Qsalat->setObjectName(QString::fromUtf8("actionAbout_Qsalat"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/usr/share/qsalat/images/mecque.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qsalat->setIcon(icon6);
        actionAbout_QT = new QAction(Salat);
        actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/usr/share/qsalat/images/Qt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_QT->setIcon(icon7);
        actionCalculation_options = new QAction(Salat);
        actionCalculation_options->setObjectName(QString::fromUtf8("actionCalculation_options"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/usr/share/qsalat/images/0396.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalculation_options->setIcon(icon8);
        actionWorldtime = new QAction(Salat);
        actionWorldtime->setObjectName(QString::fromUtf8("actionWorldtime"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/usr/share/qsalat/images/0442.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWorldtime->setIcon(icon9);
        actionGenerate_monthly_prayer_times = new QAction(Salat);
        actionGenerate_monthly_prayer_times->setObjectName(QString::fromUtf8("actionGenerate_monthly_prayer_times"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/usr/share/qsalat/images/month.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGenerate_monthly_prayer_times->setIcon(icon10);
        actionGenerate_yearly_prayer_times = new QAction(Salat);
        actionGenerate_yearly_prayer_times->setObjectName(QString::fromUtf8("actionGenerate_yearly_prayer_times"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/usr/share/qsalat/images/year.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGenerate_yearly_prayer_times->setIcon(icon11);
        centralwidget = new QWidget(Salat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 300, 400));
        widget->setStyleSheet(QString::fromUtf8("background-image: url(:/usr/share/qsalat/images/qsalat.png);"));
        label_fajr = new QLabel(widget);
        label_fajr->setObjectName(QString::fromUtf8("label_fajr"));
        label_fajr->setGeometry(QRect(110, 100, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        label_fajr->setFont(font);
        label_fajr->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
        label_fajr->setAlignment(Qt::AlignCenter);
        label_asr = new QLabel(widget);
        label_asr->setObjectName(QString::fromUtf8("label_asr"));
        label_asr->setGeometry(QRect(110, 190, 101, 41));
        label_asr->setFont(font);
        label_asr->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
        label_asr->setAlignment(Qt::AlignCenter);
        label_isha = new QLabel(widget);
        label_isha->setObjectName(QString::fromUtf8("label_isha"));
        label_isha->setGeometry(QRect(110, 280, 101, 41));
        label_isha->setFont(font);
        label_isha->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
        label_isha->setAlignment(Qt::AlignCenter);
        label_duhr = new QLabel(widget);
        label_duhr->setObjectName(QString::fromUtf8("label_duhr"));
        label_duhr->setGeometry(QRect(110, 145, 101, 41));
        label_duhr->setFont(font);
        label_duhr->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
        label_duhr->setAlignment(Qt::AlignCenter);
        label_maghreb = new QLabel(widget);
        label_maghreb->setObjectName(QString::fromUtf8("label_maghreb"));
        label_maghreb->setGeometry(QRect(110, 235, 101, 41));
        label_maghreb->setFont(font);
        label_maghreb->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
        label_maghreb->setAlignment(Qt::AlignCenter);
        label_location = new QLabel(widget);
        label_location->setObjectName(QString::fromUtf8("label_location"));
        label_location->setGeometry(QRect(20, 340, 261, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        label_location->setFont(font1);
        label_location->setStyleSheet(QString::fromUtf8("background-image: url(:/images/slider3.png);\n"
"color:white;"));
        label_location->setAlignment(Qt::AlignCenter);
        label_hijri = new QLabel(widget);
        label_hijri->setObjectName(QString::fromUtf8("label_hijri"));
        label_hijri->setGeometry(QRect(120, 40, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_hijri->setFont(font2);
        label_hijri->setLayoutDirection(Qt::RightToLeft);
        label_hijri->setStyleSheet(QString::fromUtf8("background-image: url(:/images/slider3.png);\n"
"color:white;\n"
""));
        label_hijri->setLocale(QLocale(QLocale::Arabic, QLocale::SaudiArabia));
        label_hijri->setAlignment(Qt::AlignCenter);
        label_hijri_2 = new QLabel(widget);
        label_hijri_2->setObjectName(QString::fromUtf8("label_hijri_2"));
        label_hijri_2->setGeometry(QRect(110, 10, 181, 31));
        label_hijri_2->setFont(font2);
        label_hijri_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/slider3.png);\n"
"color:white;\n"
""));
        label_hijri_2->setAlignment(Qt::AlignCenter);
        label_shourouk = new QLabel(widget);
        label_shourouk->setObjectName(QString::fromUtf8("label_shourouk"));
        label_shourouk->setGeometry(QRect(130, 330, 62, 17));
        label_shourouk->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
        label_shourouk->setAlignment(Qt::AlignCenter);
        Salat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Salat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuPrayer_times_options = new QMenu(menuTools);
        menuPrayer_times_options->setObjectName(QString::fromUtf8("menuPrayer_times_options"));
        menuExtra = new QMenu(menubar);
        menuExtra->setObjectName(QString::fromUtf8("menuExtra"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        Salat->setMenuBar(menubar);
        statusbar = new QStatusBar(Salat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Salat->setStatusBar(statusbar);
        toolBar = new QToolBar(Salat);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(false);
        Salat->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuExtra->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionHide);
        menuFile->addAction(actionQuit);
        menuTools->addSeparator();
        menuTools->addAction(actionHijri_date);
        menuTools->addAction(actionQibla_direction);
        menuTools->addAction(actionLocation);
        menuTools->addAction(actionAudio);
        menuTools->addAction(actionCalculation_options);
        menuTools->addAction(menuPrayer_times_options->menuAction());
        menuPrayer_times_options->addAction(actionGenerate_monthly_prayer_times);
        menuPrayer_times_options->addAction(actionGenerate_yearly_prayer_times);
        menuExtra->addAction(actionWorldtime);
        menuAbout->addSeparator();
        menuAbout->addAction(actionAbout_Qsalat);
        menuAbout->addAction(actionAbout_QT);
        toolBar->addAction(actionLocation);
        toolBar->addAction(actionCalculation_options);
        toolBar->addAction(actionQibla_direction);
        toolBar->addAction(actionAudio);
        toolBar->addAction(actionHijri_date);
        toolBar->addAction(actionGenerate_monthly_prayer_times);
        toolBar->addAction(actionGenerate_yearly_prayer_times);
        toolBar->addAction(actionWorldtime);

        retranslateUi(Salat);

        QMetaObject::connectSlotsByName(Salat);
    } // setupUi

    void retranslateUi(QMainWindow *Salat)
    {
        Salat->setWindowTitle(QApplication::translate("Salat", "Qsalat - salat times", 0, QApplication::UnicodeUTF8));
        actionHide->setText(QApplication::translate("Salat", "Hide", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("Salat", "Quit", 0, QApplication::UnicodeUTF8));
        actionHijri_date->setText(QApplication::translate("Salat", "Hijri date conversion", 0, QApplication::UnicodeUTF8));
        actionQibla_direction->setText(QApplication::translate("Salat", "Qibla direction", 0, QApplication::UnicodeUTF8));
        actionLocation->setText(QApplication::translate("Salat", "Location", 0, QApplication::UnicodeUTF8));
        actionAudio->setText(QApplication::translate("Salat", "Audio", 0, QApplication::UnicodeUTF8));
        actionCustom_option->setText(QApplication::translate("Salat", "Custom option", 0, QApplication::UnicodeUTF8));
        actionWorld_time->setText(QApplication::translate("Salat", "World time", 0, QApplication::UnicodeUTF8));
        actionAbout_Qsalat->setText(QApplication::translate("Salat", "About Qsalat", 0, QApplication::UnicodeUTF8));
        actionAbout_QT->setText(QApplication::translate("Salat", "About QT", 0, QApplication::UnicodeUTF8));
        actionCalculation_options->setText(QApplication::translate("Salat", "Calculation options", 0, QApplication::UnicodeUTF8));
        actionWorldtime->setText(QApplication::translate("Salat", "World time", 0, QApplication::UnicodeUTF8));
        actionGenerate_monthly_prayer_times->setText(QApplication::translate("Salat", "Generate monthly prayer times", 0, QApplication::UnicodeUTF8));
        actionGenerate_yearly_prayer_times->setText(QApplication::translate("Salat", "Generate yearly prayer times", 0, QApplication::UnicodeUTF8));
        label_fajr->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
        label_asr->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
        label_isha->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
        label_duhr->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
        label_maghreb->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
        label_location->setText(QApplication::translate("Salat", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_hijri->setText(QApplication::translate("Salat", "00  \330\254\331\205\330\247\330\257\331\211 \330\247\331\204\330\242\330\256\330\261\330\251  0000", 0, QApplication::UnicodeUTF8));
        label_hijri_2->setText(QApplication::translate("Salat", "00 Jumada al-Thani 0000", 0, QApplication::UnicodeUTF8));
        label_shourouk->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("Salat", "File", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("Salat", "Tools", 0, QApplication::UnicodeUTF8));
        menuPrayer_times_options->setTitle(QApplication::translate("Salat", "Prayer times options", 0, QApplication::UnicodeUTF8));
        menuExtra->setTitle(QApplication::translate("Salat", "Extra", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("Salat", "About", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Salat", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Salat: public Ui_Salat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALAT_H
