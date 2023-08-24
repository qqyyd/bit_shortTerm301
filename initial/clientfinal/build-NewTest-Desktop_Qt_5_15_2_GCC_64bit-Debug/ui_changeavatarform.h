/********************************************************************************
** Form generated from reading UI file 'changeavatarform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEAVATARFORM_H
#define UI_CHANGEAVATARFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dragscrollarea.h>

QT_BEGIN_NAMESPACE

class Ui_ChangeAvatarForm
{
public:
    QWidget *backgroundWidget;
    QPushButton *closeBtn;
    QLabel *friendName;
    QLabel *underLine;
    QWidget *mainWidget;
    QPushButton *pushButton_upload;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QPushButton *pushButton_clock;
    QPushButton *pushButton_anti;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;
    QLabel *underLine_2;
    DragScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label_avatar;

    void setupUi(QWidget *ChangeAvatarForm)
    {
        if (ChangeAvatarForm->objectName().isEmpty())
            ChangeAvatarForm->setObjectName(QString::fromUtf8("ChangeAvatarForm"));
        ChangeAvatarForm->resize(422, 672);
        backgroundWidget = new QWidget(ChangeAvatarForm);
        backgroundWidget->setObjectName(QString::fromUtf8("backgroundWidget"));
        backgroundWidget->setGeometry(QRect(1, 1, 420, 670));
        backgroundWidget->setStyleSheet(QString::fromUtf8("#backgroundWidget\n"
"{\n"
"	background-color:#474a59;\n"
"	border-radius:15px;\n"
"}"));
        closeBtn = new QPushButton(backgroundWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setEnabled(true);
        closeBtn->setGeometry(QRect(360, 10, 40, 40));
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
        friendName = new QLabel(backgroundWidget);
        friendName->setObjectName(QString::fromUtf8("friendName"));
        friendName->setGeometry(QRect(30, 20, 200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        friendName->setFont(font);
        friendName->setStyleSheet(QString::fromUtf8("color:#c9c9c9;"));
        friendName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        underLine = new QLabel(backgroundWidget);
        underLine->setObjectName(QString::fromUtf8("underLine"));
        underLine->setGeometry(QRect(30, 70, 370, 3));
        underLine->setStyleSheet(QString::fromUtf8("#underLine\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        mainWidget = new QWidget(backgroundWidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setGeometry(QRect(0, 69, 420, 601));
        pushButton_upload = new QPushButton(mainWidget);
        pushButton_upload->setObjectName(QString::fromUtf8("pushButton_upload"));
        pushButton_upload->setGeometry(QRect(30, 20, 120, 40));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_upload->sizePolicy().hasHeightForWidth());
        pushButton_upload->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(10);
        pushButton_upload->setFont(font1);
        pushButton_upload->setStyleSheet(QString::fromUtf8("#pushButton_upload\n"
"{\n"
"	background-color:transparent;\n"
"	color:#fff;\n"
"	border:2px solid #fff;\n"
"	border-radius:5px;\n"
"}\n"
"#pushButton_upload:hover\n"
"{\n"
"	background-color:#fff;\n"
"	color:#000;\n"
"}"));
        pushButton_upload->setFlat(true);
        layoutWidget = new QWidget(mainWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 440, 361, 52));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setStyleSheet(QString::fromUtf8("#horizontalSlider\n"
"{\n"
"	height:50px;\n"
"}\n"
"#horizontalSlider::groove\n"
"{\n"
"	background-color:rgba(255, 255, 255, 128);\n"
"	height:3px;\n"
"}\n"
"#horizontalSlider::handle\n"
"{\n"
"	background-color:#c9c9c9;\n"
"	width: 10px;\n"
"	height: 10px;\n"
"	margin: -6px 5px -6px 5px;\n"
"	border-radius:5px; \n"
"	border: 3px solid #ffffff;\n"
"}"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        pushButton_clock = new QPushButton(layoutWidget);
        pushButton_clock->setObjectName(QString::fromUtf8("pushButton_clock"));
        pushButton_clock->setMinimumSize(QSize(30, 30));
        pushButton_clock->setMaximumSize(QSize(30, 30));
        pushButton_clock->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Asserts/icons/rotate_clock_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_clock->setIcon(icon1);
        pushButton_clock->setIconSize(QSize(30, 30));
        pushButton_clock->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_clock);

        pushButton_anti = new QPushButton(layoutWidget);
        pushButton_anti->setObjectName(QString::fromUtf8("pushButton_anti"));
        pushButton_anti->setMinimumSize(QSize(30, 30));
        pushButton_anti->setMaximumSize(QSize(30, 30));
        pushButton_anti->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Asserts/icons/rotate_anti_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_anti->setIcon(icon2);
        pushButton_anti->setIconSize(QSize(30, 30));
        pushButton_anti->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_anti);

        pushButton_cancel = new QPushButton(mainWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(150, 540, 120, 40));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("#pushButton_cancel\n"
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
        pushButton_ok = new QPushButton(mainWidget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(280, 540, 120, 40));
        sizePolicy.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy);
        pushButton_ok->setStyleSheet(QString::fromUtf8("#pushButton_ok\n"
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
        underLine_2 = new QLabel(mainWidget);
        underLine_2->setObjectName(QString::fromUtf8("underLine_2"));
        underLine_2->setGeometry(QRect(30, 500, 370, 3));
        underLine_2->setStyleSheet(QString::fromUtf8("#underLine_2\n"
"{\n"
"    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  #e38283 ,stop:0.33 #c19f9e, stop:0.67 #91b8bb,stop:1 #1bced8);\n"
"\n"
"}"));
        scrollArea = new DragScrollArea(mainWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 70, 360, 360));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 358, 358));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_avatar = new QLabel(scrollAreaWidgetContents);
        label_avatar->setObjectName(QString::fromUtf8("label_avatar"));
        label_avatar->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:2px solid #fff;"));
        label_avatar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_avatar);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_upload->raise();
        pushButton_upload->raise();
        horizontalSlider->raise();
        layoutWidget->raise();
        pushButton_cancel->raise();
        pushButton_ok->raise();
        underLine_2->raise();
        scrollArea->raise();
        closeBtn->raise();
        friendName->raise();
        underLine->raise();
        horizontalSlider->raise();
        mainWidget->raise();

        retranslateUi(ChangeAvatarForm);

        QMetaObject::connectSlotsByName(ChangeAvatarForm);
    } // setupUi

    void retranslateUi(QWidget *ChangeAvatarForm)
    {
        ChangeAvatarForm->setWindowTitle(QCoreApplication::translate("ChangeAvatarForm", "Form", nullptr));
        closeBtn->setText(QString());
        friendName->setText(QCoreApplication::translate("ChangeAvatarForm", "\346\233\264\346\215\242\345\244\264\345\203\217", nullptr));
        underLine->setText(QString());
        pushButton_upload->setText(QCoreApplication::translate("ChangeAvatarForm", "\344\270\212\344\274\240\345\244\264\345\203\217", nullptr));
        pushButton_clock->setText(QString());
        pushButton_anti->setText(QString());
        pushButton_cancel->setText(QCoreApplication::translate("ChangeAvatarForm", "\345\217\226\346\266\210", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("ChangeAvatarForm", "\347\241\256\345\256\232", nullptr));
        underLine_2->setText(QString());
        label_avatar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeAvatarForm: public Ui_ChangeAvatarForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEAVATARFORM_H
