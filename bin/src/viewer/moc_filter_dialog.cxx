/****************************************************************************
** Meta object code from reading C++ file 'filter_dialog.h'
**
** Created: Mon Jan 6 20:01:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewer/filter_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filter_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MedicalViewer__FilterDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   29,   28,   28, 0x0a,
      54,   28,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MedicalViewer__FilterDialog[] = {
    "MedicalViewer::FilterDialog\0\0p\0"
    "slotModifiedParam(int)\0slotResetDefaults()\0"
};

void MedicalViewer::FilterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FilterDialog *_t = static_cast<FilterDialog *>(_o);
        switch (_id) {
        case 0: _t->slotModifiedParam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotResetDefaults(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MedicalViewer::FilterDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MedicalViewer::FilterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MedicalViewer__FilterDialog,
      qt_meta_data_MedicalViewer__FilterDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MedicalViewer::FilterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MedicalViewer::FilterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MedicalViewer::FilterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MedicalViewer__FilterDialog))
        return static_cast<void*>(const_cast< FilterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MedicalViewer::FilterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
