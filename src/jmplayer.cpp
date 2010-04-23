#include "jmplayer.h"
//
Jmplayer::Jmplayer( QWidget * parent, Qt::WFlags f) 
    : QMainWindow(parent, f)
{
    setupUi(this);    
    timer = new QTimer(this);
    ms = 0;
    fileIndex = 0;
    firstTime = true;
    running = false;    
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(setSliderValue()));
    connect(play_button, SIGNAL(clicked()), this, SLOT(pauseContinue()));
    connect(prev_button, SIGNAL(clicked()), this, SLOT(skipBackward()));
    connect(next_button, SIGNAL(clicked()), this, SLOT(skipForward()));
    connect(timeSlider, SIGNAL(sliderReleased()),this, SLOT(seekFile()));
    connect(volumeSlider, SIGNAL(valueChanged(int)),this, SLOT(changeVolume()));
    program = "/usr/bin/mplayer";
    myProcess = new QProcess(parent);  
    adjustWindow();
    initUi(); 
}

void Jmplayer::init()
{
    timeSlider->setRange(0, filesInfos.at(fileIndex).length);    
    volumeSlider->setRange(0,100);
    volumeSlider->setValue(100);
    timePlay->setText("00:00:00"); 
    totalTime->setText(calculateTime(filesInfos.at(fileIndex).length));
    QStringList templist = filesList2.at(fileIndex).split("/");
    QString filename = templist[templist.size()-1];
    setWindowTitle(filename);
}

void Jmplayer::initFiles()
{
    int id = int(widget->winId()); 
    arguments.clear();
    arguments << "-slave" << "-quiet" << "-wid" <<  QString::number(id) << filesList2;
}

void Jmplayer::initUi(){
    prev_button->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    next_button->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    prev_button->setEnabled(false);
    play_button->setEnabled(false);
    next_button->setEnabled(false);
}

void Jmplayer::adjustWindow()
{
    desktop = QApplication::desktop();       
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    windowSize = size(); 
    width = windowSize.width(); 
    height = windowSize.height();
    x = (screenWidth - width);
    y = (screenHeight - height);      
    move ( x, y );
}

void Jmplayer::adjustVideoWindow(){

    setMaximumSize(16777215,16777215);
    setMinimumSize(300,250);    
    setGeometry(x,y,filesInfos.at(fileIndex).videoWidth+18,filesInfos.at(fileIndex).videoHeight+98);
}

void Jmplayer::adjustAudioWindow(){
 
    setMaximumSize(300,70);
    setMinimumSize(300,70);        
    setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

void Jmplayer::closeEvent(QCloseEvent *event)
{
	stop();
	close();
}

void Jmplayer::play()
{
    myProcess->start(program, arguments);    
}

void Jmplayer::stop()
{
    myProcess->write("stop\n");
    myProcess->close();
    timer->stop();    
}

void Jmplayer::pause()
{
    myProcess->write("pause\n");
}

void Jmplayer::setInfos(QString fileInfoPath)
{
    metaInfo infos;
    fileInfo.grepFile(fileInfoPath);
    bool ok;
    infos.length = int(fileInfo.GetFileLength().toFloat(&ok));
    infos.name = fileInfo.GetFileName();
    infos.title = fileInfo.GetFileMetaTitle();
    infos.videoId = fileInfo.GetVideoId().toInt(&ok); 
    if (infos.videoId == 1)    
    {
        infos.videoWidth = fileInfo.GetVideoWidth().toInt(&ok);
        infos.videoHeight = fileInfo.GetVideoHeight().toInt(&ok);
    }
    else
    {
        infos.videoWidth = 0;
        infos.videoHeight = 0;
    }     
    filesInfos.append(infos);
}
 
void Jmplayer::pauseContinue()
{
    if (firstTime)
    {
        init(); 
        timer->start(1000);
        play();
        play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        firstTime = false;
        running = true;
    }
    else
    {
       if(running){
           timer->stop();        
           pause();
           play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
           running = false;
       }else{        
           timer->start(1000);
           pause();
           play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
           running = true;        
       }
    }
}

void Jmplayer::skipForward()
{
   if (fileIndex < filesList2.size()-1)
   {
       fileIndex++;   
       myProcess->write("pt_step 1\n");
       ms = 0;
       timeSlider->setValue(ms);   
       timer->start(1000);
       init();
   }   
}

void Jmplayer::skipBackward()
{
    if (fileIndex > 0)
    {    
        fileIndex--;    
        myProcess->write("pt_step -1\n");     
        ms = 0;
        timeSlider->setValue(ms);   
        timer->start(1000); 
        init();    
    }
}

void Jmplayer::showTime()
{
    ms = ms + 1;
    if(ms>=filesInfos.at(fileIndex).length){
        ms = 0;
        timeSlider->setValue(ms);
        if (fileIndex < filesList2.size()-1)
        {
            fileIndex++;            
            timer->start(1000);
            init();
        }
        else
        {
            timer->stop();            
            close();
        }
       
        
    }    
    timePlay->setText(calculateTime(ms));
}

void  Jmplayer::setSliderValue()
{
    timeSlider->setValue(ms);
}

void Jmplayer::loadFiles(QStringList files)
{
    filesList = files;
    filesList2 = filesList; 
    filesList.replaceInStrings(" ", "\\ ");    
    filesList.replaceInStrings("(", "\\(");  
    filesList.replaceInStrings(")", "\\)");    
    filesList.replaceInStrings("'", "\\'"); 
    getFilesInfos();
    play_button->setEnabled(true);    
    next_button->setEnabled(true);
    prev_button->setEnabled(true);
    initFiles();
}


void Jmplayer::seekFile()
{ 
    QString seek = "seek "+QString::number(timeSlider->value())+" 2\n";
    myProcess->write(seek.toLatin1().data());
    ms = timeSlider->value();
}

void Jmplayer::changeVolume()
{
    int volumeValue = volumeSlider->value();
    QString volume = "volume "+QString::number(volumeValue)+" 1\n";
    myProcess->write(volume.toLatin1().data());
}

void Jmplayer::getFilesInfos()
{
    for (int i = 0; i < filesList.size(); ++i) {
        QStringList templist = filesList.at(i).split("/");
        QString filename = templist[templist.size()-1];
        QStringList templist2 = filesList2.at(i).split("/");
        QString filename2 = templist2[templist2.size()-1];
        QString systemArg ="mplayer -identify -frames 0 "+filesList.at(i)+" 2>/dev/null > /tmp/"+filename+".log";
        system(systemArg.toLatin1().data());    
        setInfos("/tmp/"+filename2+".log");
        QString s = "/tmp/"+filename+".log";        
    }
}

QString Jmplayer::calculateTime(int time_)
{
    int hours = time_ / 3600;
    int minutes = (time_ - (hours*3600)) / 60;
    int seconds = (time_ - (hours*3600) - (minutes*60)) % 60;
    QString hzero = "";
    QString mzero = "";
    QString szero = "";
    if (hours < 10) hzero = "0";
    if (minutes < 10) mzero = "0";
    if (seconds < 10) szero = "0";
    QString times = hzero+QString::number(hours)+":"+ mzero+QString::number(minutes)+":"+szero+QString::number(seconds);
    return times;
}

void Jmplayer::playFiles()
{
    pauseContinue();
}

//
