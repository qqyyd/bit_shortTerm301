/********************************************************************************
** Form generated from reading UI file 'addpersonconfirm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONCONFIRM_H
#define UI_ADDPERSONCONFIRM_H

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

class Ui_AddPersonConfirm
{
public:
    QWidget *widget;
    QLabel *addPersonLabel;
    QPushButton *closeBtn;
    QLabel *underLine;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label;
    QLineEdit *verifiMsg;

    void setupUi(QWidget *AddPersonConfirm)
    {
        if (AddPersonConfirm->objectName().isEmpty())
            AddPersonConfirm->setObjectName(QStringLiteral("AddPersonConfirm"));
        AddPersonConfirm->resize(482, 312);
        widget = new QWidget(AddPersonConfirm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 480, 310));
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
        underLine = new QLabel(widget);
        underLine->setObjectName(QStringLiteral("underLine"));
        underLine->setGeometry(QRect(30, 70, 420, 3));
        underLine->setStyleSheet(QLatin1String("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        pushButton_ok = new QPushButton(widget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(320, 240, 120, 40));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy);
        pushButton_ok->setStyleSheet(QLatin1String("#pushButton_ok\n"
"{\n"
"	background-color:transparent;\n"
"	color:#fff;\n"
"	border:2px solid #fff;\n"
"	border-radius:5px;\n"
"}\n"
"#pushButton_ok:hover\n"
"{\n"
"	background-color:rgba(32, 202, 100,0.5);\n"
"	color:#fff;\n"
"}"));
        pushButton_cancel = new QPushButton(widget);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(190, 240, 120, 40));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);
        pushButton_cancel->setStyleSheet(QLatin1String("#pushButton_cancel\n"
"{\n"
"	background-color:transparent;\n"
"	color:#fff;\n"
"	border:2px solid #fff;\n"
"	border-radius:5px;\n"
"}\n"
"#pushButton_cancel:hover\n"
"{\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 380, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:#c9c9c9;"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verifiMsg = new QLineEdit(widget);
        verifiMsg->setObjectName(QStringLiteral("verifiMsg"));
        verifiMsg->setGeometry(QRect(60, 150, 350, 50));
        verifiMsg->setStyleSheet(QLatin1String("#verifiMsg\n"
"{\n"
"	border:2px solid #c9c9c9;\n"
"	border-radius:5px;	\n"
"	color:#fff;\n"
"}\n"
"#verifiMsg:focus\n"
"{\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));

        retranslateUi(AddPersonConfirm);

        QMetaObject::connectSlotsByName(AddPersonConfirm);
    } // setupUi

    void retranslateUi(QWidget *AddPersonConfirm)
    {
        AddPersonConfirm->setWindowTitle(QApplication::translate("AddPersonConfirm", "Form", Q_NULLPTR));
        addPersonLabel->setText(QApplication::translate("AddPersonConfirm", "\347\241\256\350\256\244\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        closeBtn->setText(QString());
        underLine->setText(QString());
        pushButton_ok->setText(QApplication::translate("AddPersonConfirm", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("AddPersonConfirm", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("AddPersonConfirm", "\351\252\214\350\257\201\346\266\210\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddPersonConfirm: public Ui_AddPersonConfirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSONCONFIRM_H
