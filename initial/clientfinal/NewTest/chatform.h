#ifndef CHATFORM_H
#define CHATFORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <qnchatmessage.h>
#include <QListWidgetItem>
#include <QString>

namespace Ui {
class ChatForm;
}

class ChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatForm(QWidget *parent = 0);
    ~ChatForm();

    void dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time, QNChatMessage::User_Type type);
    void dealMessageTime(QString curMsgTime);

    void setFriendName(QString Name);
    void setChatFormName(QString Name);
    Ui::ChatForm *ui;

    void init();

private slots:

    void on_miniBtn_clicked();

    void on_closeBtn_clicked();

    void on_sendBtn_clicked();

private:

    QPoint last;

    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool closeChatForm();

    QString friendName;

signals:
    void ChatFormClosed(); //关闭ChatForm
    void enteredText(QString text); //发送输入的文本
};

#endif // CHATFORM_H
