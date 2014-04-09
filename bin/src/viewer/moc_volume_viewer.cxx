/****************************************************************************
** Meta object code from reading C++ file 'volume_viewer.h'
**
** Created: Tue Jan 7 00:32:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewer/volume_viewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'volume_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MedicalViewer__VolumeViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x0a,
      46,   28,   28,   28, 0x0a,
      62,   28,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MedicalViewer__VolumeViewer[] = {
    "MedicalViewer::VolumeViewer\0\0"
    "loadLiverImage()\0loadGallImage()\0"
    "loadVesselImage()\0"
};

void MedicalViewer::VolumeViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VolumeViewer *_t = static_cast<VolumeViewer *>(_o);
        switch (_id) {
        case 0: _t->loadLiverImage(); break;
        case 1: _t->loadGallImage(); break;
        case 2: _t->loadVesselImage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MedicalViewer::VolumeViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MedicalViewer::VolumeViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MedicalViewer__VolumeViewer,
      qt_meta_data_MedicalViewer__VolumeViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MedicalViewer::VolumeViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MedicalViewer::VolumeViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MedicalViewer::VolumeViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MedicalViewer__VolumeViewer))
        return static_cast<void*>(const_cast< VolumeViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MedicalViewer::VolumeViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
