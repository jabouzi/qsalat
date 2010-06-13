/****************************************************************************
** Qsalat project V1.0
** qcalculation.cpp
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

#include "qcalculation.h"
#include "qpray.h"

//
Qcalculation::Qcalculation( QWidget * parent, Qt::WFlags f) 
    : QDialog(parent, f)
{
    setupUi(this);          
    setActions();
    date = QDate::currentDate();
    times = new QString[7]; 
}

void Qcalculation::setPath(QString lpath)
{
    path = lpath;
    setUI();  
}

void Qcalculation::initDB()
{
    db = Database::getInstance();
    db->setDatabaseName(path+"data/qsalat.db");
    db->setDatabase();   
    db->setTable("calculation");
}

void Qcalculation::setCalcMethod(int method)
{    
    calcMethod = method;
}

void Qcalculation::setAsrMethod(int method)
{
    asrMethod = method;
}

void Qcalculation::setHijriDays(int hijri)
{
    hijriDays = hijri;
}

//
void Qcalculation::closeEvent(QCloseEvent *event)
{
    hide();
    init();
    event->ignore();
}

//
void Qcalculation::init()
{    
    initDB();
    QString temp = "";     
    list << "Ithna Ashari"<<"University of Islamic Sciences, Karachi"<<"Islamic Society of North America (ISNA)"
        <<"Muslim World League (MWL)"<<"Umm al-Qura, Makkah"<<"Egyptian General Authority of Survey"<<"Institute of Geophysics, University of Tehran";
    calcList->addItems(list);
    calcList->setCurrentIndex(calcMethod);
    hList << "No adjustment"<<"middle of night"<<"1/7th of night"<<"angle/60th of night";
    highList->addItems(hList);

    if (asrMethod == 0) shafiiButton->setChecked(true);
    else hanafiButton->setChecked(true);
    hijriBox->setValue(hijriDays);   
}

//
void Qcalculation::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

//
void Qcalculation::setActions(){   
    connect(saveButton,SIGNAL(clicked()),this,SLOT(save()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));   
}

//
void Qcalculation::apply()
{
    int asrChecked = 0;
    if (hanafiButton->isChecked()) asrChecked = 1;
    calcMethod = calcList->currentIndex();
    asrMethod = asrChecked;
    db->setTable("calculation");   
    db->update("method",QString::number(calcList->currentIndex()));
    db->update("asr",QString::number(asrChecked));    
    db->update("hijri",QString::number(hijriBox->value()));    
    emit(calculationChanged());
}

//
void Qcalculation::save()
{
    apply();    
    close();
}

//
void Qcalculation::cancel()
{
    close();
}
