#include "chatform.h"
#include "ui_chatform.h"
#include <QPropertyAnimation>
#include <QDateTime>
#include <QDebug>
#include "mycommunicationclient.h"

ChatForm::ChatForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint);
    //入场动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    connect(myCommunicationClient::myClient,
            &Communication_client::new_string_message_ready,
            this,
            [=](QString from, QString message){
        if (from == friendName) {
            QString time = QString::number(QDateTime::currentDateTime().toTime_t());
            QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget(), friendName);
            QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
            dealMessage(messageW, item, message, time, QNChatMessage::User_She);
        }
    });
}



ChatForm::~ChatForm()
{
    delete ui;
}
void ChatForm::init(){
    QVector<QString> historyChat = myCommunicationClient::get_chat_recode(friendName);
    for(auto historyChatItem : historyChat)
    {
        if(historyChatItem[0] == '+')
        {
            QString time = "history";

            QString message = historyChatItem.mid(1);
            QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget(), friendName);
            QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
            dealMessage(messageW, item, message, time, QNChatMessage::User_Me);
        }
        else
        {
            QString time = "history";
            QString message = historyChatItem.mid(1);
            QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget(), friendName);
            QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
            dealMessage(messageW, item, message, time, QNChatMessage::User_She);
        }
    }
}
//三个鼠标事件的重写
void ChatForm::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void ChatForm::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void ChatForm::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void ChatForm::dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time,  QNChatMessage::User_Type type)
{
    messageW->setFixedWidth(this->width()*0.8);
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, type);
    ui->listWidget->setItemWidget(item, messageW);
}

void ChatForm::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    int listCount = ui->listWidget->count();
    if(curMsgTime == "history")
    {
        isShowTime = false;
    }
    else
    {
        if( listCount> 0 ) {
            QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
            QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(lastItem);
            int lastTime = messageW->time().toInt();
            int curTime = curMsgTime.toInt();
            qDebug() << "curTime lastTime:" << curTime - lastTime;
            isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
    //        isShowTime = true;
        } else {

            isShowTime = true;
        }

        if(isShowTime) {
            QNChatMessage* messageTime = new QNChatMessage(ui->listWidget->parentWidget(),friendName);
            QListWidgetItem* itemTime = new QListWidgetItem(ui->listWidget);

            QSize size = QSize(this->width(), 40);
            messageTime->resize(size);
            itemTime->setSizeHint(size);
            messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
            ui->listWidget->setItemWidget(itemTime, messageTime);
        }
    }


}

void ChatForm::on_miniBtn_clicked()
{
    this->showMinimized();
}

bool ChatForm::closeChatForm()
{
    //界面动画，改变透明度的方式消失1 - 0渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    return true;
}

void ChatForm::on_closeBtn_clicked()
{
    emit ChatFormClosed();
    closeChatForm();
}

void ChatForm::on_sendBtn_clicked()
{
    QString msg = ui->inputEdit->toPlainText();
    ui->inputEdit->setPlainText("");
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

    bool isSending = true; // 发送中
    emit enteredText(ui->inputEdit->toPlainText());

    qDebug()<<"addMessage" << msg << time << ui->listWidget->count();

    myCommunicationClient::myClient->send_string_message(msg,myCommunicationClient::my_id,friendName);// 调用接口将消息发送至服务器给对方

    qDebug()<<"!!";
    dealMessageTime(time);
    qDebug()<<"!!";

    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget(), friendName);
    qDebug()<<"!!";
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    qDebug()<<"!!";
    dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);// 渲染出我们给对方发送的消息
    qDebug()<<"!!";


//    myCommunicationClient::myClient->send_string_message(msg,myCommunicationClient::my_id,
//     if(ui->listWidget->count()%2) {
//         if(isSending)
//         {
//             dealMessageTime(time);

//             QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
//             QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
//             dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
//         }
//         else
//         {
//             bool isOver = true;
//             for(int i = ui->listWidget->count() - 1; i > 0; i--) {
//                 QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(ui->listWidget->item(i));
//                 if(messageW->text() == msg) {
//                     isOver = false;
//                     messageW->setTextSuccess();
//                 }
//             }
//             if(isOver) {
//                 dealMessageTime(time);

//                 QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget(),friendName);
//                 QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
//                 dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
//                 messageW->setTextSuccess();
//             }
//         }
//     } else {
//         if(msg != "") {
//             dealMessageTime(time);

//             QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
//             QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
//             dealMessage(messageW, item, msg, time, QNChatMessage::User_She);
//         }
//     }
//     ui->listWidget->setCurrentRow(ui->listWidget->count()-1);

}

void ChatForm::setFriendName(QString Name){
    this->friendName = Name;
}

void ChatForm::setChatFormName(QString Name){
    ui->friendName->setText(Name);
}
