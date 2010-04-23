#ifndef JMPLAYER_H
#define JMPLAYER_H
//
#include <QMainWindow>
#include <QtGui>
#include <QDialog>
#include <QProcess>
#include <QString>
#include <QTextStream>
#include <QSlider>
#include "getFileInfo.h"
#include "ui_jmplayer.h"
//
struct metaInfo{
    int length;
    QString name;
    QString title;
    int videoId;
    int videoWidth;
    int videoHeight;
};

class Jmplayer : public QMainWindow, public Ui::Jmplayer
{
Q_OBJECT
public:
	Jmplayer( QWidget * parent = 0, Qt::WFlags f = 0 );
    
private slots:
    void play();
	void stop();
    void pause();    
    //void start_stop();
    void pauseContinue();
    void showTime();    
    void setSliderValue();    
    void skipForward();
    void skipBackward();
    void seekFile();
    void changeVolume();
    
private:   
    GetFileInfo fileInfo;
    QString program;
    QString files;
    QString fileName;
    int videoId;
    int videoHeight;
    int videoWidth;
    QStringList arguments;    
    QStringList filesList;
    QStringList filesList2;   
    QList<metaInfo> filesInfos;
    QProcess *myProcess;     
    QTimer *timer;
    QTime *time;
    bool firstTime;
    bool running;
    //bool paused;
    int ms;
    int maxTime;
    QDesktopWidget *desktop;
    int screenWidth;
    int width; 
    int screenHeight;
    int height;
    int x;
    int y;
    QSize windowSize; 
    int fileIndex;
    
    void adjustWindow();
    void adjustAudioWindow();
    void adjustVideoWindow();
    void setInfos(QString); 
    void initUi();
    void init();
    QString calculateTime(int);   
    void getFilesInfos(); 
    void initFiles();
    void closeEvent(QCloseEvent *);
    
public:
    void playFiles();
    void loadFiles(QStringList);
};
#endif




