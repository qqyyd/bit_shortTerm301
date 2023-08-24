/********************************************************************************
** Form generated from reading UI file 'addpersonform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONFORM_H
#define UI_ADDPERSONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            AddPersonForm->setObjectName(QStringLiteral("AddPersonForm"));
        AddPersonForm->resize(482, 312);
        widget = new QWidget(AddPersonForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 1, 480, 310));
        widget->setStyleSheet(QLatin1String("background-color:#474a59;\n"
"border:none;\n"
"border-radius:15px"));
        addPersonLabel = new QLabel(widget);
        addPersonLabel->setObjectName(QStringLiteral("addPersonLabel"));
        addPersonLabel->setGeometry(QRect(30, 20, 200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        addPersonLabel->setFont(font);
        addPersonLabel->setStyleSheet(QStringLiteral("color:#c9c9c9;"));
        addPersonLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setEnabled(true);
        closeBtn->setGeometry(QRect(430, 10, 40, 40));
        closeBtn->setStyleSheet(QLatin1String("#closeBtn{\n"
"\n"
"            border-radius: 5px;\n"
"}\n"
"#closeBtn:hover\n"
"{\n"
"            background-color: rgba(255,255,255,.3);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Asserts/icons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setAutoDefault(false);
        closeBtn->setFlat(true);
        underLine_2 = new QLabel(widget);
        underLine_2->setObjectName(QStringLiteral("underLine_2"));
        underLine_2->setGeometry(QRect(30, 70, 420, 3));
        underLine_2->setStyleSheet(QLatin1String("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        searchNameEdit = new QLineEdit(widget);
        searchNameEdit->setObjectName(QStringLiteral("searchNameEdit"));
        searchNameEdit->setGeometry(QRect(50, 160, 281, 50));
        searchNameEdit->setStyleSheet(QLatin1String("#searchNameEdit\n"
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
        searchNameBtn->setObjectName(QStringLiteral("searchNameBtn"));
        searchNameBtn->setGeometry(QRect(350, 160, 70, 50));
        searchNameBtn->setStyleSheet(QLatin1String("#searchNameBtn:hover\n"
"{\n"
"	background-color:rgba(255,255,255,0.5);\n"
"	\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Asserts/icons/person_search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        searchNameBtn->setIcon(icon1);
        searchNameBtn->setIconSize(QSize(40, 40));
        hintLabel = new QLabel(widget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setGeometry(QRect(50, 230, 280, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font1.setPointSize(10);
        hintLabel->setFont(font1);
        hintLabel->setStyleSheet(QStringLiteral("color:#c9c9c9;"));
        hintLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(AddPersonForm);

        QMetaObject::connectSlotsByName(AddPersonForm);
    } // setupUi

    void retranslateUi(QWidget *AddPersonForm)
    {
        AddPersonForm->setWindowTitle(QApplication::translate("AddPersonForm", "Form", Q_NULLPTR));
        addPersonLabel->setText(QApplication::translate("AddPersonForm", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
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
