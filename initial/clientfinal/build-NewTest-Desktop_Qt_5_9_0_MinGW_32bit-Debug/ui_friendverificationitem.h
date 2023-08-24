/********************************************************************************
** Form generated from reading UI file 'friendverificationitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDVERIFICATIONITEM_H
#define UI_FRIENDVERIFICATIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendVerificationItem
{
public:
    QLabel *friendName;
    QLabel *friendVerifiMsg;
    QPushButton *rejectionBtn;
    QPushButton *acceptBtn;
    QLabel *underLine;

    void setupUi(QWidget *FriendVerificationItem)
    {
        if (FriendVerificationItem->objectName().isEmpty())
            FriendVerificationItem->setObjectName(QStringLiteral("FriendVerificationItem"));
        FriendVerificationItem->resize(540, 90);
        friendName = new QLabel(FriendVerificationItem);
        friendName->setObjectName(QStringLiteral("friendName"));
        friendName->setGeometry(QRect(20, 20, 200, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        friendName->setFont(font);
        friendName->setStyleSheet(QLatin1String("color:#c9c9c9;\n"
"background-color:transparent;"));
        friendVerifiMsg = new QLabel(FriendVerificationItem);
        friendVerifiMsg->setObjectName(QStringLiteral("friendVerifiMsg"));
        friendVerifiMsg->setGeometry(QRect(20, 60, 300, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        friendVerifiMsg->setFont(font1);
        friendVerifiMsg->setStyleSheet(QLatin1String("color:#c9c9c9;\n"
"\n"
"background-color:transparent;"));
        rejectionBtn = new QPushButton(FriendVerificationItem);
        rejectionBtn->setObjectName(QStringLiteral("rejectionBtn"));
        rejectionBtn->setGeometry(QRect(350, 5, 80, 80));
        rejectionBtn->setStyleSheet(QLatin1String("#rejectionBtn\n"
"{\n"
"	border-radius:5px;\n"
"}\n"
"#rejectionBtn:hover\n"
"{\n"
"	background-color:rgba(255, 107, 109, 128);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Asserts/icons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        rejectionBtn->setIcon(icon);
        rejectionBtn->setIconSize(QSize(50, 50));
        rejectionBtn->setFlat(true);
        acceptBtn = new QPushButton(FriendVerificationItem);
        acceptBtn->setObjectName(QStringLiteral("acceptBtn"));
        acceptBtn->setGeometry(QRect(440, 5, 80, 80));
        acceptBtn->setStyleSheet(QLatin1String("#acceptBtn\n"
"{\n"
"	border-radius:5px;\n"
"}\n"
"#acceptBtn:hover\n"
"{\n"
"	background-color:rgba(32, 202, 100,0.5);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Asserts/icons/check.svg"), QSize(), QIcon::Normal, QIcon::Off);
        acceptBtn->setIcon(icon1);
        acceptBtn->setIconSize(QSize(50, 50));
        underLine = new QLabel(FriendVerificationItem);
        underLine->setObjectName(QStringLiteral("underLine"));
        underLine->setGeometry(QRect(10, 85, 520, 2));
        underLine->setStyleSheet(QLatin1String("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #2e3158 ,stop:0.33 #4f5178, stop:0.67 #727399,stop:1 #9697bc);\n"
"}"));

        retranslateUi(FriendVerificationItem);

        QMetaObject::connectSlotsByName(FriendVerificationItem);
    } // setupUi

    void retranslateUi(QWidget *FriendVerificationItem)
    {
        FriendVerificationItem->setWindowTitle(QApplication::translate("FriendVerificationItem", "Form", Q_NULLPTR));
        friendName->setText(QApplication::translate("FriendVerificationItem", "friendName", Q_NULLPTR));
        friendVerifiMsg->setText(QApplication::translate("FriendVerificationItem", "\346\210\221\346\230\257\344\275\240\347\210\270\347\210\270", Q_NULLPTR));
        rejectionBtn->setText(QString());
        acceptBtn->setText(QString());
        underLine->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendVerificationItem: public Ui_FriendVerificationItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDVERIFICATIONITEM_H
