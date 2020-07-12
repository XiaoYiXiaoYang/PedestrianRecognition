/****************************************************************************
** Meta object code from reading C++ file 'persondata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../persondata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'persondata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PersonData_t {
    QByteArrayData data[13];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PersonData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PersonData_t qt_meta_stringdata_PersonData = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PersonData"
QT_MOC_LITERAL(1, 11, 12), // "showErrorMsg"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "QString&"
QT_MOC_LITERAL(4, 34, 6), // "strMsg"
QT_MOC_LITERAL(5, 41, 18), // "slotBtnSearchClick"
QT_MOC_LITERAL(6, 60, 15), // "slotBtnPreClick"
QT_MOC_LITERAL(7, 76, 16), // "slotBtnNextClick"
QT_MOC_LITERAL(8, 93, 23), // "slotLineEditingFinished"
QT_MOC_LITERAL(9, 117, 16), // "slotShowErrorMsg"
QT_MOC_LITERAL(10, 134, 8), // "strError"
QT_MOC_LITERAL(11, 143, 23), // "slotShowTableItemDetail"
QT_MOC_LITERAL(12, 167, 17) // "QTableWidgetItem*"

    },
    "PersonData\0showErrorMsg\0\0QString&\0"
    "strMsg\0slotBtnSearchClick\0slotBtnPreClick\0"
    "slotBtnNextClick\0slotLineEditingFinished\0"
    "slotShowErrorMsg\0strError\0"
    "slotShowTableItemDetail\0QTableWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    1,   56,    2, 0x08 /* Private */,
      11,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void PersonData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PersonData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showErrorMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotBtnSearchClick(); break;
        case 2: _t->slotBtnPreClick(); break;
        case 3: _t->slotBtnNextClick(); break;
        case 4: _t->slotLineEditingFinished(); break;
        case 5: _t->slotShowErrorMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotShowTableItemDetail((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PersonData::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PersonData::showErrorMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PersonData::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PersonData.data,
    qt_meta_data_PersonData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PersonData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PersonData.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PersonData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PersonData::showErrorMsg(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
