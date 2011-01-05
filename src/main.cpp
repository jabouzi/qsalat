#include <QApplication>
#include "qsalat.h"
//
int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    app.setApplicationName( "Qsalat" );
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString(locale+"/qsalat_") + locale);
    app.installTranslator(&translator);
    Qsalat win;
    win.show(); 
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
