/****************************************************************************
** Qsalat project V1.0
** qsalat.h
**
** Copyright (C) 2008 Skander Jabouzi (Skander Software Solutions).
** Contact: skander@skanderjabouzi.com or jabouzi@gmail.com
**
** This file is part of the Qsalat open source software.
**
** GNU General Public License Usage
** This file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
***************************************************************************/

#ifndef QSALAT_H
#define QSALAT_H
//
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QProcess>
#include <QPaintEvent>
#include "ui_salat.h"
#include "qpray.h"
#include "qhijri.h"
#include "qlocation.h"
#include "qqibla.h"
#include "qaudio.h"
#include "qcalculation.h"
#include "qworldTime.h"
#include "qhijridate.h"
#include "qcalendar.h"
#include "alarm.h"
#include "database.h"
#include "player.h"
#include "log.h"

//
class Qsalat : public QMainWindow, public Ui::Salat
{
Q_OBJECT
public:
    Qsalat( QWidget * parent = 0, Qt::WFlags f = 0 );
    ~Qsalat();
    
private:    
    // private members
    Alarm * alarm; 
    QString timeOfSalat;
    Qhijri *hijri;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QString *salatTimes;
    int year;
    int month;
    int day;
    double latitude;
    double longitude;
    int timezone;
    int timezone_dst;
    QString country;
    QString city;        
    Qlocation location;
    Qqibla qibla;
    QDate date;
    Qaudio audio;
    Qcalculation calculation;
    Qworldtime worldtime;
    Qcalendar calendar;
    Qhijridate hijridate; 
    Player player;
    QString file;    
    int timer;    
    QString prayerAudio;
    QString fajrAudio;
    QString duaAudio;
    int playAthan;
    int playDua;
    int calcMethod;
    int fajrMinutes;
    int duhrMinutes;
    int asrMethod;
    int hijriDays;
    int highlatitude;
    QString path;    
    QStringList audioList;
    Database *db;
    Log *pLog;
    
    // private methods
    void init();
    void checkData();
    void initLocation();
    void initAudio();
    void initCalculation();
    void adjustWindow();    
    void getSalats();
    void getHijri();
    void createTrayIcon();
    void setVisible(bool);    
    void closeEvent(QCloseEvent *);
    void createActions();
    void setPlayer(QStringList,QString);
    QString getNextSalat();
    void startSalatAlarm();   
    int getFajr();
    int getDuhr();
    int getAsr();
    int getMaghrib();
    int getIsha();
    int getMidNight(); 
    int salatOrder;
    QString salatTitle;
    void initDB();
    void initLocationObject();
    void initCalculationObject();
    void initAudioObject();
    void initQiblaObject();
    void initHijriDateObject();
    void initCalendarObject();
    QString seconds_to_DHMS(quint32);
    
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason);
    void showLocation();
    void showQibla();
    void showAudio();
    void showCalculation();
    void showWorldtime();
    void showCalendar();
    void showTimeLeft();
    void showHijridate();
    void _about();
    void _hide();
    void _showNormal();
    void itsSalatTime();
    void updateCalculation();
    void updateLocation();
    void updateAudio();
    void restartSalat();
    void _quit();
};
#endif




