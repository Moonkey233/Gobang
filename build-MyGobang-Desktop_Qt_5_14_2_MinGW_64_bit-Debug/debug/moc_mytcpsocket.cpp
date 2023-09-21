/****************************************************************************
** Meta object code from reading C++ file 'mytcpsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyGobang/src/tool/mytcpsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyTcpSocket_t {
    QByteArrayData data[28];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTcpSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTcpSocket_t qt_meta_stringdata_MyTcpSocket = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyTcpSocket"
QT_MOC_LITERAL(1, 12, 22), // "sigReturnConnectStatus"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "ConnectStatus"
QT_MOC_LITERAL(4, 50, 13), // "connectStatus"
QT_MOC_LITERAL(5, 64, 16), // "sigParseResponse"
QT_MOC_LITERAL(6, 81, 8), // "response"
QT_MOC_LITERAL(7, 90, 16), // "sigErrorResponse"
QT_MOC_LITERAL(8, 107, 5), // "error"
QT_MOC_LITERAL(9, 113, 16), // "sigLoginResponse"
QT_MOC_LITERAL(10, 130, 6), // "cookie"
QT_MOC_LITERAL(11, 137, 5), // "email"
QT_MOC_LITERAL(12, 143, 8), // "userName"
QT_MOC_LITERAL(13, 152, 19), // "sigPasswordResponse"
QT_MOC_LITERAL(14, 172, 18), // "sigReloginResponse"
QT_MOC_LITERAL(15, 191, 19), // "sigSendcodeResponse"
QT_MOC_LITERAL(16, 211, 19), // "sigRegisterResponse"
QT_MOC_LITERAL(17, 231, 19), // "sigSetpieceResponse"
QT_MOC_LITERAL(18, 251, 14), // "ChessPieceInfo"
QT_MOC_LITERAL(19, 266, 5), // "piece"
QT_MOC_LITERAL(20, 272, 15), // "sigJoinResponse"
QT_MOC_LITERAL(21, 288, 6), // "roomId"
QT_MOC_LITERAL(22, 295, 8), // "roomName"
QT_MOC_LITERAL(23, 304, 5), // "rival"
QT_MOC_LITERAL(24, 310, 9), // "ChessType"
QT_MOC_LITERAL(25, 320, 9), // "chessType"
QT_MOC_LITERAL(26, 330, 11), // "onReadyRead"
QT_MOC_LITERAL(27, 342, 15) // "onParseResponse"

    },
    "MyTcpSocket\0sigReturnConnectStatus\0\0"
    "ConnectStatus\0connectStatus\0"
    "sigParseResponse\0response\0sigErrorResponse\0"
    "error\0sigLoginResponse\0cookie\0email\0"
    "userName\0sigPasswordResponse\0"
    "sigReloginResponse\0sigSendcodeResponse\0"
    "sigRegisterResponse\0sigSetpieceResponse\0"
    "ChessPieceInfo\0piece\0sigJoinResponse\0"
    "roomId\0roomName\0rival\0ChessType\0"
    "chessType\0onReadyRead\0onParseResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTcpSocket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       7,    1,   80,    2, 0x06 /* Public */,
       9,    3,   83,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,
      14,    0,   91,    2, 0x06 /* Public */,
      15,    0,   92,    2, 0x06 /* Public */,
      16,    0,   93,    2, 0x06 /* Public */,
      17,    1,   94,    2, 0x06 /* Public */,
      20,    4,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    0,  106,    2, 0x08 /* Private */,
      27,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 24,   21,   22,   23,   25,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void MyTcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyTcpSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReturnConnectStatus((*reinterpret_cast< ConnectStatus(*)>(_a[1]))); break;
        case 1: _t->sigParseResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sigErrorResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sigLoginResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->sigPasswordResponse(); break;
        case 5: _t->sigReloginResponse(); break;
        case 6: _t->sigSendcodeResponse(); break;
        case 7: _t->sigRegisterResponse(); break;
        case 8: _t->sigSetpieceResponse((*reinterpret_cast< ChessPieceInfo(*)>(_a[1]))); break;
        case 9: _t->sigJoinResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const ChessType(*)>(_a[4]))); break;
        case 10: _t->onReadyRead(); break;
        case 11: _t->onParseResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyTcpSocket::*)(ConnectStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigReturnConnectStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigParseResponse)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigErrorResponse)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigLoginResponse)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigPasswordResponse)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigReloginResponse)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigSendcodeResponse)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigRegisterResponse)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)(ChessPieceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigSetpieceResponse)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MyTcpSocket::*)(const QString & , const QString & , const QString & , const ChessType & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTcpSocket::sigJoinResponse)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyTcpSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_meta_stringdata_MyTcpSocket.data,
    qt_meta_data_MyTcpSocket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyTcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTcpSocket.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int MyTcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MyTcpSocket::sigReturnConnectStatus(ConnectStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTcpSocket::sigParseResponse(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTcpSocket::sigErrorResponse(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTcpSocket::sigLoginResponse(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTcpSocket::sigPasswordResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MyTcpSocket::sigReloginResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MyTcpSocket::sigSendcodeResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MyTcpSocket::sigRegisterResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MyTcpSocket::sigSetpieceResponse(ChessPieceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyTcpSocket::sigJoinResponse(const QString & _t1, const QString & _t2, const QString & _t3, const ChessType & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
