/****************************************************************************
** Meta object code from reading C++ file 'slice_viewer.h'
**
** Created: Mon Jan 6 20:01:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewer/slice_viewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slice_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MedicalViewer__SliceViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      54,   42,   27,   27, 0x0a,
      88,   81,   27,   27, 0x0a,
     108,   27,   27,   27, 0x0a,
     126,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MedicalViewer__SliceViewer[] = {
    "MedicalViewer::SliceViewer\0\0updateImage()\0"
    "lower,upper\0setLevelAndWindow(int,int)\0"
    "active\0setActiveSlice(int)\0updateUsageText()\0"
    "slotLoadImage()\0"
};

void MedicalViewer::SliceViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SliceViewer *_t = static_cast<SliceViewer *>(_o);
        switch (_id) {
        case 0: _t->updateImage(); break;
        case 1: _t->setLevelAndWindow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setActiveSlice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateUsageText(); break;
        case 4: _t->slotLoadImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MedicalViewer::SliceViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MedicalViewer::SliceViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MedicalViewer__SliceViewer,
      qt_meta_data_MedicalViewer__SliceViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MedicalViewer::SliceViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MedicalViewer::SliceViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MedicalViewer::SliceViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MedicalViewer__SliceViewer))
        return static_cast<void*>(const_cast< SliceViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MedicalViewer::SliceViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
