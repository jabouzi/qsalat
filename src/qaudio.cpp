/****************************************************************************
** Qsalat project V1.0
** qaudio.cpp
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

#include "qaudio.h"

//
Qaudio::Qaudio( QWidget * parent, Qt::WFlags f) : QDialog(parent, f )
{
    setupUi(this);    
    setActions();
    initDB();
}

void Qaudio::setPath(QString lpath)
{
    path = lpath;
    setUI();
}

void Qaudio::initDB()
{
    db = Database::getInstance();
    db->setDatabaseName("data/qsalat.db");
    db->setDatabase();   
    db->setTable("audio");
}

void Qaudio::setSalatAudio(QString salat)
{
    salatAudio = salat;
}

void Qaudio::setFajrAudio(QString fajr)
{
    fajrAudio = fajr;
}

void Qaudio::setDuaAudio(QString dua)
{
    duaAudio = dua;
}

void Qaudio::setPlayAthan(int athan)
{
    playAthan = athan;
}

void Qaudio::setPlayDua(int dua)
{
    playDua = dua;
}

//
void Qaudio::init()
{
    setMediaFilesLists();    
    if (0 == playAthan) {
        salatCheckBox->setChecked(false); 
        duaCheckBox->setChecked(false);
        duaCheckBox->setEnabled(false);        
    }
    else{
        salatCheckBox->setChecked(true);
        if (0 == playDua) {
            duaCheckBox->setChecked(false);         
        }
        else{
            duaCheckBox->setChecked(true);
        }    
    }  
}

//
void Qaudio::closeEvent(QCloseEvent *event)
{
    hide();
    init();
    event->ignore();
}

//
void Qaudio::setActions()
{
    connect(prayerButton, SIGNAL(clicked()), this, SLOT(loadPrayer()));
    connect(fajrButton, SIGNAL(clicked()), this, SLOT(loadFajr()));
    connect(duaButton, SIGNAL(clicked()), this, SLOT(loadDua()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(previewButton,SIGNAL(clicked()), this, SLOT(preview()));    
    connect(salatCheckBox,SIGNAL(clicked()), this, SLOT(checkChanged()));    
}

//
void Qaudio::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    prayerButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    fajrButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    duaButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));   
}

// load athan file
void Qaudio::loadPrayer()
{
    salatFiles->addItem(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios et videos (*.mp3 *.wma *.ogg *.wave *.midi *.mp4 *.flv *.ogv *.mpeg *.mpg *.avi *.divx *.wmv *.mov)")));
}

// load fajr file
void Qaudio::loadFajr()
{
    fajrFiles->addItem(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios et videos (*.mp3 *.wma *.ogg *.wave *.midi *.mp4 *.flv *.ogv *.mpeg *.mpg *.avi *.divx *.wmv *.mov)")));
}

// load dua file
void Qaudio::loadDua()
{
    duaFiles->addItem(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios et videos (*.mp3 *.wma *.ogg *.wave *.midi *.mp4 *.flv *.ogv *.mpeg *.mpg *.avi *.divx *.wmv *.mov)")));
}

//
void Qaudio::preview()
{       
    QStringList audioFile;         
    audioFile.clear();
    if (regularRadioButton->isChecked()) audioFile << path+"audio/salat/"+salatFiles->currentText() << "Athan preview";
    else if (fajrRadioButton->isChecked()) audioFile << path+"audio/fajr/"+fajrFiles->currentText() << "Athan fajr preview"; 
    else audioFile << path+"audio/dua/"+duaFiles->currentText() << "Dua fajr preview";   
    QString program = "salatPlayer";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, audioFile);
}

//
void Qaudio::apply()
{
    db->setTable("audio");
    int prayerChecked = 0;
    int duaChecked = 0;
    QString fileName = "";
    QStringList list;
    QString newFileName = "";
    
    fileName = salatFiles->currentText();
    list = fileName.split("/");
    newFileName = list[list.size()-1];    
    db->update("athan",newFileName);
    
    fileName = fajrFiles->currentText();
    list = fileName.split("/");
    newFileName = list[list.size()-1];
    db->update("fajr",newFileName);
    
    fileName = duaFiles->currentText();
    list = fileName.split("/");
    newFileName = list[list.size()-1];
    db->update("dua",newFileName);
    
    if (salatCheckBox->isChecked()) prayerChecked = 1;
    if (duaCheckBox->isChecked()) duaChecked = 1;
    db->update("playAthan",QString::number(prayerChecked));
    db->update("playDua",QString::number(duaChecked));    
    
    addNewFiles(salatFiles,"salat");
    addNewFiles(fajrFiles,"fajr");
    addNewFiles(duaFiles,"dua");
    
    emit(audioChanged());
}

//
void Qaudio::save()
{
    apply();
    close();
}

//
void Qaudio::cancel()
{
    close();
}

void Qaudio::checkChanged()
{
    if (salatCheckBox->isChecked() == false){
        duaCheckBox->setChecked(false);
        duaCheckBox->setEnabled(false);
    }
    else{
        duaCheckBox->setEnabled(true);
    }
}

QStringList Qaudio::getMediaFiles(QString folder)
{
    QDir currentDir = QDir(path+"audio/"+folder+"/");
    QStringList fileName;
    fileName << "*.mp3" << "*.wma" << "*.ogg" << "*.wave" << "*.midi" << "*.mp4" << "*.flv" << "*.ogv" << "*.mpeg" << "*.mpg" << "*.avi" << "*.divx" << "*.wmv" << "*.mov";
    return currentDir.entryList(QStringList(fileName),QDir::Files | QDir::NoSymLinks);
}

void Qaudio::setMediaFilesLists()
{
    salatFiles->clear();
    fajrFiles->clear();
    duaFiles->clear();
    
    int currentIndex = 0;    
    QStringList files;
    
    files = getMediaFiles("salat");
    salatFiles->addItems(files);
    currentIndex = files.indexOf(salatAudio);
    salatFiles->setCurrentIndex(currentIndex);
    
    files = getMediaFiles("fajr");
    fajrFiles->addItems(files);
    currentIndex = files.indexOf(fajrAudio);
    fajrFiles->setCurrentIndex(currentIndex);
    
    files = getMediaFiles("dua");
    duaFiles->addItems(files);
    currentIndex = files.indexOf(duaAudio);
    duaFiles->setCurrentIndex(currentIndex);
}

void Qaudio::addNewFiles(QComboBox* fileList, QString folder)
{
    for (int i = 0; i < fileList->count(); ++i)
    {
        QString file = fileList->itemText(i);
        QStringList list = file.split("/");
        QString newFile = list[list.size()-1];
        if (!QFile::exists(path+"audio/"+folder+"/"+newFile))
        {
            QFile::copy(file,path+"audio/"+folder+"/"+newFile);
        }
    }
}
