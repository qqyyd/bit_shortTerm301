/********************************************************************************
** Form generated from reading UI file 'personalform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALFORM_H
#define UI_PERSONALFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalForm
{
public:
    QWidget *widget;
    QWidget *Header;
    QPushButton *closeBtn;
    QPushButton *miniBtn;
    QLabel *avatarImage;
    QLabel *UsersName;
    QPushButton *changeAvatarBtn;
    QLineEdit *usersMotto;
    QLabel *underLine;
    QListWidget *listWidget;
    QLabel *underLine_2;
    QPushButton *addPersonBtn;
    QPushButton *friendRequest;

    void setupUi(QWidget *PersonalForm)
    {
        if (PersonalForm->objectName().isEmpty())
            PersonalForm->setObjectName(QString::fromUtf8("PersonalForm"));
        PersonalForm->resize(402, 802);
        widget = new QWidget(PersonalForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 1, 400, 800));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"	\n"
"	background-color:#474a59;\n"
"	border-radius:10px;\n"
"\n"
"}"));
        Header = new QWidget(widget);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(1, 0, 400, 170));
        closeBtn = new QPushButton(Header);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setEnabled(true);
        closeBtn->setGeometry(QRect(350, 10, 40, 40));
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
        miniBtn = new QPushButton(Header);
        miniBtn->setObjectName(QString::fromUtf8("miniBtn"));
        miniBtn->setGeometry(QRect(310, 10, 40, 40));
        miniBtn->setStyleSheet(QString::fromUtf8("#miniBtn{\n"
"\n"
"            border-radius: 5px;\n"
"}\n"
"#miniBtn:hover\n"
"{\n"
"            background-color: rgba(255,255,255,.3);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Asserts/icons/minimize.svg"), QSize(), QIcon::Normal, QIcon::Off);
        miniBtn->setIcon(icon1);
        miniBtn->setFlat(true);
        avatarImage = new QLabel(Header);
        avatarImage->setObjectName(QString::fromUtf8("avatarImage"));
        avatarImage->setGeometry(QRect(20, 60, 100, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        avatarImage->setFont(font);
        avatarImage->setPixmap(QPixmap(QString::fromUtf8(":/Asserts/images/FishkoAvatar.png")));
        avatarImage->setScaledContents(true);
        UsersName = new QLabel(Header);
        UsersName->setObjectName(QString::fromUtf8("UsersName"));
        UsersName->setGeometry(QRect(130, 90, 150, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(14);
        UsersName->setFont(font1);
        UsersName->setStyleSheet(QString::fromUtf8("color:#c9c9c9;"));
        changeAvatarBtn = new QPushButton(Header);
        changeAvatarBtn->setObjectName(QString::fromUtf8("changeAvatarBtn"));
        changeAvatarBtn->setGeometry(QRect(20, 60, 100, 100));
        changeAvatarBtn->setStyleSheet(QString::fromUtf8("#changeAvatarBtn\n"
"{\n"
"	background-color:transparent;\n"
"	border-radius:50px\n"
"}\n"
"#changeAvatarBtn:hover\n"
"{\n"
"	border-radius:50px;\n"
"	border:3px solid #fff;\n"
"	background-color:rgba(255, 255, 255, 128);\n"
"}"));
        changeAvatarBtn->setFlat(true);
        usersMotto = new QLineEdit(Header);
        usersMotto->setObjectName(QString::fromUtf8("usersMotto"));
        usersMotto->setGeometry(QRect(129, 130, 251, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(10);
        usersMotto->setFont(font2);
        usersMotto->setStyleSheet(QString::fromUtf8("#usersMotto\n"
"{\n"
"	background-color:transparent;\n"
"	color:#c9c9c9;\n"
"	border:none;\n"
"}\n"
"#usersMotto:hover\n"
"{\n"
"	border-radius:5px;\n"
"	border:1px solid #fff;\n"
"}\n"
"#usersMotto:focus\n"
"{\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));
        miniBtn->raise();
        closeBtn->raise();
        UsersName->raise();
        avatarImage->raise();
        changeAvatarBtn->raise();
        usersMotto->raise();
        underLine = new QLabel(widget);
        underLine->setObjectName(QString::fromUtf8("underLine"));
        underLine->setGeometry(QRect(10, 180, 380, 3));
        underLine->setStyleSheet(QString::fromUtf8("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 200, 380, 521));
        listWidget->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        underLine_2 = new QLabel(widget);
        underLine_2->setObjectName(QString::fromUtf8("underLine_2"));
        underLine_2->setGeometry(QRect(10, 725, 380, 3));
        underLine_2->setStyleSheet(QString::fromUtf8("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        addPersonBtn = new QPushButton(widget);
        addPersonBtn->setObjectName(QString::fromUtf8("addPersonBtn"));
        addPersonBtn->setGeometry(QRect(340, 740, 40, 40));
        addPersonBtn->setStyleSheet(QString::fromUtf8("#addPersonBtn\n"
"{\n"
"	background-color:transparent;\n"
"	border:none;\n"
"	border-radius:5px;\n"
"}\n"
"#addPersonBtn:hover\n"
"{\n"
"	background-color: rgba(255,255,255,.3);\n"
"}\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Asserts/icons/person_add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        addPersonBtn->setIcon(icon2);
        addPersonBtn->setIconSize(QSize(30, 30));
        friendRequest = new QPushButton(widget);
        friendRequest->setObjectName(QString::fromUtf8("friendRequest"));
        friendRequest->setGeometry(QRect(290, 740, 40, 40));
        friendRequest->setStyleSheet(QString::fromUtf8("#friendRequest\n"
"{\n"
"	background-color:transparent;\n"
"	border:none;\n"
"	border-radius:5px;\n"
"}\n"
"#friendRequest:hover\n"
"{\n"
"	background-color: rgba(255,255,255,.3);\n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Asserts/icons/notifications.svg"), QSize(), QIcon::Normal, QIcon::Off);
        friendRequest->setIcon(icon3);
        friendRequest->setIconSize(QSize(30, 30));
        Header->raise();
        underLine->raise();
        listWidget->raise();
        underLine_2->raise();
        addPersonBtn->raise();
        friendRequest->raise();
        changeAvatarBtn->raise();

        retranslateUi(PersonalForm);

        QMetaObject::connectSlotsByName(PersonalForm);
    } // setupUi

    void retranslateUi(QWidget *PersonalForm)
    {
        PersonalForm->setWindowTitle(QCoreApplication::translate("PersonalForm", "Form", nullptr));
        closeBtn->setText(QString());
        miniBtn->setText(QString());
        avatarImage->setText(QString());
        UsersName->setText(QCoreApplication::translate("PersonalForm", "Fishko", nullptr));
        changeAvatarBtn->setText(QString());
        usersMotto->setText(QCoreApplication::translate("PersonalForm", "Qt\344\275\240\345\270\246\346\210\221\350\265\260\345\220\247qwqq", nullptr));
        underLine->setText(QString());
        underLine_2->setText(QString());
        addPersonBtn->setText(QString());
        friendRequest->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonalForm: public Ui_PersonalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALFORM_H
