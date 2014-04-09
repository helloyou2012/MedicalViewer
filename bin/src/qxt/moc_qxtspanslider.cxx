/****************************************************************************
** Meta object code from reading C++ file 'qxtspanslider.h'
**
** Created: Mon Jan 6 20:01:55 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/qxt/qxtspanslider.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtspanslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxtSpanSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       5,   69, // properties
       1,   84, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x05,
      54,   48,   14,   14, 0x05,
      83,   77,   14,   14, 0x05,
     106,   48,   14,   14, 0x05,
     132,   77,   14,   14, 0x05,
     165,  158,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     191,   48,   14,   14, 0x0a,
     210,   77,   14,   14, 0x0a,
     229,   15,   14,   14, 0x0a,
     246,   48,   14,   14, 0x0a,
     268,   77,   14,   14, 0x0a,

 // properties: name, type, flags
     294,  290, 0x02095103,
     305,  290, 0x02095103,
     316,  290, 0x02095103,
     330,  290, 0x02095103,
     363,  344, 0x0009510b,

 // enums: name, flags, count, data
     344, 0x0,    3,   88,

 // enum data: key, value
     382, uint(QxtSpanSlider::FreeMovement),
     395, uint(QxtSpanSlider::NoCrossing),
     406, uint(QxtSpanSlider::NoOverlapping),

       0        // eod
};

static const char qt_meta_stringdata_QxtSpanSlider[] = {
    "QxtSpanSlider\0\0lower,upper\0"
    "spanChanged(int,int)\0lower\0"
    "lowerValueChanged(int)\0upper\0"
    "upperValueChanged(int)\0lowerPositionChanged(int)\0"
    "upperPositionChanged(int)\0handle\0"
    "sliderPressed(SpanHandle)\0setLowerValue(int)\0"
    "setUpperValue(int)\0setSpan(int,int)\0"
    "setLowerPosition(int)\0setUpperPosition(int)\0"
    "int\0lowerValue\0upperValue\0lowerPosition\0"
    "upperPosition\0HandleMovementMode\0"
    "handleMovementMode\0FreeMovement\0"
    "NoCrossing\0NoOverlapping\0"
};

void QxtSpanSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QxtSpanSlider *_t = static_cast<QxtSpanSlider *>(_o);
        switch (_id) {
        case 0: _t->spanChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->lowerValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->upperValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->lowerPositionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->upperPositionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sliderPressed((*reinterpret_cast< SpanHandle(*)>(_a[1]))); break;
        case 6: _t->setLowerValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setUpperValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setSpan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->setLowerPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setUpperPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QxtSpanSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QxtSpanSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_QxtSpanSlider,
      qt_meta_data_QxtSpanSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxtSpanSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxtSpanSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxtSpanSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtSpanSlider))
        return static_cast<void*>(const_cast< QxtSpanSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int QxtSpanSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = lowerValue(); break;
        case 1: *reinterpret_cast< int*>(_v) = upperValue(); break;
        case 2: *reinterpret_cast< int*>(_v) = lowerPosition(); break;
        case 3: *reinterpret_cast< int*>(_v) = upperPosition(); break;
        case 4: *reinterpret_cast< HandleMovementMode*>(_v) = handleMovementMode(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLowerValue(*reinterpret_cast< int*>(_v)); break;
        case 1: setUpperValue(*reinterpret_cast< int*>(_v)); break;
        case 2: setLowerPosition(*reinterpret_cast< int*>(_v)); break;
        case 3: setUpperPosition(*reinterpret_cast< int*>(_v)); break;
        case 4: setHandleMovementMode(*reinterpret_cast< HandleMovementMode*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QxtSpanSlider::spanChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QxtSpanSlider::lowerValueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QxtSpanSlider::upperValueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QxtSpanSlider::lowerPositionChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QxtSpanSlider::upperPositionChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QxtSpanSlider::sliderPressed(SpanHandle _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
