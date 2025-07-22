/****************************************************************************
** Meta object code from reading C++ file 'RknnProcessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/RknnProcessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RknnProcessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RknnProcessor_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RknnProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RknnProcessor_t qt_meta_stringdata_RknnProcessor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RknnProcessor"
QT_MOC_LITERAL(1, 14, 9), // "initReady"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "success"
QT_MOC_LITERAL(4, 33, 7), // "message"
QT_MOC_LITERAL(5, 41, 17), // "inferenceFinished"
QT_MOC_LITERAL(6, 59, 11), // "resultImage"
QT_MOC_LITERAL(7, 71, 13), // "errorOccurred"
QT_MOC_LITERAL(8, 85, 12), // "errorMessage"
QT_MOC_LITERAL(9, 98, 10), // "initialize"
QT_MOC_LITERAL(10, 109, 9), // "modelPath"
QT_MOC_LITERAL(11, 119, 12), // "runInference"
QT_MOC_LITERAL(12, 132, 9) // "imagePath"

    },
    "RknnProcessor\0initReady\0\0success\0"
    "message\0inferenceFinished\0resultImage\0"
    "errorOccurred\0errorMessage\0initialize\0"
    "modelPath\0runInference\0imagePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RknnProcessor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    2,   44,    2, 0x06 /* Public */,
       7,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   52,    2, 0x0a /* Public */,
      11,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QImage, QMetaType::QString,    6,    4,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void RknnProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RknnProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->inferenceFinished((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->initialize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->runInference((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RknnProcessor::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RknnProcessor::initReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RknnProcessor::*)(const QImage & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RknnProcessor::inferenceFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RknnProcessor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RknnProcessor::errorOccurred)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RknnProcessor::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RknnProcessor.data,
    qt_meta_data_RknnProcessor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RknnProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RknnProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RknnProcessor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RknnProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RknnProcessor::initReady(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RknnProcessor::inferenceFinished(const QImage & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RknnProcessor::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
