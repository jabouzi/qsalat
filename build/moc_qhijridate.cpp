/****************************************************************************
** Meta object code from reading C++ file 'qhijridate.h'
**
** Created: Fri Apr 23 09:09:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qhijridate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhijridate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qhijridate[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      22,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Qhijridate[] = {
    "Qhijridate\0\0convert()\0update()\0"
};

const QMetaObject Qhijridate::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qhijridate,
      qt_meta_data_Qhijridate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qhijridate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qhijridate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qhijridate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qhijridate))
        return static_cast<void*>(const_cast< Qhijridate*>(this));
    if (!strcmp(_clname, "Ui::Hijri"))
        return static_cast< Ui::Hijri*>(const_cast< Qhijridate*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qhijridate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: convert(); break;
        case 1: update(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
