/****************************************************************************
** Meta object code from reading C++ file 'qsalat.h'
**
** Created: Fri Apr 23 09:20:33 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qsalat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsalat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qsalat[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      57,    7,    7,    7, 0x08,
      72,    7,    7,    7, 0x08,
      84,    7,    7,    7, 0x08,
      96,    7,    7,    7, 0x08,
     114,    7,    7,    7, 0x08,
     130,    7,    7,    7, 0x08,
     144,    7,    7,    7, 0x08,
     157,    7,    7,    7, 0x08,
     173,    7,    7,    7, 0x08,
     186,    7,    7,    7, 0x08,
     195,    7,    7,    7, 0x08,
     203,    7,    7,    7, 0x08,
     217,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Qsalat[] = {
    "Qsalat\0\0iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "showLocation()\0showQibla()\0showAudio()\0"
    "showCalculation()\0showWorldtime()\0"
    "showMonthly()\0showYearly()\0showHijridate()\0"
    "showPlayer()\0_about()\0_hide()\0"
    "_showNormal()\0itsSalatTime()\0"
};

const QMetaObject Qsalat::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Qsalat,
      qt_meta_data_Qsalat, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qsalat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qsalat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qsalat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qsalat))
        return static_cast<void*>(const_cast< Qsalat*>(this));
    if (!strcmp(_clname, "Ui::Salat"))
        return static_cast< Ui::Salat*>(const_cast< Qsalat*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Qsalat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: showLocation(); break;
        case 2: showQibla(); break;
        case 3: showAudio(); break;
        case 4: showCalculation(); break;
        case 5: showWorldtime(); break;
        case 6: showMonthly(); break;
        case 7: showYearly(); break;
        case 8: showHijridate(); break;
        case 9: showPlayer(); break;
        case 10: _about(); break;
        case 11: _hide(); break;
        case 12: _showNormal(); break;
        case 13: itsSalatTime(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
