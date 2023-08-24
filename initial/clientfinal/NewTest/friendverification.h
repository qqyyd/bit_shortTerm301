#ifndef FRIENDVERIFICATION_H
#define FRIENDVERIFICATION_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPoint>
#include <QMouseEvent>
#include "friendverificationitem.h"

namespace Ui {
class FriendVerification;
}

class FriendVerification : public QWidget
{
    Q_OBJECT

public:
    explicit FriendVerification(QWidget *parent = 0);
    ~FriendVerification();

private slots:
    void on_closeBtn_clicked();


private:
    Ui::FriendVerification *ui;
    bool closeFriendVerification();
    void showFriendVerificationList();
    QPoint last;

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // FRIENDVERIFICATION_H
