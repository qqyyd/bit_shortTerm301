/********************************************************************************
** Form generated from reading UI file 'friendverification.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDVERIFICATION_H
#define UI_FRIENDVERIFICATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendVerification
{
public:
    QWidget *widget;
    QLabel *addPersonLabel;
    QPushButton *closeBtn;
    QLabel *underLine;
    QListWidget *listWidget;

    void setupUi(QWidget *FriendVerification)
    {
        if (FriendVerification->objectName().isEmpty())
            FriendVerification->setObjectName(QString::fromUtf8("FriendVerification"));
        FriendVerification->resize(602, 452);
        widget = new QWidget(FriendVerification);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 600, 450));
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
        closeBtn->setGeometry(QRect(540, 10, 40, 40));
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
        underLine = new QLabel(widget);
        underLine->setObjectName(QString::fromUtf8("underLine"));
        underLine->setGeometry(QRect(30, 70, 540, 3));
        underLine->setStyleSheet(QString::fromUtf8("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 90, 540, 320));

        retranslateUi(FriendVerification);

        QMetaObject::connectSlotsByName(FriendVerification);
    } // setupUi

    void retranslateUi(QWidget *FriendVerification)
    {
        FriendVerification->setWindowTitle(QCoreApplication::translate("FriendVerification", "Form", nullptr));
        addPersonLabel->setText(QCoreApplication::translate("FriendVerification", "\345\245\275\345\217\213\347\224\263\350\257\267", nullptr));
        closeBtn->setText(QString());
        underLine->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendVerification: public Ui_FriendVerification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDVERIFICATION_H
