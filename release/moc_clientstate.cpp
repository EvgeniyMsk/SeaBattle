/****************************************************************************
** Meta object code from reading C++ file 'clientstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/tcpClient/clientstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientState_t {
    QByteArrayData data[13];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ClientState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ClientState_t qt_meta_stringdata_ClientState = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 5),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 7),
QT_MOC_LITERAL(4, 27, 8),
QT_MOC_LITERAL(5, 36, 21),
QT_MOC_LITERAL(6, 58, 4),
QT_MOC_LITERAL(7, 63, 5),
QT_MOC_LITERAL(8, 69, 7),
QT_MOC_LITERAL(9, 77, 8),
QT_MOC_LITERAL(10, 86, 4),
QT_MOC_LITERAL(11, 91, 5),
QT_MOC_LITERAL(12, 97, 4)
    },
    "ClientState\0error\0\0message\0received\0"
    "Protocol::RequestType\0type\0bytes\0"
    "connect\0hostName\0port\0abort\0send\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,
       4,    2,   42,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    2,   47,    2, 0x0a,
      11,    0,   52,    2, 0x0a,
      12,    2,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    6,    7,

       0        // eod
};

void ClientState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientState *_t = static_cast<ClientState *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->received((*reinterpret_cast< Protocol::RequestType(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 3: _t->abort(); break;
        case 4: _t->send((*reinterpret_cast< Protocol::RequestType(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientState::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientState::error)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientState::*_t)(Protocol::RequestType , const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientState::received)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ClientState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientState.data,
      qt_meta_data_ClientState,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClientState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientState.stringdata))
        return static_cast<void*>(const_cast< ClientState*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ClientState::error(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientState::received(Protocol::RequestType _t1, const QByteArray & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
