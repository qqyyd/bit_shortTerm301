/********************************************************************************
** Form generated from reading UI file 'chatform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATFORM_H
#define UI_CHATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatForm
{
public:
    QWidget *widget;
    QLabel *friendName;
    QPlainTextEdit *inputEdit;
    QPushButton *sendBtn;
    QPushButton *closeBtn;
    QPushButton *miniBtn;
    QListWidget *listWidget;
    QLabel *underLine_2;
    QLabel *underLine;
    QWidget *voiceChatWidget;
    QRadioButton *highVBtn;
    QRadioButton *lowVBtn;
    QPushButton *VoiceStartBtn;

    void setupUi(QWidget *ChatForm)
    {
        if (ChatForm->objectName().isEmpty())
            ChatForm->setObjectName(QStringLiteral("ChatForm"));
        ChatForm->resize(432, 752);
        widget = new QWidget(ChatForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 1, 430, 750));
        widget->setStyleSheet(QLatin1String("\n"
"	background-color:#474a59;\n"
"	border-radius:10px;"));
        friendName = new QLabel(widget);
        friendName->setObjectName(QStringLiteral("friendName"));
        friendName->setGeometry(QRect(109, 0, 200, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        friendName->setFont(font);
        friendName->setStyleSheet(QStringLiteral("color:#c9c9c9;"));
        friendName->setAlignment(Qt::AlignCenter);
        inputEdit = new QPlainTextEdit(widget);
        inputEdit->setObjectName(QStringLiteral("inputEdit"));
        inputEdit->setGeometry(QRect(30, 680, 300, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(10);
        inputEdit->setFont(font1);
        inputEdit->setStyleSheet(QLatin1String("#inputEdit\n"
"{\n"
"	border-radius: 5px;\n"
"	border:1px solid #fff;\n"
"	color:#c9c9c9;\n"
"	padding:5px\n"
"}\n"
"#inputEdit:selected\n"
"{\n"
"	background-color:#fff;\n"
"}"));
        sendBtn = new QPushButton(widget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(340, 680, 60, 40));
        sendBtn->setFont(font1);
        sendBtn->setStyleSheet(QLatin1String("#sendBtn\n"
"{\n"
"	border-radius:5px;\n"
"	border:1px solid #fff;\n"
"	color:#c9c9c9;\n"
"    \n"
"}\n"
"#sendBtn:hover\n"
"{\n"
"	background:#fff;\n"
"	color:#000;\n"
"}"));
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setEnabled(true);
        closeBtn->setGeometry(QRect(380, 10, 40, 40));
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
        miniBtn = new QPushButton(widget);
        miniBtn->setObjectName(QStringLiteral("miniBtn"));
        miniBtn->setGeometry(QRect(340, 10, 40, 40));
        miniBtn->setStyleSheet(QLatin1String("#miniBtn{\n"
"\n"
"            border-radius: 5px;\n"
"}\n"
"#miniBtn:hover\n"
"{\n"
"            background-color: rgba(255,255,255,.3);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Asserts/icons/minimize.svg"), QSize(), QIcon::Normal, QIcon::Off);
        miniBtn->setIcon(icon1);
        miniBtn->setFlat(true);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 80, 390, 511));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        underLine_2 = new QLabel(widget);
        underLine_2->setObjectName(QStringLiteral("underLine_2"));
        underLine_2->setGeometry(QRect(30, 660, 370, 3));
        underLine_2->setStyleSheet(QLatin1String("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        underLine = new QLabel(widget);
        underLine->setObjectName(QStringLiteral("underLine"));
        underLine->setGeometry(QRect(30, 60, 370, 3));
        underLine->setStyleSheet(QLatin1String("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        voiceChatWidget = new QWidget(widget);
        voiceChatWidget->setObjectName(QStringLiteral("voiceChatWidget"));
        voiceChatWidget->setGeometry(QRect(30, 600, 370, 60));
        voiceChatWidget->setStyleSheet(QLatin1String("#voiceChatWidget\n"
"{\n"
"	background-color:transparent;\n"
"	border-radius:0px;\n"
"	border-top:1px solid #c9c9c9;\n"
"}"));
        highVBtn = new QRadioButton(voiceChatWidget);
        highVBtn->setObjectName(QStringLiteral("highVBtn"));
        highVBtn->setGeometry(QRect(0, 10, 40, 40));
        highVBtn->setFont(font1);
        highVBtn->setStyleSheet(QLatin1String("#highVBtn::indicator\n"
"{\n"
"	width:0;\n"
"}\n"
"#highVBtn\n"
"{\n"
"	border-radius:5px;\n"
"	color:#c9c9c9;\n"
"	padding-left:5px;\n"
"}\n"
"#highVBtn::unchecked\n"
"{\n"
"	border:1px solid #fff;\n"
"}\n"
"#highVBtn::checked\n"
"{\n"
"	border:3px solid #fff;\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));
        lowVBtn = new QRadioButton(voiceChatWidget);
        lowVBtn->setObjectName(QStringLiteral("lowVBtn"));
        lowVBtn->setGeometry(QRect(330, 10, 40, 40));
        lowVBtn->setFont(font1);
        lowVBtn->setStyleSheet(QLatin1String("#lowVBtn::indicator\n"
"{\n"
"	width:0;\n"
"}\n"
"#lowVBtn\n"
"{\n"
"	border-radius:5px;\n"
"	color:#c9c9c9;\n"
"	padding-left:5px;\n"
"}\n"
"#lowVBtn::unchecked\n"
"{\n"
"	border:1px solid #fff;\n"
"}\n"
"#lowVBtn::checked\n"
"{\n"
"	border:3px solid #fff;\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));
        VoiceStartBtn = new QPushButton(voiceChatWidget);
        VoiceStartBtn->setObjectName(QStringLiteral("VoiceStartBtn"));
        VoiceStartBtn->setGeometry(QRect(120, 10, 120, 40));
        VoiceStartBtn->setFont(font1);
        VoiceStartBtn->setStyleSheet(QLatin1String("#VoiceStartBtn\n"
"{\n"
"	border-radius:5px;\n"
"	color:#c9c9c9;\n"
"	border:1px solid #fff;\n"
"}\n"
"#VoiceStartBtn:hover\n"
"{\n"
"	border:3px solid #fff;\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));

        retranslateUi(ChatForm);

        QMetaObject::connectSlotsByName(ChatForm);
    } // setupUi

    void retranslateUi(QWidget *ChatForm)
    {
        ChatForm->setWindowTitle(QApplication::translate("ChatForm", "Form", Q_NULLPTR));
        friendName->setText(QApplication::translate("ChatForm", "\345\217\213\344\272\272A", Q_NULLPTR));
        inputEdit->setPlainText(QApplication::translate("ChatForm", "Hello world! \344\275\240\345\245\275\357\274\201", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("ChatForm", "\345\217\221\351\200\201", Q_NULLPTR));
        closeBtn->setText(QString());
        miniBtn->setText(QString());
        underLine_2->setText(QString());
        underLine->setText(QString());
        highVBtn->setText(QApplication::translate("ChatForm", "\351\253\230", Q_NULLPTR));
        lowVBtn->setText(QApplication::translate("ChatForm", "\344\275\216", Q_NULLPTR));
        VoiceStartBtn->setText(QApplication::translate("ChatForm", "\350\257\255\351\237\263\351\200\232\350\257\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatForm: public Ui_ChatForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATFORM_H
