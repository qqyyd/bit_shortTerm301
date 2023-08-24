/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QWidget *shell;
    QWidget *boxleft;
    QLabel *LoginLabel;
    QTextBrowser *Describe;
    QWidget *boxright;
    QLabel *usersNameLabel;
    QLabel *PasswordLabel;
    QLineEdit *usersName;
    QLabel *underLine;
    QLabel *underLine_2;
    QLineEdit *Password;
    QPushButton *submit;
    QPushButton *signup;
    QPushButton *closeBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1172, 672);
        Widget->setStyleSheet(QString::fromUtf8("#Widget\n"
"{ \n"
"	background-color: transprant;\n"
"}"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 1, 1170, 670));
        widget->setStyleSheet(QString::fromUtf8("#widget\n"
"{ \n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #519ef6,stop:0.33 #a4a8d6,stop:0.67 #d6b3b6, stop:1  #febf94);\n"
"	border-radius: 20px;\n"
"}\n"
""));
        shell = new QWidget(widget);
        shell->setObjectName(QString::fromUtf8("shell"));
        shell->setGeometry(QRect(200, 160, 800, 350));
        shell->setStyleSheet(QString::fromUtf8("#shell{\n"
"	width: 640px;\n"
"	height: 320px;\n"
"\n"
"}"));
        boxleft = new QWidget(shell);
        boxleft->setObjectName(QString::fromUtf8("boxleft"));
        boxleft->setGeometry(QRect(0, 20, 400, 310));
        boxleft->setStyleSheet(QString::fromUtf8("#boxleft{\n"
"            background-color: #fff;\n"
"            height: 280px;\n"
"            top: 20px;\n"
"            position: relative;\n"
"            width: 50%;\n"
"}"));
        LoginLabel = new QLabel(boxleft);
        LoginLabel->setObjectName(QString::fromUtf8("LoginLabel"));
        LoginLabel->setGeometry(QRect(0, 0, 401, 171));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        LoginLabel->setFont(font);
        LoginLabel->setStyleSheet(QString::fromUtf8("	color: #474a59;\n"
"    font: 900 50px '';\n"
"    margin: 50px 40px 40px;\n"
"	font:\"Arial Black\";"));
        Describe = new QTextBrowser(boxleft);
        Describe->setObjectName(QString::fromUtf8("Describe"));
        Describe->setGeometry(QRect(-5, 171, 411, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(false);
        Describe->setFont(font1);
        Describe->setStyleSheet(QString::fromUtf8("#Describe{\n"
"	line-height:20px;\n"
"    color: #999;\n"
"    font-style: 14px;\n"
"    margin: 40px;\n"
"	border:none;\n"
"}"));
        boxright = new QWidget(shell);
        boxright->setObjectName(QString::fromUtf8("boxright"));
        boxright->setGeometry(QRect(400, 0, 400, 350));
        boxright->setStyleSheet(QString::fromUtf8("#boxright{\n"
"	background-color: #474a59;\n"
"	border-radius: 15px;\n"
"    color: #f1f1f2;\n"
"    width: 50%;\n"
"	border-top: 1px solid QLinearGradient(y0:0, y1:1,stop: 0 #DADADA, stop: 1 transparent);\n"
"	border-left: 1px solid QLinearGradient(x0:0, x1:1,stop: 0 #DADADA, stop: 1 transparent);\n"
"	border-bottom: 1px solid QLinearGradient(y0:0, y1:1,stop: 0 transparent, stop: 1  #DADADA);\n"
"	border-right: 1px solid QLinearGradient(x0:0, x1:1,stop:  0 transparent, stop: 1 #DADADA);\n"
"}"));
        usersNameLabel = new QLabel(boxright);
        usersNameLabel->setObjectName(QString::fromUtf8("usersNameLabel"));
        usersNameLabel->setGeometry(QRect(30, 0, 371, 91));
        usersNameLabel->setFont(font);
        usersNameLabel->setStyleSheet(QString::fromUtf8("#usersNameLabel{\n"
"	color: #c2c2c5;\n"
"    font-size: 18px;\n"
"	font:\"Arial Black\";\n"
"    margin-top: 20px;\n"
"    margin-bottom: 5px;\n"
"    position: relative;\n"
"}"));
        PasswordLabel = new QLabel(boxright);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(30, 140, 371, 91));
        PasswordLabel->setFont(font);
        PasswordLabel->setStyleSheet(QString::fromUtf8("#PasswordLabel{\n"
"	color: #c2c2c5;\n"
"    font-size: 18px;\n"
"    margin-top: 20px;\n"
"	font:\"Arial Black\";\n"
"    margin-bottom: 5px;\n"
"    position: relative;\n"
"}"));
        usersName = new QLineEdit(boxright);
        usersName->setObjectName(QString::fromUtf8("usersName"));
        usersName->setGeometry(QRect(40, 70, 331, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font2.setPointSize(12);
        usersName->setFont(font2);
        usersName->setStyleSheet(QString::fromUtf8("#usersName\n"
"{\n"
"	background: transparent;\n"
"    border: 0;\n"
"    color: #f2f2f2;\n"
"    font-style: 20px;\n"
"    height: 30px;\n"
"    line-height: 30px;\n"
"    width: 100%;\n"
"    outline: none !important;\n"
"}"));
        underLine = new QLabel(boxright);
        underLine->setObjectName(QString::fromUtf8("underLine"));
        underLine->setGeometry(QRect(40, 121, 330, 3));
        underLine->setStyleSheet(QString::fromUtf8("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        underLine_2 = new QLabel(boxright);
        underLine_2->setObjectName(QString::fromUtf8("underLine_2"));
        underLine_2->setGeometry(QRect(40, 261, 330, 3));
        underLine_2->setStyleSheet(QString::fromUtf8("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        Password = new QLineEdit(boxright);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(40, 210, 331, 51));
        Password->setFont(font2);
        Password->setStyleSheet(QString::fromUtf8("#Password\n"
"{\n"
"	background: transparent;\n"
"    border: 0;\n"
"    color: #f2f2f2;\n"
"    font-style: 20px;\n"
"    height: 30px;\n"
"    line-height: 30px;\n"
"    width: 100%;\n"
"    outline: none !important;\n"
"}"));
        Password->setEchoMode(QLineEdit::Password);
        submit = new QPushButton(boxright);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(212, 247, 141, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Black"));
        font3.setPointSize(9);
        submit->setFont(font3);
        submit->setStyleSheet(QString::fromUtf8("#submit{\n"
"			color: #c2c2c5;\n"
"            margin-top: 40px;\n"
"            width: 100px;\n"
"            height: 35px;\n"
"            background-color: rgba(255,255,255,.1);\n"
"            border-radius: 20px;\n"
"            float: right;\n"
"        }\n"
"#submit:hover{\n"
"            color: #474a59;\n"
"            background-color: #fff;\n"
"}"));
        submit->setFlat(false);
        signup = new QPushButton(boxright);
        signup->setObjectName(QString::fromUtf8("signup"));
        signup->setGeometry(QRect(45, 247, 141, 81));
        signup->setFont(font3);
        signup->setStyleSheet(QString::fromUtf8("#signup{\n"
"			color: #c2c2c5;\n"
"            margin-top: 40px;\n"
"            width: 100px;\n"
"            height: 35px;\n"
"            background-color: rgba(255,255,255,.1);\n"
"            border-radius: 20px;\n"
"            float: right;\n"
"        }\n"
"#signup:hover{\n"
"            color: #474a59;\n"
"            background-color: #fff;\n"
"}"));
        signup->setFlat(false);
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setEnabled(true);
        closeBtn->setGeometry(QRect(1120, 10, 40, 40));
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

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        LoginLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:30pt; font-weight:600;\">Login</span></p></body></html>", nullptr));
        Describe->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\347\255\211\347\272\277'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:3px;\"><span style=\" font-size:14pt; font-weight:400;\">\344\275\240\346\211\200\347\203\255\347\210\261\347\232\204\357\274\214\344\275\240\347\232\204\347\224\237\346\264\273</span></p></body></html>", nullptr));
        usersNameLabel->setText(QCoreApplication::translate("Widget", "Your Name", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("Widget", "Password", nullptr));
        usersName->setText(QString());
        usersName->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        underLine->setText(QString());
        underLine_2->setText(QString());
        Password->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        submit->setText(QCoreApplication::translate("Widget", "Log in", nullptr));
        signup->setText(QCoreApplication::translate("Widget", "Sign Up", nullptr));
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
