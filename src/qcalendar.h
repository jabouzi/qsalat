/****************************************************************************
** Qsalat project V1.0
** calendar.h
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

#ifndef __QCALENDAR_H__
#define __QCALENDAR_H__

#include <QtGui>
#include <QString>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include "ui_calendar.h"
#include "qpray.h"
#include "log.h"

class Qcalendar : public QDialog, public Ui::Calendar
{
Q_OBJECT
public:
    Qcalendar( QWidget * parent = 0, Qt::WFlags f = 0 );
    void init();
    void setLatitude(double);
    void setLongitude(double);
    void setTimezone(int);
    void setCalculationMethod(int);
    void setAsrMethod(int);
    void setPath(QString);    
    
    
protected:
    void closeEvent(QCloseEvent *);
    
private slots:
    void generate();
    void selectAll();
    void unselectAll();
        
private:
    void setUI();
    void setActions();
    void setMonths();
    QDate date;
    Qpray *prayers;
    QString file;
    int calcMethod;
    int asrMethod;
    double latitude;
    double longitude;
    int timezone; 
    QString path;
    QList<int> monthNumber;
    QList<int> days;
    QStringList months;
    QString *salatTimes;
    Log *pLog;
};


#endif // __QCALENDAR_H__
