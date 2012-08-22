#include <QtGui>
#include "alarm.h" 

Alarm::Alarm(QObject* parent) :
    QObject(parent)
{
    
}

void Alarm::init(QString path_)
{    
	path = path_;
	pLog = new Log(path+"errors.log");
	qDebug() << path;
    QDateTime today = QDateTime::currentDateTime();
    year = today.date().year();
    month = today.date().month();
    day = today.date().day();
    hours = 0;
    minutes = 0;
    seconds = 0;
    timeToAlarm = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(finishAalarm()));
}

void Alarm::setAlarm()
{
    //stopAlarm();
    //if (timer->isActive()) //pLog->Write("is active");
    //else //pLog->Write("not active");
    if (getTimeLeft() > 0)
    {
        //qDebug("There are %d seconds to alarm", now.secsTo(alarmTime));
        //pLog->Write("There are "+QString::number(now.secsTo(alarmTime))+" seconds to alarm");
        timeToAlarm = timeLeft*1000;
        pLog->Write("There are "+QString::number(timeToAlarm)+" seconds to alarm");
        startAlarm();
    }
    else
    {
        //qDebug("There are %d seconds passed", abs(now.secsTo(alarmTime)));
        pLog->Write("There are "+QString::number(timeToAlarm)+" seconds passed");
        stopAlarm();
    }
}

void Alarm::startAlarm()
{
    if (timer->isActive()) 
    {
        pLog->Write("Alarm is active");
        //timer->stop();
    }
    else 
    {   
        pLog->Write("Alarm not active");
        timer->start(60000);
        //pLog->Write("Timer ID : "+QString::number(timer->timerId()));
    }
}

void Alarm::stopAlarm()
{
    //pLog->Write("Timerz ID : "+QString::number(timer->timerId()));
    timer->stop();
    //pLog->Write("Timerz ID : "+QString::number(timer->timerId()));
    //pLog->Write("Alarm stopped");
}

void Alarm::setYear(int year_)
{
    year = year_;
}

void Alarm::setMonth(int month_)
{
    month = month_;
}

void Alarm::setDay(int day_)
{
    day = day_;
}

void Alarm::setHours(int hours_)
{
    hours = hours_;
}

void Alarm::setMinutes(int minutes_)
{
    minutes = minutes_;
}

void Alarm::setSeconds(int seconds_)
{
    seconds = seconds_;
}

void Alarm::checkTimer()
{

}

void Alarm::finishAalarm()
{
    int error = 0;
    QDateTime now = QDateTime::currentDateTime();
    if (now.date().year() != year) error++;
    if (now.date().month() != month) error++;
    if (now.date().day() != day) error++;
    if (now.time().hour() != hours) error++;
    if (now.time().minute() != minutes) error++;
    qDebug() << error;
    if (error == 0)
    {
        pLog->Write("Time left : " + QString::number(getTimeLeft()));
        pLog->Write("Time is ok");
        emit(itsTime());
        timer->stop();
    }
    else
    {
        if (getTimeLeft() < 0)
        {
            pLog->Write("Wrong time");
            emit(wrongTime());
        }
    }
}

void Alarm::printMassage()
{
    qDebug("Alarm finished");
}

int Alarm::getTimeLeft()
{
    QDateTime now = QDateTime::currentDateTime();
    QDateTime alarmTime(QDate(year, month, day), QTime(hours, minutes, seconds));
    timeLeft = now.secsTo(alarmTime);
    return timeLeft;
}

bool Alarm::isActive()
{
    return timer->isActive();
}
