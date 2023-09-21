/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyGobang/src/widget/gamewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWidget_t {
    QByteArrayData data[17];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWidget"
QT_MOC_LITERAL(1, 11, 14), // "onMouseRelease"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "point"
QT_MOC_LITERAL(4, 33, 10), // "onMakeMove"
QT_MOC_LITERAL(5, 44, 14), // "ChessPieceInfo"
QT_MOC_LITERAL(6, 59, 5), // "piece"
QT_MOC_LITERAL(7, 65, 18), // "onSetpieceResponse"
QT_MOC_LITERAL(8, 84, 10), // "onInitGame"
QT_MOC_LITERAL(9, 95, 7), // "Player*"
QT_MOC_LITERAL(10, 103, 7), // "player1"
QT_MOC_LITERAL(11, 111, 7), // "player2"
QT_MOC_LITERAL(12, 119, 8), // "GameType"
QT_MOC_LITERAL(13, 128, 8), // "gameType"
QT_MOC_LITERAL(14, 137, 6), // "roomId"
QT_MOC_LITERAL(15, 144, 8), // "roomName"
QT_MOC_LITERAL(16, 153, 9) // "rivalName"

    },
    "GameWidget\0onMouseRelease\0\0point\0"
    "onMakeMove\0ChessPieceInfo\0piece\0"
    "onSetpieceResponse\0onInitGame\0Player*\0"
    "player1\0player2\0GameType\0gameType\0"
    "roomId\0roomName\0rivalName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
       8,    6,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 12, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   13,   14,   15,   16,

       0        // eod
};

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMouseRelease((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->onMakeMove((*reinterpret_cast< ChessPieceInfo(*)>(_a[1]))); break;
        case 2: _t->onSetpieceResponse((*reinterpret_cast< ChessPieceInfo(*)>(_a[1]))); break;
        case 3: _t->onInitGame((*reinterpret_cast< Player*(*)>(_a[1])),(*reinterpret_cast< Player*(*)>(_a[2])),(*reinterpret_cast< GameType(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Player* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<MyWidget::staticMetaObject>(),
    qt_meta_stringdata_GameWidget.data,
    qt_meta_data_GameWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget.stringdata0))
        return static_cast<void*>(this);
    return MyWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
