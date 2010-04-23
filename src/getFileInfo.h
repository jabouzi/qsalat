#ifndef GETFILEINFO_H
#define GETFILEINFO_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QStringList>
class GetFileInfo
{
public:
    GetFileInfo();
    void init(QString);
    QString GetFileName();
    QString GetFileLength();
    QString GetFileMetaTitle();
    QString GetVideoId();
    QString GetVideoHeight();
    QString GetVideoWidth();
    void grepFile(QString);

private:
    QString filePath;
    QString fileName;
    QString fileLength;
    QString fileMetaTitle;   
    QString videoId;
    QString videoHeight;
    QString videoWidth;
};

#endif // __GETFILEINFO_H__
