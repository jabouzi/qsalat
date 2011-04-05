#include "lib/qtsingleapplication.h"
//#include <QApplication>
#include "qsalat.h"
//
int main(int argc, char ** argv)
{
    QtSingleApplication app(argc, argv);

    if (app.isRunning())
        return 0;

    app.setApplicationName( "Qsalat" );
    QString locale = QLocale::system().name();
    QTranslator translator;
    QString path = QCoreApplication::applicationDirPath ();
    if (path.data()[path.size() - 1] != '/') path += "/";
    if (locale.contains("fr", Qt::CaseInsensitive)) translator.load(QString(path+"fr/qsalat_fr"));
    else if (locale.contains("en", Qt::CaseInsensitive)) translator.load(QString(path+"en/qsalat_en"));
    app.installTranslator(&translator);
    Qsalat win;
    app.setActivationWindow(&win);
    win.show(); 
    app.setActivationWindow(&win, false);
    QObject::connect(&win, SIGNAL(needToShow()), &app, SLOT(activateWindow()));
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
