/****************************************************************************
** Qsalat project V1.0
** qlocation.cpp
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

#include "qlocation.h"

//
Qlocation::Qlocation( QWidget * parent, Qt::WFlags f) 
    : QDialog(parent, f)
{
    setupUi(this);    
    manager = new QNetworkAccessManager(this);
    setActions();            
    initDB();
}

void Qlocation::setPath(QString lpath)
{
    path = lpath;
    setUI();
}

void Qlocation::initDB()
{
    db = Database::getInstance();
    db->setDatabaseName("data/qsalat.db");
    db->setDatabase();   
    db->setTable("location");
}

void Qlocation::setLatitude(double latitude_)
{
    latitude = latitude_;
}

void Qlocation::setLongitude(double longitude_)
{
    longitude = longitude_;
}

void Qlocation::setCountry(QString country_)
{
    country = country_;
}

void Qlocation::setCity(QString city_)
{
    city = city_;
}

void Qlocation::setTimezone(int timezone_)
{
    timezone = timezone_;
}

//
void Qlocation::init()
{
    loadCoordinates(latitude,longitude);
    latLineEdit->setText(QString::number(latitude));
    lngLineEdit->setText(QString::number(longitude));
    countryLineEdit->setText(country);
    cityLineEdit->setText(city);
    timezoneLineEdit->setText(QString::number(timezone));
    locationLineEdit->setText("");
}

//search location with webkit and google maps
void Qlocation::loadAddress(QString adr)
{
    QStringList scriptStr;    
    foreach( QPointF point, coordinates ) {
        latLineEdit->setText(QString::number(point.x()));
        lngLineEdit->setText(QString::number(point.y()));
    }   
   scriptStr << QString("http://www.skanderjabouzi.com/qpray/?adr=%1")                        
                             .arg(adr);
    
    QUrl url(scriptStr.join("\n"));
    webView->load(url); 
}

//get geocodes from web service
void Qlocation::loadCoordinates(double lat, double lng)
{
   QStringList scriptStr;   
   scriptStr << QString("http://www.skanderjabouzi.com/qpray/?adr=0&lat=%1&lng=%2")                        
                             .arg(QString::number(lat))
                             .arg(QString::number(lng));
    
    QUrl url(scriptStr.join("\n"));
    webView->load(url);
}

//load the location from the line edit
void Qlocation::showItem()
{
    loadAddress( locationLineEdit->text() );    
}

//update the geos informations
void Qlocation::updateLatLng()
{    
    QStringList scriptStr1,scriptStr2,scriptStr3,scriptStr4,scriptStr5; 
    scriptStr1 << "document.getElementById(\"lat\").value;";
    QVariant vres1 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr1.join("\n") );
    QString sres1 = vres1.toString();
    
    scriptStr2 << "document.getElementById(\"lng\").value;";
    QVariant vres2 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr2.join("\n") );
    QString sres2 = vres2.toString();
    
    scriptStr3 << "document.getElementById(\"country\").value;";
    QVariant vres3 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr3.join("\n") );
    QString sres3 = vres3.toString();
    
    scriptStr4 << "document.getElementById(\"city\").value;";
    QVariant vres4 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr4.join("\n") );
    QString sres4 = vres4.toString();
    
    scriptStr5 << "document.getElementById(\"timezone\").value;";
    QVariant vres5 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr5.join("\n") );
    QString sres5 = vres5.toString();
    
    latLineEdit->setText(sres1);
    lngLineEdit->setText(sres2);
    countryLineEdit->setText(sres3);
    cityLineEdit->setText(sres4);
    timezoneLineEdit->setText(sres5); 
}

//
void Qlocation::closeEvent(QCloseEvent *event)
{
    hide();
    init();
    event->ignore();
}

//
void Qlocation::setActions()
{
    connect(searchButton,SIGNAL(clicked()),this,SLOT(showItem()));  
    connect(applyButton,SIGNAL(clicked()),this,SLOT(updateLatLng()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(save()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(cityLineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(update()));
    connect(this,SIGNAL(updateMap()),this,SLOT(updateLatLng())); 
}

//
void Qlocation::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
    applyButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

//
void Qlocation::apply()
{
    latitude = latLineEdit->text().toDouble();
    longitude = lngLineEdit->text().toDouble();
    city = cityLineEdit->text();
    country = countryLineEdit->text();
    timezone = timezoneLineEdit->text().toInt();
    db->setTable("location");
    db->update("latitude",latLineEdit->text());
    db->update("longitude",lngLineEdit->text()); 
    db->update("city",cityLineEdit->text());
    db->update("country",countryLineEdit->text());
    db->update("timezone",timezoneLineEdit->text());
    emit(locationChanged());
}

//
void Qlocation::save()
{
    if (latLineEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"The latitude is empty",QMessageBox::Ok);
    else if (lngLineEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"The longitude is empty",QMessageBox::Ok);    
    else if (cityLineEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"The city is empty",QMessageBox::Ok);
    else if (countryLineEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"The country is empty",QMessageBox::Ok);
    else if (timezoneLineEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"The timezone is empty",QMessageBox::Ok);
    else apply();
}

//
void Qlocation::cancel()
{
    close();
}
//
