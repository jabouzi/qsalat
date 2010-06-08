/****************************************************************************
** Qsalat project V1.0
** qcalendar.cpp
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

#include "qcalendar.h"

//
Qcalendar::Qcalendar( QWidget * parent, Qt::WFlags f) 
    : QDialog(parent, f)
{
    pLog = new Log("calendar.log");
    setupUi(this);    
    setUI();
    date = QDate::currentDate();
    prayers = new Qpray();
    //init();
    //setMonths();
    setActions();
}

//
void Qcalendar::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

//
void Qcalendar::init()
{
    setUI();        
}

void Qcalendar::setLatitude(double latitude_)
{
    latitude = latitude_;
}

void Qcalendar::setLongitude(double longitude_)
{
    longitude = longitude_;
}

void Qcalendar::setTimezone(int timezone_)
{
    timezone = timezone_;
}

void Qcalendar::setCalculationMethod(int calcMethod_)
{
    calcMethod = calcMethod_;
}

void Qcalendar::setAsrMethod(int asrMethod_)
{
    asrMethod = asrMethod_;
}

void Qcalendar::setPath(QString path_)
{
    path = path_;
} 

//
void Qcalendar::setActions()
{
    connect(generateButton, SIGNAL(clicked()), this, SLOT(generate()));
    connect(selectButton, SIGNAL(clicked()), this, SLOT(selectAll()));
    connect(unselectButton, SIGNAL(clicked()), this, SLOT(unselectAll()));
}

//
void Qcalendar::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    generateButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    selectButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
    unselectButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

//
void Qcalendar::setMonths()
{
    int i = 0;
    months.clear();
    monthNumber.clear();
    days.clear();
    if (checkBox_01->isChecked()) 
    {
        months << "January";
        monthNumber << 1;
        days << 31;
        i++;
    }
    if (checkBox_02->isChecked()) 
    {
        months << "February";
        monthNumber << 2;
        if (QDate::isLeapYear ( date.year() )) days << 29;
        else days << 28;        
        i++;
    }
    if (checkBox_03->isChecked()) 
    {
        months << "March";
        monthNumber << 3;
        days << 31;
        i++;
    }
    if (checkBox_04->isChecked()) 
    {
        months << "April";
        monthNumber << 4;
        days << 30;
        i++;
    }
    if (checkBox_05->isChecked()) 
    {
        months << "May";
        monthNumber << 5;
        days << 31;
        i++;
    }
    if (checkBox_06->isChecked()) 
    {
        months << "June";
        monthNumber << 6;
        days << 30;
        i++;
    }
    if (checkBox_07->isChecked()) 
    {
        months << "July";
        monthNumber << 7;
        days << 31;
        i++;
    }
    if (checkBox_08->isChecked()) 
    {
        months << "August";
        monthNumber << 8;
        days << 31;
        i++;
    }
    if (checkBox_09->isChecked()) 
    {
        months << "September";
        monthNumber << 9;
        days << 30;
        i++;
    }
    if (checkBox_10->isChecked()) 
    {
        months << "Obctober";
        monthNumber << 10;
        days << 31;
        i++;
    }
    if (checkBox_11->isChecked()) 
    {
        months << "November";
        monthNumber << 11;
        days << 30;
        i++;
    }
    if (checkBox_12->isChecked()) 
    {
        months << "December";
        monthNumber << 12;
        days << 30;
        i++;
    }
}

//generate calendar prayer times
void Qcalendar::generate()
{
    setMonths();
    pLog->Write(QString::number(latitude));
    pLog->Write(QString::number(longitude));
    pLog->Write(QString::number(timezone));
    pLog->Write(" ");    
    pLog->Write(" ");    
    for (int i = 0; i < months.size(); i++)
    {
        pLog->Write(months.at(i));
        int index[] = {0,2,3,5,6};
        for (int j = 1; j <= days.at(i); j++){
            pLog->Write(QString::number(j));
            salatTimes = prayers->getDatePrayerTimes(date.year(),monthNumber.at(i),j,latitude,longitude,timezone);
            for (int k = 0; k < 5; k++){
                pLog->Write(salatTimes[index[k]]);
            }
        }    
        pLog->Write(" ");    
    }
}

void Qcalendar::selectAll()
{    
    checkBox_01->setChecked(true);
    checkBox_02->setChecked(true);
    checkBox_03->setChecked(true);
    checkBox_04->setChecked(true);
    checkBox_05->setChecked(true);
    checkBox_06->setChecked(true);
    checkBox_07->setChecked(true);
    checkBox_08->setChecked(true);
    checkBox_09->setChecked(true);
    checkBox_10->setChecked(true);
    checkBox_11->setChecked(true);
    checkBox_12->setChecked(true);
}

void Qcalendar::unselectAll()
{     
    checkBox_01->setChecked(false);
    checkBox_02->setChecked(false);
    checkBox_03->setChecked(false);
    checkBox_04->setChecked(false);
    checkBox_05->setChecked(false);
    checkBox_06->setChecked(false);
    checkBox_07->setChecked(false);
    checkBox_08->setChecked(false);
    checkBox_09->setChecked(false);
    checkBox_10->setChecked(false);
    checkBox_11->setChecked(false);
    checkBox_12->setChecked(false);
}
