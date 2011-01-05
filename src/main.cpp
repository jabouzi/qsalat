#include <QApplication>
#include "qsalat.h"
//
int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    app.setApplicationName( "Qsalat" );
    QString locale = QLocale::system().name();
    QTranslator translator;
    //translator.load(QString("qsalat_fr") + locale);
    if (locale.contains("fr", Qt::CaseInsensitive)) translator.load(QString("fr/qsalat_fr"));
    else if (locale.contains("en", Qt::CaseInsensitive)) translator.load(QString("en/qsalat_en"));
    app.installTranslator(&translator);
    Qsalat win;
    win.show(); 
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
