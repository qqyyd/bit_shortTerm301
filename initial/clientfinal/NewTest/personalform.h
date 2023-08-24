#ifndef PERSONALFORM_H
#define PERSONALFORM_H

#include <QWidget>
#include <QPainter>
#include <QList>
#include <QFocusEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QList>
#include <QString>
#include "frienditem.h"
#include "addpersonform.h"
#include "changeavatarform.h"
#include "friendverification.h"
//#include "personalinfo.h"
#include "global.h"


namespace Ui {
class PersonalForm;
}

class PersonalForm : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalForm(QWidget *parent = 0);
    ~PersonalForm();
    void circleAvatar(QImage my = myCommunicationClient::myinfo.image);


private:
    Ui::PersonalForm *ui;

    QPoint last;
    QList <FriendItem*> FriendList;
protected:

    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);


    void friendItemView();

private slots:
    void on_closeBtn_clicked();
    void on_miniBtn_clicked();
    bool closePersonalForm();
    void on_changeAvatarBtn_clicked();
    void on_usersMotto_editingFinished();
    void on_addPersonBtn_clicked();
    void on_friendRequest_clicked();

//    void appendFriendList(FriendItem *friendItem); // 添加好友
    void getFriendList(); // 获取好友列表
};

#endif // PERSONALFORM_H
