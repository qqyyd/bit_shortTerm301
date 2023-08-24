#include "friendverificationitem.h"
#include "ui_friendverificationitem.h"

FriendVerificationItem::FriendVerificationItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendVerificationItem)
{
    ui->setupUi(this);
}

FriendVerificationItem::~FriendVerificationItem()
{
    delete ui;
}

void FriendVerificationItem::on_rejectionBtn_clicked()
{

    //拒绝添加
    myCommunicationClient::myClient->friend_reject(myCommunicationClient::my_id,ui->friendName->text());
    QString friendRequestIdNumber = ui->friendName->text();
    for(auto uncheckedfriendRequest = myCommunicationClient::allRequest.begin();
        uncheckedfriendRequest!=myCommunicationClient::allRequest.end();
        uncheckedfriendRequest++)
    {
        if(friendRequestIdNumber==(*uncheckedfriendRequest).first.idNumber)
        {
            myCommunicationClient::allRequest.erase(uncheckedfriendRequest);
            break;
        }
    }

    close();
}

void FriendVerificationItem::on_acceptBtn_clicked()
{
    qDebug()<<myCommunicationClient::my_id<<endl;
    qDebug()<<ui->friendName->text()<<endl;
    myCommunicationClient::myClient->friend_accept(myCommunicationClient::my_id,ui->friendName->text());
    QString friendRequestIdNumber = ui->friendName->text();
    for(auto uncheckedfriendRequest = myCommunicationClient::allRequest.begin();
        uncheckedfriendRequest!=myCommunicationClient::allRequest.end();
        uncheckedfriendRequest++)
    {
        if(friendRequestIdNumber == (*uncheckedfriendRequest).first.idNumber)
        {
//            myCommunicationClient::allFriend.append((*uncheckedfriendRequest).first);
            myCommunicationClient::allRequest.erase(uncheckedfriendRequest);
            break;
        }
    }


    close();
    //接受
}
//好友名称
void FriendVerificationItem::setName(QString friendName)
{
    ui->friendName->setText(friendName);
}
QString FriendVerificationItem::getName()
{
    return QString(ui->friendName->text());
}
//好友验证消息
void FriendVerificationItem::setVerifiMsg(QString verfiMsg)
{
    ui->friendVerifiMsg->setText(verfiMsg);
}
QString FriendVerificationItem::getVerifiMsg()
{
    return QString(ui->friendVerifiMsg->text());
}
