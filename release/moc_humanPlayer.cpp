/****************************************************************************
** Meta object code from reading C++ file 'humanPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/gameLogics/humanPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'humanPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HumanPlayer_t {
    QByteArrayData data[7];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_HumanPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_HumanPlayer_t qt_meta_stringdata_HumanPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 4),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 15),
QT_MOC_LITERAL(4, 34, 2),
QT_MOC_LITERAL(5, 37, 20),
QT_MOC_LITERAL(6, 58, 20)
    },
    "HumanPlayer\0turn\0\0cellWasAttacked\0id\0"
    "reEmitFleetInstalled\0needAutoInstallFleet\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HumanPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    1,   35,    2, 0x09,
       5,    0,   38,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HumanPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HumanPlayer *_t = static_cast<HumanPlayer *>(_o);
        switch (_id) {
        case 0: _t->turn(); break;
        case 1: _t->cellWasAttacked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->reEmitFleetInstalled(); break;
        case 3: _t->needAutoInstallFleet(); break;
        default: ;
        }
    }
}

const QMetaObject HumanPlayer::staticMetaObject = {
    { &Player::staticMetaObject, qt_meta_stringdata_HumanPlayer.data,
      qt_meta_data_HumanPlayer,  qt_static_metacall, 0, 0}
};


const QMetaObject *HumanPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HumanPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HumanPlayer.stringdata))
        return static_cast<void*>(const_cast< HumanPlayer*>(this));
    return Player::qt_metacast(_clname);
}

int HumanPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Player::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
