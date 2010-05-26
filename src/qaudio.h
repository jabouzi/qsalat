/****************************************************************************
** Qsalat project V1.0
** qaudio.h
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

#ifndef __QAUDIO_H__
#define __QAUDIO_H__

#include <QtGui>
#include <phonon>
#include <QProcess>
#include "ui_audio.h"
#include "database.h"

class Qaudio : public QDialog, public Ui::Audio
{
Q_OBJECT
public:
    Qaudio( QWidget * parent = 0, Qt::WFlags f = 0 );
    void init();
    void setSalatAudio(QString);
    void setFajrAudio(QString);
    void setDuaAudio(QString);
    void setPlayAthan(int);
    void setPlayDua(int);
    void setPath(QString);

protected:
    void closeEvent(QCloseEvent *);
    
private:
    QString file;    
    QString path;
    QString salatAudio;
    QString fajrAudio;
    QString duaAudio;
    int playAthan;
    int playDua;
        
    void setActions();
    void setUI();
    Database *db;
    void initDB();
    QStringList getMediaFiles(QString);
    void setMediaFilesLists();
    void addNewFiles(QComboBox*,QString);


private slots:
    void loadPrayer();
    void loadFajr();
    void loadDua();
    void save();
    void cancel();
    void apply();
    void checkChanged();
    void preview();    
    
signals:
    void audioChanged();
    
};

#endif // __QAUDIO_H__
