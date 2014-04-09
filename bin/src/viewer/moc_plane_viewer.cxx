/****************************************************************************
** Meta object code from reading C++ file 'plane_viewer.h'
**
** Created: Mon Jan 6 20:01:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewer/plane_viewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plane_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MedicalViewer__PlaneViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      45,   27,   27,   27, 0x0a,
      60,   27,   27,   27, 0x0a,
      82,   27,   27,   27, 0x0a,
     104,   27,   27,   27, 0x0a,
     127,   27,   27,   27, 0x0a,
     145,   27,   27,   27, 0x0a,
     158,   27,   27,   27, 0x0a,
     167,   27,   27,   27, 0x0a,
     199,   27,   27,   27, 0x0a,
     233,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MedicalViewer__PlaneViewer[] = {
    "MedicalViewer::PlaneViewer\0\0"
    "resliceMode(int)\0thickMode(int)\0"
    "SetBlendModeToMaxIP()\0SetBlendModeToMinIP()\0"
    "SetBlendModeToMeanIP()\0SetBlendMode(int)\0"
    "ResetViews()\0Render()\0"
    "AddDistanceMeasurementToView1()\0"
    "AddDistanceMeasurementToView(int)\0"
    "slotLoadImage()\0"
};

void MedicalViewer::PlaneViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlaneViewer *_t = static_cast<PlaneViewer *>(_o);
        switch (_id) {
        case 0: _t->resliceMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->thickMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SetBlendModeToMaxIP(); break;
        case 3: _t->SetBlendModeToMinIP(); break;
        case 4: _t->SetBlendModeToMeanIP(); break;
        case 5: _t->SetBlendMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ResetViews(); break;
        case 7: _t->Render(); break;
        case 8: _t->AddDistanceMeasurementToView1(); break;
        case 9: _t->AddDistanceMeasurementToView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slotLoadImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MedicalViewer::PlaneViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MedicalViewer::PlaneViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MedicalViewer__PlaneViewer,
      qt_meta_data_MedicalViewer__PlaneViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MedicalViewer::PlaneViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MedicalViewer::PlaneViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MedicalViewer::PlaneViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MedicalViewer__PlaneViewer))
        return static_cast<void*>(const_cast< PlaneViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MedicalViewer::PlaneViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
