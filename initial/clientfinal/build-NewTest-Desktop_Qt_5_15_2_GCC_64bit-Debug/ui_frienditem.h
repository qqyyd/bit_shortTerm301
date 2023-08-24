/********************************************************************************
** Form generated from reading UI file 'frienditem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDITEM_H
#define UI_FRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendItem
{
public:
    QLabel *friendAvatar;
    QLabel *friendName;
    QLabel *underLine;
    QPushButton *friendChatBtn;

    void setupUi(QWidget *FriendItem)
    {
        if (FriendItem->objectName().isEmpty())
            FriendItem->setObjectName(QString::fromUtf8("FriendItem"));
        FriendItem->resize(380, 120);
        friendAvatar = new QLabel(FriendItem);
        friendAvatar->setObjectName(QString::fromUtf8("friendAvatar"));
        friendAvatar->setGeometry(QRect(30, 20, 80, 80));
        friendAvatar->setPixmap(QPixmap(QString::fromUtf8(":/Asserts/images/friendAvatar.png")));
        friendAvatar->setScaledContents(true);
        friendName = new QLabel(FriendItem);
        friendName->setObjectName(QString::fromUtf8("friendName"));
        friendName->setGeometry(QRect(130, 20, 221, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(10);
        friendName->setFont(font);
        friendName->setStyleSheet(QString::fromUtf8("color:#c9c9c9;"));
        underLine = new QLabel(FriendItem);
        underLine->setObjectName(QString::fromUtf8("underLine"));
        underLine->setGeometry(QRect(20, 110, 340, 2));
        underLine->setStyleSheet(QString::fromUtf8("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #2e3158 ,stop:0.33 #4f5178, stop:0.67 #727399,stop:1 #9697bc);\n"
"}"));
        friendChatBtn = new QPushButton(FriendItem);
        friendChatBtn->setObjectName(QString::fromUtf8("friendChatBtn"));
        friendChatBtn->setGeometry(QRect(0, 0, 381, 141));
        friendChatBtn->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        friendChatBtn->setFlat(true);

        retranslateUi(FriendItem);

        QMetaObject::connectSlotsByName(FriendItem);
    } // setupUi

    void retranslateUi(QWidget *FriendItem)
    {
        FriendItem->setWindowTitle(QCoreApplication::translate("FriendItem", "Form", nullptr));
        friendAvatar->setText(QString());
        friendName->setText(QCoreApplication::translate("FriendItem", "friendName", nullptr));
        underLine->setText(QString());
        friendChatBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendItem: public Ui_FriendItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDITEM_H
