#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QTimer> 
#include <QDateTime>
#include <QCoreApplication>
#include <stdlib.h>
#include "log.h"

class Alarm : public QObject
{  
  Q_OBJECT     
    public:
        Alarm(QObject* = 0); 
        void startAlarm();
        void stopAlarm();   
        void setYear(int);
        void setMonth(int);
        void setDay(int); 
        void setHours(int);
        void setMinutes(int);
        void setSeconds(int);
        void setAlarm();
        void init(QString);
        int getTimeLeft();
        bool isActive();
    
    private:    
        int year;
        int month;
        int day;
        int hours;
        int minutes;
        int seconds;
        int timeToAlarm;
        int timeLeft;
        QTimer *timer;   
        Log *pLog;    
        QString path;
        
    private slots:
        void checkTimer();
        void finishAalarm();
        void printMassage();
        
    signals:
        void itsTime();
        void wrongTime();
		void salatTimeLeft();
    
};

#endif
