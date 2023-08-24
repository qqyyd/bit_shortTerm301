#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QPixmap>
#include <QString>
#include <QImage>
#include "chatform.h"
#include "global.h"
#include "personalinfo.h"

namespace Ui {
class FriendItem;
}

class FriendItem : public QWidget
{
    Q_OBJECT

public:
    explicit FriendItem(PersonalInfo person, QWidget *parent = 0);
    ~FriendItem();
    void setFriendName(QString friendName);

private slots:
    void on_friendChatBtn_clicked();
    ChatForm* makeChatform(QString Name); //Name创建一个ChatForm
    void onChatFormClosed();
private:
    Ui::FriendItem *ui;
    void circleAvatar(QImage);
    void on_frienditem_clicked();

    QString friendName;

signals:
    void openChatForm(QString Name);
};

#endif // FRIENDITEM_H
