/********************************************************************************
** Form generated from reading UI file 'registerform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERFORM_H
#define UI_REGISTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <verification.h>

QT_BEGIN_NAMESPACE

class Ui_registerForm
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
    QPushButton *ConfirmBtn;
    QPushButton *ReturnBtn;
    QLabel *underLine_3;
    QLineEdit *PasswordConfirmed;
    QLabel *PasswordConfirmedLabel;
    QLabel *PasswordStrong;
    QLabel *PasswordStrongLable;
    Verification *verification_code;
    QLineEdit *verification;
    QLabel *label;

    void setupUi(QWidget *registerForm)
    {
        if (registerForm->objectName().isEmpty())
            registerForm->setObjectName(QStringLiteral("registerForm"));
        registerForm->resize(1172, 672);
        widget = new QWidget(registerForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 1, 1170, 670));
        widget->setStyleSheet(QLatin1String("#widget\n"
"{ \n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #febf94,stop:0.33 #d6b3b6,stop:0.67 #a4a8d6, stop:1 #519ef6);\n"
"	border-radius: 20px;\n"
"}\n"
""));
        shell = new QWidget(widget);
        shell->setObjectName(QStringLiteral("shell"));
        shell->setGeometry(QRect(200, 35, 800, 600));
        shell->setStyleSheet(QLatin1String("	width: 640px;\n"
"	height: 320px;"));
        boxleft = new QWidget(shell);
        boxleft->setObjectName(QStringLiteral("boxleft"));
        boxleft->setGeometry(QRect(0, 145, 400, 310));
        boxleft->setStyleSheet(QLatin1String("            background-color: #fff;\n"
"            height: 280px;\n"
"            top: 20px;\n"
"            position: relative;\n"
"            width: 50%;"));
        LoginLabel = new QLabel(boxleft);
        LoginLabel->setObjectName(QStringLiteral("LoginLabel"));
        LoginLabel->setGeometry(QRect(0, 0, 401, 171));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        LoginLabel->setFont(font);
        LoginLabel->setStyleSheet(QLatin1String("	color: #474a59;\n"
"    font: 900 50px '';\n"
"    margin: 50px 40px 40px;\n"
"	font:\"Arial Black\";"));
        Describe = new QTextBrowser(boxleft);
        Describe->setObjectName(QStringLiteral("Describe"));
        Describe->setGeometry(QRect(-5, 171, 411, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(false);
        Describe->setFont(font1);
        Describe->setStyleSheet(QLatin1String("\n"
"	line-height:20px;\n"
"    color: #999;\n"
"    font-style: 14px;\n"
"    margin: 40px;\n"
"	border:none;\n"
""));
        boxright = new QWidget(shell);
        boxright->setObjectName(QStringLiteral("boxright"));
        boxright->setGeometry(QRect(400, 0, 400, 600));
        boxright->setStyleSheet(QLatin1String("#boxright{\n"
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
        usersNameLabel->setObjectName(QStringLiteral("usersNameLabel"));
        usersNameLabel->setGeometry(QRect(30, -10, 370, 90));
        usersNameLabel->setFont(font);
        usersNameLabel->setStyleSheet(QLatin1String("#usersNameLabel{\n"
"	color: #c2c2c5;\n"
"    font-size: 18px;\n"
"	font:\"Arial Black\";\n"
"    margin-top: 20px;\n"
"    margin-bottom: 5px;\n"
"    position: relative;\n"
"}"));
        PasswordLabel = new QLabel(boxright);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(30, 110, 370, 90));
        PasswordLabel->setFont(font);
        PasswordLabel->setStyleSheet(QLatin1String("#PasswordLabel{\n"
"	color: #c2c2c5;\n"
"    font-size: 18px;\n"
"    margin-top: 20px;\n"
"	font:\"Arial Black\";\n"
"    margin-bottom: 5px;\n"
"    position: relative;\n"
"}"));
        usersName = new QLineEdit(boxright);
        usersName->setObjectName(QStringLiteral("usersName"));
        usersName->setGeometry(QRect(40, 70, 320, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font2.setPointSize(12);
        usersName->setFont(font2);
        usersName->setStyleSheet(QLatin1String("#usersName\n"
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
        underLine->setObjectName(QStringLiteral("underLine"));
        underLine->setGeometry(QRect(40, 120, 320, 3));
        underLine->setStyleSheet(QLatin1String("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        underLine_2 = new QLabel(boxright);
        underLine_2->setObjectName(QStringLiteral("underLine_2"));
        underLine_2->setGeometry(QRect(40, 240, 330, 3));
        underLine_2->setStyleSheet(QLatin1String("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        Password = new QLineEdit(boxright);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(40, 190, 320, 50));
        Password->setFont(font2);
        Password->setStyleSheet(QLatin1String("#Password\n"
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
        ConfirmBtn = new QPushButton(boxright);
        ConfirmBtn->setObjectName(QStringLiteral("ConfirmBtn"));
        ConfirmBtn->setGeometry(QRect(219, 520, 141, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Black"));
        font3.setPointSize(9);
        ConfirmBtn->setFont(font3);
        ConfirmBtn->setStyleSheet(QLatin1String("#ConfirmBtn{\n"
"			color: #c2c2c5;\n"
"            background-color: rgba(255,255,255,.1);\n"
"            border-radius: 20px;\n"
"            float: right;\n"
"        }\n"
"#ConfirmBtn:hover{\n"
"            color: #474a59;\n"
"            background-color: #fff;\n"
"}"));
        ConfirmBtn->setFlat(false);
        ReturnBtn = new QPushButton(boxright);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));
        ReturnBtn->setGeometry(QRect(40, 520, 141, 40));
        ReturnBtn->setFont(font3);
        ReturnBtn->setStyleSheet(QLatin1String("#ReturnBtn{\n"
"			color: #c2c2c5;\n"
"            border-radius: 20px;\n"
"            background-color: rgba(255,255,255,.1);\n"
"            float: right;\n"
"        }\n"
"#ReturnBtn:hover{\n"
"            color: #474a59;\n"
"            background-color: #fff;\n"
"}"));
        ReturnBtn->setFlat(false);
        underLine_3 = new QLabel(boxright);
        underLine_3->setObjectName(QStringLiteral("underLine_3"));
        underLine_3->setGeometry(QRect(40, 360, 330, 3));
        underLine_3->setStyleSheet(QLatin1String("#underLine_3\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        PasswordConfirmed = new QLineEdit(boxright);
        PasswordConfirmed->setObjectName(QStringLiteral("PasswordConfirmed"));
        PasswordConfirmed->setGeometry(QRect(40, 310, 320, 50));
        PasswordConfirmed->setFont(font2);
        PasswordConfirmed->setStyleSheet(QLatin1String("#PasswordConfirmed\n"
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
        PasswordConfirmed->setEchoMode(QLineEdit::Password);
        PasswordConfirmedLabel = new QLabel(boxright);
        PasswordConfirmedLabel->setObjectName(QStringLiteral("PasswordConfirmedLabel"));
        PasswordConfirmedLabel->setGeometry(QRect(30, 230, 370, 90));
        PasswordConfirmedLabel->setFont(font);
        PasswordConfirmedLabel->setStyleSheet(QLatin1String("#PasswordConfirmedLabel{\n"
"	color: #c2c2c5;\n"
"    font-size: 18px;\n"
"    margin-top: 20px;\n"
"	font:\"Arial Black\";\n"
"    margin-bottom: 5px;\n"
"    position: relative;\n"
"}"));
        PasswordStrong = new QLabel(boxright);
        PasswordStrong->setObjectName(QStringLiteral("PasswordStrong"));
        PasswordStrong->setGeometry(QRect(330, 140, 40, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font4.setPointSize(9);
        PasswordStrong->setFont(font4);
        PasswordStrong->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:#c9c9c9;"));
        PasswordStrongLable = new QLabel(boxright);
        PasswordStrongLable->setObjectName(QStringLiteral("PasswordStrongLable"));
        PasswordStrongLable->setGeometry(QRect(249, 140, 71, 50));
        PasswordStrongLable->setFont(font4);
        PasswordStrongLable->setStyleSheet(QStringLiteral("color:#c9c9c9;"));
        verification_code = new Verification(boxright);
        verification_code->setObjectName(QStringLiteral("verification_code"));
        verification_code->setGeometry(QRect(260, 430, 100, 40));
        verification = new QLineEdit(boxright);
        verification->setObjectName(QStringLiteral("verification"));
        verification->setGeometry(QRect(30, 430, 221, 40));
        verification->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border:1px solid #c9c9c9;\n"
"border-radius:5px;"));
        label = new QLabel(boxright);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 350, 241, 90));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("#label{\n"
"	color: #c2c2c5;\n"
"    font-size: 18px;\n"
"    margin-top: 20px;\n"
"	font:\"Arial Black\";\n"
"    margin-bottom: 5px;\n"
"    position: relative;\n"
"}"));

        retranslateUi(registerForm);

        QMetaObject::connectSlotsByName(registerForm);
    } // setupUi

    void retranslateUi(QWidget *registerForm)
    {
        registerForm->setWindowTitle(QApplication::translate("registerForm", "Form", Q_NULLPTR));
        LoginLabel->setText(QApplication::translate("registerForm", "<html><head/><body><p><span style=\" font-size:30pt; font-weight:600;\">Sign Up</span></p></body></html>", Q_NULLPTR));
        Describe->setHtml(QApplication::translate("registerForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\347\255\211\347\272\277'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:3px;\"><span style=\" font-size:14pt; font-weight:400;\">Qt\346\262\273\345\245\275\344\272\206\346\210\221\347\232\204\347\262\276\347\245\236\345\206\205\350\200\227</span></p></body></html>", Q_NULLPTR));
        usersNameLabel->setText(QApplication::translate("registerForm", "Your Name", Q_NULLPTR));
        PasswordLabel->setText(QApplication::translate("registerForm", "Password", Q_NULLPTR));
        usersName->setText(QString());
        usersName->setPlaceholderText(QApplication::translate("registerForm", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", Q_NULLPTR));
        underLine->setText(QString());
        underLine_2->setText(QString());
        Password->setPlaceholderText(QApplication::translate("registerForm", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("registerForm", "Confirm", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("registerForm", "Return", Q_NULLPTR));
        underLine_3->setText(QString());
        PasswordConfirmed->setPlaceholderText(QApplication::translate("registerForm", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        PasswordConfirmedLabel->setText(QApplication::translate("registerForm", "Confirm Your Password", Q_NULLPTR));
        PasswordStrong->setText(QApplication::translate("registerForm", "\346\234\252\347\237\245", Q_NULLPTR));
        PasswordStrongLable->setText(QApplication::translate("registerForm", "\345\257\206\347\240\201\345\274\272\345\272\246\357\274\232", Q_NULLPTR));
        verification_code->setText(QApplication::translate("registerForm", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("registerForm", "Verification", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registerForm: public Ui_registerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERFORM_H
