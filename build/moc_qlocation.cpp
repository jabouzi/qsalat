/****************************************************************************
** Meta object code from reading C++ file 'qlocation.h'
**
** Created: Fri Apr 23 06:47:35 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qlocation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlocation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qlocation[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      23,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   10,   10,   10, 0x08,
      58,   56,   10,   10, 0x08,
      87,   10,   10,   10, 0x08,
      98,   10,   10,   10, 0x08,
     113,   10,   10,   10, 0x08,
     121,   10,   10,   10, 0x08,
     128,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Qlocation[] = {
    "Qlocation\0\0reloadMap()\0updateMap()\0"
    "loadAddress(QString)\0,\0"
    "loadCoordinates(float,float)\0showItem()\0"
    "updateLatLng()\0apply()\0save()\0cancel()\0"
};

const QMetaObject Qlocation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qlocation,
      qt_meta_data_Qlocation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qlocation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qlocation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qlocation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qlocation))
        return static_cast<void*>(const_cast< Qlocation*>(this));
    if (!strcmp(_clname, "Ui::Location"))
        return static_cast< Ui::Location*>(const_cast< Qlocation*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qlocation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: reloadMap(); break;
        case 1: updateMap(); break;
        case 2: loadAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: loadCoordinates((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 4: showItem(); break;
        case 5: updateLatLng(); break;
        case 6: apply(); break;
        case 7: save(); break;
        case 8: cancel(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Qlocation::reloadMap()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Qlocation::updateMap()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
