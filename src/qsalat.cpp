/****************************************************************************
** Qsalat project V1.0
** qsalat.cpp
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

#include "qsalat.h" 
//
Qsalat::Qsalat( QWidget * parent, Qt::WFlags f) 
    : QMainWindow(parent, f)
{
    pLog = new Log("errors.log");
    path = QCoreApplication::applicationDirPath ();
    if (path.data()[path.size() - 1] != '/') path += "/";
    setupUi(this);
    adjustWindow();
    prayers = new Qpray();
    hijri = new Qhijri();
    trayIcon = new QSystemTrayIcon(this);
    trayIconMenu = new QMenu(this);
    createActions();
    setVisible(true);
    init();
    initDB();
    initLocation();
    initLocationObject();
    initQiblaObject();
    initAudio();
    initAudioObject();
    initCalculation();
    initCalculationObject();
    initHijriDateObject();
    initCalendarObject();
    getSalats();
    getHijri();
    createTrayIcon();
    startSalatAlarm();    
}

/**    
 * initialization function : this function is used to initialize and reinitialize the qsalat object 
 */
void Qsalat::init()
{    
    date = QDate::currentDate();    
    year = date.year();
    month = date.month();
    day = date.day();
}

void Qsalat::initDB()
{
    db = Database::getInstance();
    db->setDatabaseName("data/qsalat.db");
    db->setDatabase();   
}

void Qsalat::initLocation()
{ 
    db->setTable("location");
    latitude = db->select("latitude").toDouble();
    longitude = db->select("longitude").toDouble(); 
    city = db->select("city");
    country = db->select("country");
    timezone = db->select("timezone").toInt();   
    pLog->Write(QString::number(latitude)); 
    pLog->Write(QString::number(longitude)); 
    pLog->Write(QString::number(timezone)); 
}

void Qsalat::initLocationObject()
{
    location.setPath(path);
    location.setLatitude(latitude);
    location.setLongitude(longitude);
    location.setCountry(country);
    location.setCity(city);
    location.setTimezone(timezone);
    location.init();
}

void Qsalat::initQiblaObject()
{
    qibla.setPath(path);
    qibla.setLatitude(latitude);
    qibla.setLongitude(longitude);
    qibla.init();
}


void Qsalat::initAudio()
{
    db->setTable("audio");
    prayerAudio = db->select("athan");
    fajrAudio = db->select("fajr");
    duaAudio = db->select("dua"); 
    playAthan = db->select("playAthan").toInt(); 
    playDua = db->select("playDua").toInt(); 
}

void Qsalat::initAudioObject()
{
    audio.setPath(path);
    audio.setSalatAudio(prayerAudio);
    audio.setFajrAudio(fajrAudio);
    audio.setDuaAudio(duaAudio);
    audio.setPlayAthan(playAthan);
    audio.setPlayDua(playDua);
    audio.init();
}

void Qsalat::initCalculation()
{
    db->setTable("calculation");
    calcMethod = db->select("method").toInt();
    fajrMinutes = db->select("fajr").toInt();
    duhrMinutes = db->select("duhr").toInt();
    asrMethod = db->select("asr").toInt();    
    hijriDays = db->select("hijri").toInt();
    highlatitude = db->select("higherLat").toInt();        
}

void Qsalat::initCalculationObject()
{
    calculation.setPath(path);
    calculation.setCalcMethod(calcMethod);
    calculation.setAsrMethod(asrMethod);
    calculation.init();
}

void Qsalat::initHijriDateObject()
{
    hijridate.setPath(path);
}

void Qsalat::initCalendarObject()
{
    calendar.setPath(path);
    calendar.setLatitude(latitude);
    calendar.setLongitude(longitude);
    calendar.setTimezone(timezone);
    calendar.setCalculationMethod(calcMethod);
    calendar.setAsrMethod(asrMethod);
    calendar.init();
}

/**    
 * window position function : this function is used to adjust the main window to the center of the screen
 */
void Qsalat::adjustWindow(){
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth, width; 
    int screenHeight, height;
    int x, y;
    QSize windowSize;     
    screenWidth = desktop->width();
    screenHeight = desktop->height();  
    windowSize = size(); 
    width = windowSize.width(); 
    height = windowSize.height();
    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    y -= 50;     
    move ( x, y );    
}

/**    
 * salat function : calculate the salats times for the current day
 */
