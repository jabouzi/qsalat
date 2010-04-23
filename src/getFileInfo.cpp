#include "getFileInfo.h"

GetFileInfo::GetFileInfo()
{
    filePath = ' ';
    fileName = ' ';
    fileLength = ' ';
    fileMetaTitle = ' ';
    videoId = '0';
    videoHeight = '0';
    videoWidth = '0';
}

void GetFileInfo::init(QString path)
{
    filePath = path;
}

QString GetFileInfo::GetFileName()
{
    return fileName;
}

QString GetFileInfo::GetFileLength()
{
    return fileLength;
}

QString GetFileInfo::GetFileMetaTitle()
{
    return fileMetaTitle;
}

QString GetFileInfo::GetVideoId()
{
    return videoId;
}

QString GetFileInfo::GetVideoWidth()
{
    return videoWidth;
}

QString GetFileInfo::GetVideoHeight()
{
    return videoHeight;
}

void GetFileInfo::grepFile(QString filePath)
{
     QFile file(filePath);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
     	return;     	
     }
         

     QTextStream in(&file);
     while (!in.atEnd()) {
         QString line = in.readLine();
         if (line.startsWith("ID_LENGTH"))
         {
             QStringList liste = line.split("=");
             fileLength = liste.at(1);
         }
         
         if (line.startsWith("ID_CLIP_INFO_NAME0"))
         {
             QStringList liste = line.split("=");
             fileName = liste.at(1);
         }
         
         if (line.startsWith("ID_CLIP_INFO_VALUE0"))
         {
             QStringList liste = line.split("=");
             fileMetaTitle = liste.at(1);
         }
         if (line.startsWith("ID_VIDEO_ID"))
         {
             QStringList liste = line.split("=");
             videoId = liste.at(1);
         }
         if (line.startsWith("ID_VIDEO_WIDTH"))
         {
             QStringList liste = line.split("=");
             videoWidth = liste.at(1);
         }
         if (line.startsWith("ID_VIDEO_HEIGHT"))
         {
             QStringList liste = line.split("=");
             videoHeight = liste.at(1);
         }
     }
}
    
// place your code here
