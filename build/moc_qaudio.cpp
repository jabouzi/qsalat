/****************************************************************************
** Meta object code from reading C++ file 'qaudio.h'
**
** Created: Thu Jan 7 23:00:17 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qaudio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qaudio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qaudio[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      21,    7,    7,    7, 0x08,
      32,    7,    7,    7, 0x08,
      42,    7,    7,    7, 0x08,
      49,    7,    7,    7, 0x08,
      58,    7,    7,    7, 0x08,
      66,    7,    7,    7, 0x08,
      81,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Qaudio[] = {
    "Qaudio\0\0loadPrayer()\0loadFajr()\0"
    "loadDua()\0save()\0cancel()\0apply()\0"
    "checkChanged()\0preview()\0"
};

const QMetaObject Qaudio::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qaudio,
      qt_meta_data_Qaudio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qaudio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qaudio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qaudio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qaudio))
        return static_cast<void*>(const_cast< Qaudio*>(this));
    if (!strcmp(_clname, "Ui::Audio"))
        return static_cast< Ui::Audio*>(const_cast< Qaudio*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qaudio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadPrayer(); break;
        case 1: loadFajr(); break;
        case 2: loadDua(); break;
        case 3: save(); break;
        case 4: cancel(); break;
        case 5: apply(); break;
        case 6: checkChanged(); break;
        case 7: preview(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