void Qsalat::getSalats(){        
    salatTimes = new QString[7];
    prayers->setCalcMethod(calcMethod);
    prayers->setAsrMethod(asrMethod);
    prayers->setDhuhrMinutes(duhrMinutes);
    prayers->setHighLatsMethod(highlatitude);
    salatTimes = prayers->getDatePrayerTimes(year,month,day,latitude,longitude,timezone);
    label_fajr->setText(salatTimes[0]);
    label_duhr->setText(salatTimes[2]);
    label_asr->setText(salatTimes[3]);
    label_maghreb->setText(salatTimes[5]);
    label_isha->setText(salatTimes[6]);
    label_shourouk->setText(salatTimes[1]);
    label_location->setText(city+", "+country); 
}

/**    
 * hijri function : calculate the hijri date for the current day
 */
void Qsalat::getHijri(){    
    QString *dates = new QString[4];
    dates = hijri->isToString(year, month, day,hijriDays);
    label_hijri->setText(QString::fromUtf8((dates[0]+" "+dates[2]+" "+dates[3]).toLatin1().data()));
    label_hijri_2->setText(dates[0]+" "+dates[1]+" "+dates[3]);
}

/**    
 * tray icon function : set the tray icon for this application
 */
void Qsalat::createTrayIcon()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    QColor *c = new QColor ( 238, 238, 157, 255 );    
    QPalette * p = new QPalette();
    p->setColor(QPalette::ToolTipBase,*c);
    QFont *f = new QFont ( "sans", 10, -1, false );    
    QToolTip::setFont ( *f );
    QToolTip::setPalette(*p);    
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);    
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(path+"images/mecque.png"));
    QString ttmessage = "Fajr : "+label_fajr->text()+ QString::fromUtf8(" : فجر")+"\nDuhr : "    +label_duhr->text()+QString::fromUtf8(" : ظهر")+"\nAsr : "+label_asr->text()+QString::fromUtf8(" : عصر")+"\nMaghreb : "+label_maghreb->text()+QString::fromUtf8(" : مغرب")+"\nIsha : "+label_isha->text()+QString::fromUtf8(" : عشاء");
    trayIcon->setToolTip("Qsalat Islamic cross-platform prayers time V1.0");
    trayIcon->setToolTip(ttmessage);
    trayIcon->show();    
}



/**    
 * tray icon menu function : set the tray icon menu
 */
void Qsalat::setVisible(bool visible)
{
    minimizeAction->setEnabled(visible);
    restoreAction->setEnabled(!visible);
    QMainWindow::setVisible(visible);
}

/**    
 * custom close function : make the main window and all other open windows hide on close event
 */
void Qsalat::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
    qibla.hide();
    location.hide();
    audio.hide();
    calculation.hide();
    worldtime.hide();
    calendar.hide();
    hijridate.hide();
}

/**    
 * actions function : set all menu and buttons actions
 */
void Qsalat::createActions()
{
    connect(&alarm, SIGNAL(itsTime()), this, SLOT(itsSalatTime()));
    connect(&calculation, SIGNAL(calculationChanged()), this, SLOT(updateCalculation()));
    connect(&location, SIGNAL(locationChanged()), this, SLOT(updateLocation()));
    connect(&audio, SIGNAL(audioChanged()), this, SLOT(updateAudio()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason))); 
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(_hide()));
    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(_showNormal()));
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));    
    connect(actionLocation, SIGNAL(triggered()), this, SLOT(showLocation()));    
    connect(actionQibla_direction, SIGNAL(triggered()), this, SLOT(showQibla()));     
    connect(actionAudio, SIGNAL(triggered()), this, SLOT(showAudio()));     
    connect(actionCalculation_options, SIGNAL(triggered()), this, SLOT(showCalculation()));    
    connect(actionWorldtime, SIGNAL(triggered()), this, SLOT(showWorldtime()));
    connect(actionGenerate_prayer_times, SIGNAL(triggered()), this, SLOT(showCalendar()));
    connect(actionHijri_date, SIGNAL(triggered()), this, SLOT(showHijridate())); 
    actionQuit->setShortcut(tr("Ctrl+Q"));    
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));    
    connect(actionAbout_QT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));     
    actionHide->setShortcut(tr("Ctrl+H"));
    connect(actionHide, SIGNAL(triggered()), this, SLOT(hide()));    
    connect(actionAbout_Qsalat, SIGNAL(triggered()), this, SLOT(_about()));  
}

int Qsalat::getFajr()
{
    QDateTime today = QDateTime::currentDateTime();
    int year = today.date().year();
    int month = today.date().month();
    int day = today.date().day();
    QString salat = salatTimes[0]+":00";
    QTime time = QTime::fromString(salat, "HH:mm:ss");
    QDateTime salatTime(QDate(year, month, day), time);    
    return today.secsTo(salatTime);
}

