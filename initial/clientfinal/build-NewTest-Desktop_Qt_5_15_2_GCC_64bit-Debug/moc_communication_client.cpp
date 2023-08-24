/****************************************************************************
** Meta object code from reading C++ file 'communication_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../NewTest/communication_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Communication_client_t {
    QByteArrayData data[18];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communication_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communication_client_t qt_meta_stringdata_Communication_client = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Communication_client"
QT_MOC_LITERAL(1, 21, 24), // "new_string_message_ready"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 16), // "friendList_ready"
QT_MOC_LITERAL(4, 64, 21), // "QVector<PersonalInfo>"
QT_MOC_LITERAL(5, 86, 20), // "request_recode_ready"
QT_MOC_LITERAL(6, 107, 37), // "QVector<QPair<PersonalInfo,QS..."
QT_MOC_LITERAL(7, 145, 17), // "chat_recode_ready"
QT_MOC_LITERAL(8, 163, 42), // "QVector<QPair<QString,QVector..."
QT_MOC_LITERAL(9, 206, 14), // "login_feedback"
QT_MOC_LITERAL(10, 221, 17), // "register_feedback"
QT_MOC_LITERAL(11, 239, 18), // "find_friend_result"
QT_MOC_LITERAL(12, 258, 14), // "friend_request"
QT_MOC_LITERAL(13, 273, 12), // "PersonalInfo"
QT_MOC_LITERAL(14, 286, 16), // "new_friend_added"
QT_MOC_LITERAL(15, 303, 11), // "be_rejected"
QT_MOC_LITERAL(16, 315, 23), // "head_image_change_state"
QT_MOC_LITERAL(17, 339, 23) // "usersMotto_change_state"

    },
    "Communication_client\0new_string_message_ready\0"
    "\0friendList_ready\0QVector<PersonalInfo>\0"
    "request_recode_ready\0"
    "QVector<QPair<PersonalInfo,QString> >\0"
    "chat_recode_ready\0"
    "QVector<QPair<QString,QVector<QString> > >\0"
    "login_feedback\0register_feedback\0"
    "find_friend_result\0friend_request\0"
    "PersonalInfo\0new_friend_added\0be_rejected\0"
    "head_image_change_state\0usersMotto_change_state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communication_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       3,    1,   79,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       7,    1,   85,    2, 0x06 /* Public */,
       9,    1,   88,    2, 0x06 /* Public */,
      10,    1,   91,    2, 0x06 /* Public */,
      11,    1,   94,    2, 0x06 /* Public */,
      12,    2,   97,    2, 0x06 /* Public */,
      14,    1,  102,    2, 0x06 /* Public */,
      15,    1,  105,    2, 0x06 /* Public */,
      16,    1,  108,    2, 0x06 /* Public */,
      17,    1,  111,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Communication_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Communication_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_string_message_ready((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->friendList_ready((*reinterpret_cast< QVector<PersonalInfo>(*)>(_a[1]))); break;
        case 2: _t->request_recode_ready((*reinterpret_cast< QVector<QPair<PersonalInfo,QString> >(*)>(_a[1]))); break;
        case 3: _t->chat_recode_ready((*reinterpret_cast< QVector<QPair<QString,QVector<QString> > >(*)>(_a[1]))); break;
        case 4: _t->login_feedback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->register_feedback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->find_friend_result((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->friend_request((*reinterpret_cast< PersonalInfo(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->new_friend_added((*reinterpret_cast< PersonalInfo(*)>(_a[1]))); break;
        case 9: _t->be_rejected((*reinterpret_cast< PersonalInfo(*)>(_a[1]))); break;
        case 10: _t->head_image_change_state((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->usersMotto_change_state((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Communication_client::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::new_string_message_ready)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(QVector<PersonalInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::friendList_ready)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(QVector<QPair<PersonalInfo,QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::request_recode_ready)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(QVector<QPair<QString,QVector<QString>> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::chat_recode_ready)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::login_feedback)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::register_feedback)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::find_friend_result)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(PersonalInfo , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::friend_request)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(PersonalInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::new_friend_added)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(PersonalInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::be_rejected)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::head_image_change_state)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Communication_client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication_client::usersMotto_change_state)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Communication_client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Communication_client.data,
    qt_meta_data_Communication_client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Communication_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communication_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Communication_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Communication_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Communication_client::new_string_message_ready(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Communication_client::friendList_ready(QVector<PersonalInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communication_client::request_recode_ready(QVector<QPair<PersonalInfo,QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communication_client::chat_recode_ready(QVector<QPair<QString,QVector<QString>> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communication_client::login_feedback(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communication_client::register_feedback(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Communication_client::find_friend_result(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Communication_client::friend_request(PersonalInfo _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Communication_client::new_friend_added(PersonalInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Communication_client::be_rejected(PersonalInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Communication_client::head_image_change_state(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Communication_client::usersMotto_change_state(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
