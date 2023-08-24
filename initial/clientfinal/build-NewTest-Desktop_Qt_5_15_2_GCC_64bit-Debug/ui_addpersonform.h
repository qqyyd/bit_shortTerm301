/********************************************************************************
** Form generated from reading UI file 'addpersonform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONFORM_H
#define UI_ADDPERSONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPersonForm
{
public:
    QWidget *widget;
    QLabel *addPersonLabel;
    QPushButton *closeBtn;
    QLabel *underLine_2;
    QLineEdit *searchNameEdit;
    QPushButton *searchNameBtn;
    QLabel *hintLabel;

    void setupUi(QWidget *AddPersonForm)
    {
        if (AddPersonForm->objectName().isEmpty())
            AddPersonForm->setObjectName(QString::fromUtf8("AddPersonForm"));
        AddPersonForm->resize(482, 312);
        widget = new QWidget(AddPersonForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 1, 480, 310));
        widget->setStyleSheet(QString::fromUtf8("background-color:#474a59;\n"
"border:none;\n"
"border-radius:15px"));
        addPersonLabel = new QLabel(widget);
        addPersonLabel->setObjectName(QString::fromUtf8("addPersonLabel"));
        addPersonLabel->setGeometry(QRect(30, 20, 200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        addPersonLabel->setFont(font);
        addPersonLabel->setStyleSheet(QString::fromUtf8("color:#c9c9c9;"));
        addPersonLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setEnabled(true);
        closeBtn->setGeometry(QRect(430, 10, 40, 40));
        closeBtn->setStyleSheet(QString::fromUtf8("#closeBtn{\n"
"\n"
"            border-radius: 5px;\n"
"}\n"
"#closeBtn:hover\n"
"{\n"
"            background-color: rgba(255,255,255,.3);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Asserts/icons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setAutoDefault(false);
        closeBtn->setFlat(true);
        underLine_2 = new QLabel(widget);
        underLine_2->setObjectName(QString::fromUtf8("underLine_2"));
        underLine_2->setGeometry(QRect(30, 70, 420, 3));
        underLine_2->setStyleSheet(QString::fromUtf8("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        searchNameEdit = new QLineEdit(widget);
        searchNameEdit->setObjectName(QString::fromUtf8("searchNameEdit"));
        searchNameEdit->setGeometry(QRect(50, 160, 281, 50));
        searchNameEdit->setStyleSheet(QString::fromUtf8("#searchNameEdit\n"
"{\n"
"	border:2px solid #c9c9c9;\n"
"	border-radius:5px;\n"
"	color:#c9c9c9;\n"
"}\n"
"#searchNameEdit:focus\n"
"{\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));
        searchNameBtn = new QPushButton(widget);
        searchNameBtn->setObjectName(QString::fromUtf8("searchNameBtn"));
        searchNameBtn->setGeometry(QRect(350, 160, 70, 50));
        searchNameBtn->setStyleSheet(QString::fromUtf8("#searchNameBtn:hover\n"
"{\n"
"	background-color:rgba(255,255,255,0.5);\n"
"	\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Asserts/icons/person_search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        searchNameBtn->setIcon(icon1);
        searchNameBtn->setIconSize(QSize(40, 40));
        hintLabel = new QLabel(widget);
        hintLabel->setObjectName(QString::fromUtf8("hintLabel"));
        hintLabel->setGeometry(QRect(50, 230, 280, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font1.setPointSize(10);
        hintLabel->setFont(font1);
        hintLabel->setStyleSheet(QString::fromUtf8("color:#c9c9c9;"));
        hintLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(AddPersonForm);

        QMetaObject::connectSlotsByName(AddPersonForm);
    } // setupUi

    void retranslateUi(QWidget *AddPersonForm)
    {
        AddPersonForm->setWindowTitle(QCoreApplication::translate("AddPersonForm", "Form", nullptr));
        addPersonLabel->setText(QCoreApplication::translate("AddPersonForm", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        closeBtn->setText(QString());
        underLine_2->setText(QString());
        searchNameBtn->setText(QString());
        hintLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddPersonForm: public Ui_AddPersonForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSONFORM_H