int Qsalat::getDuhr()
{
    QDateTime today = QDateTime::currentDateTime();
    int year = today.date().year();
    int month = today.date().month();
    int day = today.date().day();
    QString salat = salatTimes[2]+":00";
    QTime time = QTime::fromString(salat, "HH:mm:ss");
    QDateTime salatTime(QDate(year, month, day), time);
    return today.secsTo(salatTime);
}

int Qsalat::getAsr()
{
    QDateTime today = QDateTime::currentDateTime();
    int year = today.date().year();
    int month = today.date().month();
    int day = today.date().day();
    QString salat = salatTimes[3]+":00";
    QTime time = QTime::fromString(salat, "HH:mm:ss");
    QDateTime salatTime(QDate(year, month, day), time);
    return today.secsTo(salatTime);
}

int Qsalat::getMaghrib()
{
    QDateTime today = QDateTime::currentDateTime();
    int year = today.date().year();
    int month = today.date().month();
    int day = today.date().day();
    QString salat = salatTimes[5]+":00";
    QTime time = QTime::fromString(salat, "HH:mm:ss");
    QDateTime salatTime(QDate(year, month, day), time);
    return today.secsTo(salatTime);
}

int Qsalat::getIsha()
{
    QDateTime today = QDateTime::currentDateTime();
    int year = today.date().year();
    int month = today.date().month();
    int day = today.date().day();
    QString salat = salatTimes[6]+":00";
    QTime time = QTime::fromString(salat, "HH:mm:ss");
    QDateTime salatTime(QDate(year, month, day), time);
    return today.secsTo(salatTime);
}

int Qsalat::getMidNight()
{
    QDateTime today = QDateTime::currentDateTime();
    int year = today.date().year();
    int month = today.date().month();
    int day = today.date().day();
    QTime time = QTime::fromString("24:00:00", "HH:mm:ss");
    QDateTime salatTime(QDate(year, month, day), time);
    return today.secsTo(salatTime);
} 

QString Qsalat::getNextSalat()
{
   if (getFajr() > 0) 
   {
       timeOfSalat = salatTimes[0]+":00";
       salatOrder = 0;
       salatTitle = "Fajr prayer ";
   }
   else if (getDuhr() > 0)
   {
        timeOfSalat = salatTimes[2]+":00";
        salatOrder = 1;
        salatTitle = "Duhr prayer "; 
   }
   else if (getAsr() > 0) 
   {
       timeOfSalat = salatTimes[3]+":00";
       salatOrder = 2;
       salatTitle = "Asr prayer ";
   }
   else if (getMaghrib() > 0)
   {
        timeOfSalat = salatTimes[5]+":00";
        salatOrder = 3;
        salatTitle = "Maghreb prayer ";
   }
   else if (getIsha() > 0)
   {
        timeOfSalat =salatTimes[6]+":00";
        salatOrder = 4;
        salatTitle = "Isha prayer ";
   }
   else 
   {
        timeOfSalat = "00:00:01"; 
        salatOrder = 5;
        salatTitle = "Midnight ";
   }
   pLog->Write(timeOfSalat);
   pLog->Write(QString::number(salatOrder));
   pLog->Write(salatTitle);
   return timeOfSalat;
}

void Qsalat::startSalatAlarm()
{
    if (1 == playAthan)
    {
        QString salatTime = getNextSalat();    
        QDateTime today = QDateTime::currentDateTime();
        QTime time = QTime::fromString(salatTime, "HH:mm:ss");
        alarm.init();   
        alarm.setYear(today.date().year());
        alarm.setMonth(today.date().month());
        if (5 == salatOrder)
        {
            alarm.setDay(today.date().day()+1);
        }
        alarm.setHours(time.hour());
        alarm.setMinutes(time.minute());
        alarm.setSeconds(time.second());
        alarm.setAlarm();
    }
} 

// Private Slots

/**    
 * tray icon click function : set the action when you click on the tray icon
 */
void Qsalat::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:    
    case QSystemTrayIcon::MiddleClick:
        showNormal();
        break;
    default:
        ;
    }
}

/**    
 * show location window function : show the location window to set the city parameters
 */
void Qsalat::showLocation(){
    if (location.isHidden()){
        location.show();    
    }
    else{        
        location.activateWindow();
        location.raise();        
    }
    
}

/**    
 * show qibla window function : show the qibla window and the salat direction
 */
