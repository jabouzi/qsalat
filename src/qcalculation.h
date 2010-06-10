/****************************************************************************
** Qsalat project V1.0
** qcalculation.h
**
** Copyright (C) 2008 - 2010 Skander Jabouzi (Skander Software Solutions).
** Contact: skander@skanderjabouzi.com
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

#ifndef __CALCULATION_H__
#define __CALCULATION_H__

#include <QtGui>
#include <QString>
#include "ui_calculation.h"
#include "database.h"


class Qcalculation : public QDialog, public Ui::Calculation
{
Q_OBJECT
public:
    Qcalculation( QWidget * parent = 0, Qt::WFlags f = 0 );    
    void init();
    void setCalcMethod(int);
    void setAsrMethod(int);
    //void setDuhrMinutes(int);
    //void setFajrMinutes(int);
    void setPath(QString);
    
protected:
    void closeEvent(QCloseEvent *);
    
private slots:    
    void save();
    void cancel();
    void apply();
    
private:    
    QString file;
    QStringList list;    
    QStringList hList;
    QString path;
    QDate date;
    QString *times;
    int calcMethod;
    int asrMethod;
    //int duhrMinutes;
    //int asrMinutes;
    Database *db;
    
    void initDB();
    void setUI();     
    void setActions();
    int calcTime(QString,QString);
    int getDuhrMinutes();
    int setDuhrMinutes();
    int getAsrDiff(int,QString,QString);
    
signals:
    void calculationChanged();
};

#endif // __CALCULATION_H__
