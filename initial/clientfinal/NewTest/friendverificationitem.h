#ifndef FRIENDVERIFICATIONITEM_H
#define FRIENDVERIFICATIONITEM_H

#include <QWidget>
#include <QString>
#include "mycommunicationclient.h"

namespace Ui {
class FriendVerificationItem;
}

class FriendVerificationItem : public QWidget
{
    Q_OBJECT

public:
    explicit FriendVerificationItem(QWidget *parent = 0);
    ~FriendVerificationItem();
    void setName(QString friendName);
    QString getName();

    void setVerifiMsg(QString friendVerifiMsg);
    QString getVerifiMsg();

private slots:

    void on_rejectionBtn_clicked();

    void on_acceptBtn_clicked();

private:
    Ui::FriendVerificationItem *ui;
};

#endif // FRIENDVERIFICATIONITEM_H