void Qsalat::showQibla(){    
    if (qibla.isHidden()){        
        qibla.show();        
    }    
    else{
         qibla.activateWindow();
         qibla.raise();    
    }    
}

/**    
 * show audio window function : show the audio window to set the athan audio files
 */
void Qsalat::showAudio(){    
    if (audio.isHidden()){        
        audio.show();    
    }    
    else{        
        audio.activateWindow();
        audio.raise();        
    }    
}

/**    
 * show calculation window function : show the salat calculation parameters window
 */
void Qsalat::showCalculation(){       
    if (calculation.isHidden()){        
        calculation.show();
    }    
    else{        
        calculation.activateWindow();
        calculation.raise();        
    }    
}

/**    
 * show calculation window function : show the salat calculation parameters window
 */
void Qsalat::showWorldtime(){
    worldtime.init(timezone);
    if (worldtime.isHidden()){        
        worldtime.show();
    }    
    else{        
        worldtime.activateWindow();
        worldtime.raise();        
    }    
}

/**    
 * show monthly prayer window function : show the salat time for one month
 */
void Qsalat::showCalendar(){    
    if (calendar.isHidden()){        
        calendar.show();
    }    
    else{        
        calendar.activateWindow();
        calendar.raise();        
    }    
}

/**    
 * show yearly prayer window function : show the salat time for one year
 */
//~ void Qsalat::showYearly(){    
    //~ if (yearly.isHidden()){        
        //~ yearly.show();
    //~ }    
    //~ else{        
        //~ yearly.activateWindow();
        //~ yearly.raise();        
    //~ }    
//~ }

/**    
 * show hijri date window function : show the hijri date conversion
 */
void Qsalat::showHijridate(){    
    if (hijridate.isHidden()){        
        hijridate.show();
    }    
    else{        
        hijridate.activateWindow();
        hijridate.raise();        
    }    
}

/**    
 * Application about window
 */
void Qsalat::_about()
{    
    QString cp = "©";
    QMessageBox::about(this, tr("About Qsalat"),
             tr("<b> Qsalat V0.9.3</b> Copyright ") +  QString::fromUtf8(cp.toLatin1().data()) + tr(" 2008-2010 Skander Jabouzi skander@skanderjabouzi.com<br>"             
                 " This is a free software distributed under the terms of the GNU General Public License version 3\n(http://www.gnu.org/licenses/gpl-3.0.html)"));     
} 

/**    
 * close all windows when the main window is closed 
 */
void Qsalat::_hide()
{
    hide();    
    if (!qibla.isHidden()){        
        qibla.hide();
    }
    if (!location.isHidden()){        
        location.hide();
    }
    if (!audio.isHidden()){        
        audio.hide();
    }    
    if (!calculation.isHidden()){        
        calculation.hide();
    }    
    if (!worldtime.isHidden()){        
        worldtime.hide();
    }    
    if (!calendar.isHidden()){        
        calendar.hide();
    }    
    //~ if (!yearly.isHidden()){        
        //~ yearly.hide();
    //~ }    
    if (!hijridate.isHidden()){        
        hijridate.hide();
    }    
}

/**    
 * restore the main window
 */
void Qsalat::_showNormal()
{
    showNormal();
}

/**    
 * play the athan audio
 */
void Qsalat::setPlayer(QStringList files, QString label)
{
    if (playAthan == 1)
    {
        files << label;
        QString program = "salatPlayer";
        QProcess *myProcess = new QProcess(this);
        myProcess->start(program, files);
    }
    
}
 
void Qsalat::itsSalatTime()
{
    if (salatOrder > 4)
    {
        init();      
        getSalats();
        getHijri();
        createTrayIcon();   
    }
    else if (salatOrder > 0)
    {
        audioList.clear();
        audioList << path+"audio/salat/"+prayerAudio;
        if (playDua == 1) audioList << path+"audio/dua/"+duaAudio;
        setPlayer(audioList, salatTitle);  
         
    }
    else
    {
        audioList.clear();
        audioList << path+"audio/fajr/"+fajrAudio;
        if (playDua == 1) audioList << path+"audio/dua/"+duaAudio;
        setPlayer(audioList, salatTitle);   
    }
    startSalatAlarm();
}

void Qsalat::updateCalculation()
{
    initCalculation();    
    getSalats();
    startSalatAlarm();
}

void Qsalat::updateLocation()
{
    initLocation();    
    getSalats();
    startSalatAlarm();
    initQiblaObject();
}

void Qsalat::updateAudio()
{
    initAudio(); 
    initAudioObject();
    startSalatAlarm();
}
//
