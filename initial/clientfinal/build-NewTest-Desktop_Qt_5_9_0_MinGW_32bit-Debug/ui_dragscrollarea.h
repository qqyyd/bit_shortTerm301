/********************************************************************************
** Form generated from reading UI file 'dragscrollarea.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGSCROLLAREA_H
#define UI_DRAGSCROLLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DragScrollArea
{
public:
    QWidget *scrollAreaWidgetContents;

    void setupUi(QScrollArea *DragScrollArea)
    {
        if (DragScrollArea->objectName().isEmpty())
            DragScrollArea->setObjectName(QStringLiteral("DragScrollArea"));
        DragScrollArea->resize(400, 300);
        DragScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 298));
        DragScrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(DragScrollArea);

        QMetaObject::connectSlotsByName(DragScrollArea);
    } // setupUi

    void retranslateUi(QScrollArea *DragScrollArea)
    {
        DragScrollArea->setWindowTitle(QApplication::translate("DragScrollArea", "ScrollArea", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DragScrollArea: public Ui_DragScrollArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGSCROLLAREA_H
