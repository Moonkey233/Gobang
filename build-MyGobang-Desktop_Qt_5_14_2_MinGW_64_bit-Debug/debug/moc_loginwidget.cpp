/****************************************************************************
** Meta object code from reading C++ file 'loginwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyGobang/src/widget/loginwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginWidget_t {
    QByteArrayData data[15];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWidget_t qt_meta_stringdata_LoginWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LoginWidget"
QT_MOC_LITERAL(1, 12, 25), // "setEmailAndPreviousSignal"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "email"
QT_MOC_LITERAL(4, 45, 8), // "previous"
QT_MOC_LITERAL(5, 54, 18), // "onForgetBtnClicked"
QT_MOC_LITERAL(6, 73, 17), // "onLoginBtnClicked"
QT_MOC_LITERAL(7, 91, 20), // "onRegisterBtnClicked"
QT_MOC_LITERAL(8, 112, 18), // "onReturnBtnClicked"
QT_MOC_LITERAL(9, 131, 11), // "onAutoLogin"
QT_MOC_LITERAL(10, 143, 17), // "onCancelAutoLogin"
QT_MOC_LITERAL(11, 161, 15), // "onLoginResponse"
QT_MOC_LITERAL(12, 177, 6), // "cookie"
QT_MOC_LITERAL(13, 184, 8), // "userName"
QT_MOC_LITERAL(14, 193, 17) // "onReloginResponse"

    },
    "LoginWidget\0setEmailAndPreviousSignal\0"
    "\0email\0previous\0onForgetBtnClicked\0"
    "onLoginBtnClicked\0onRegisterBtnClicked\0"
    "onReturnBtnClicked\0onAutoLogin\0"
    "onCancelAutoLogin\0onLoginResponse\0"
    "cookie\0userName\0onReloginResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       1,    1,   69,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    3,   78,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,    3,   13,
    QMetaType::Void,

       0        // eod
};

void LoginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setEmailAndPreviousSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->setEmailAndPreviousSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onForgetBtnClicked(); break;
        case 3: _t->onLoginBtnClicked(); break;
        case 4: _t->onRegisterBtnClicked(); break;
        case 5: _t->onReturnBtnClicked(); break;
        case 6: _t->onAutoLogin(); break;
        case 7: _t->onCancelAutoLogin(); break;
        case 8: _t->onLoginResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: _t->onReloginResponse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginWidget::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWidget::setEmailAndPreviousSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LoginWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<MyWidget::staticMetaObject>(),
    qt_meta_stringdata_LoginWidget.data,
    qt_meta_data_LoginWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWidget.stringdata0))
        return static_cast<void*>(this);
    return MyWidget::qt_metacast(_clname);
}

int LoginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void LoginWidget::setEmailAndPreviousSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
