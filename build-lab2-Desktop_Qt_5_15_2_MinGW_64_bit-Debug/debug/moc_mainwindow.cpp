/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "DialogMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "std::string"
QT_MOC_LITERAL(4, 38, 5), // "quest"
QT_MOC_LITERAL(5, 44, 11), // "instruction"
QT_MOC_LITERAL(6, 56, 8), // "ShowMenu"
QT_MOC_LITERAL(7, 65, 8), // "HideMenu"
QT_MOC_LITERAL(8, 74, 12), // "ShowLineEdit"
QT_MOC_LITERAL(9, 87, 12), // "HideLineEdit"
QT_MOC_LITERAL(10, 100, 11), // "ShowAddEdge"
QT_MOC_LITERAL(11, 112, 24), // "on_IntegerButton_clicked"
QT_MOC_LITERAL(12, 137, 21), // "on_BackButton_clicked"
QT_MOC_LITERAL(13, 159, 23), // "on_DoubleButton_clicked"
QT_MOC_LITERAL(14, 183, 23), // "on_StringButton_clicked"
QT_MOC_LITERAL(15, 207, 21), // "on_ExitButton_clicked"
QT_MOC_LITERAL(16, 229, 29), // "on_EnterStartPoint_textEdited"
QT_MOC_LITERAL(17, 259, 4), // "arg1"
QT_MOC_LITERAL(18, 264, 30), // "on_EnterFinishPoint_textEdited"
QT_MOC_LITERAL(19, 295, 31), // "on_EnterWeightString_textEdited"
QT_MOC_LITERAL(20, 327, 31), // "on_EnterWeightDouble_textEdited"
QT_MOC_LITERAL(21, 359, 28) // "on_EnterWeightInt_textEdited"

    },
    "MainWindow\0DialogMessage\0\0std::string\0"
    "quest\0instruction\0ShowMenu\0HideMenu\0"
    "ShowLineEdit\0HideLineEdit\0ShowAddEdge\0"
    "on_IntegerButton_clicked\0on_BackButton_clicked\0"
    "on_DoubleButton_clicked\0on_StringButton_clicked\0"
    "on_ExitButton_clicked\0"
    "on_EnterStartPoint_textEdited\0arg1\0"
    "on_EnterFinishPoint_textEdited\0"
    "on_EnterWeightString_textEdited\0"
    "on_EnterWeightDouble_textEdited\0"
    "on_EnterWeightInt_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    1,  109,    2, 0x08 /* Private */,
      18,    1,  112,    2, 0x08 /* Private */,
      19,    1,  115,    2, 0x08 /* Private */,
      20,    1,  118,    2, 0x08 /* Private */,
      21,    1,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->DialogMessage((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->ShowMenu(); break;
        case 2: _t->HideMenu(); break;
        case 3: _t->ShowLineEdit(); break;
        case 4: _t->HideLineEdit(); break;
        case 5: _t->ShowAddEdge(); break;
        case 6: _t->on_IntegerButton_clicked(); break;
        case 7: _t->on_BackButton_clicked(); break;
        case 8: _t->on_DoubleButton_clicked(); break;
        case 9: _t->on_StringButton_clicked(); break;
        case 10: _t->on_ExitButton_clicked(); break;
        case 11: _t->on_EnterStartPoint_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_EnterFinishPoint_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_EnterWeightString_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_EnterWeightDouble_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_EnterWeightInt_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
