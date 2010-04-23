/****************************************************************************
** Meta object code from reading C++ file 'jmplayer.h'
**
** Created: Sun Jan 3 20:59:09 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/jmplayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jmplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Jmplayer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      17,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      32,    9,    9,    9, 0x08,
      48,    9,    9,    9, 0x08,
      59,    9,    9,    9, 0x08,
      76,    9,    9,    9, 0x08,
      90,    9,    9,    9, 0x08,
     105,    9,    9,    9, 0x08,
     116,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Jmplayer[] = {
    "Jmplayer\0\0play()\0stop()\0pause()\0"
    "pauseContinue()\0showTime()\0setSliderValue()\0"
    "skipForward()\0skipBackward()\0seekFile()\0"
    "changeVolume()\0"
};

const QMetaObject Jmplayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Jmplayer,
      qt_meta_data_Jmplayer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Jmplayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Jmplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Jmplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Jmplayer))
        return static_cast<void*>(const_cast< Jmplayer*>(this));
    if (!strcmp(_clname, "Ui::Jmplayer"))
        return static_cast< Ui::Jmplayer*>(const_cast< Jmplayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Jmplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: play(); break;
        case 1: stop(); break;
        case 2: pause(); break;
        case 3: pauseContinue(); break;
        case 4: showTime(); break;
        case 5: setSliderValue(); break;
        case 6: skipForward(); break;
        case 7: skipBackward(); break;
        case 8: seekFile(); break;
        case 9: changeVolume(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
