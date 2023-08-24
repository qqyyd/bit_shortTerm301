#include "personalform.h"
#include "ui_personalform.h"
#include "frienditem.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QList>
#include <QString>
#include "mycommunicationclient.h"

PersonalForm::PersonalForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalForm)
{
    ui->setupUi(this);

    ui->UsersName->setText(myCommunicationClient::my_id);

    qDebug()<<"@wuw";
    connect(myCommunicationClient::myClient,
            &Communication_client::friendList_ready,
            this,
            [=](QVector<PersonalInfo> friendList){
        qDebug("!!");
        myCommunicationClient::allFriend = friendList;
        myCommunicationClient::myinfo =
                myCommunicationClient::findInfo(myCommunicationClient::my_id);
        ui->avatarImage-> setPixmap(QPixmap::fromImage(myCommunicationClient::myinfo.image));

        if (myCommunicationClient::myinfo.image.isNull()) {
            qDebug() << "Image not in database";
            return;
        }

        QPixmap pixmap = QPixmap::fromImage(myCommunicationClient::myinfo.image);
        if (pixmap.isNull()) {
            qDebug() << "Failed to convert QImage to QPixmap!";
            return;
        }


        ui->usersMotto->setText(myCommunicationClient::myinfo.usersMotto);
        circleAvatar(myCommunicationClient::myinfo.image);
        getFriendList();
        friendItemView();
    });



    connect(myCommunicationClient::myClient,
            &Communication_client::new_friend_added,
            this,
            [=](PersonalInfo newFriend){
        myCommunicationClient::allFriend.append(newFriend);
           //use showFriendList and friendItemview
        getFriendList();
        friendItemView();//每当有新朋友加入好友列表，刷新好友列表
    });


    connect(myCommunicationClient::myClient,
            &Communication_client::request_recode_ready,
            this,
            [=](QVector<QPair<PersonalInfo,QString>> requestList){
       myCommunicationClient::allRequest = requestList;
    });

    connect(myCommunicationClient::myClient,
            &Communication_client::friend_request,
            this,
            [=](PersonalInfo newFriend, QString verifyText){
        myCommunicationClient::allRequest.append({newFriend,verifyText});
    });

    connect(myCommunicationClient::myClient,
            &Communication_client::chat_recode_ready,
            this,
            [=](QVector<QPair<QString,QVector<QString>>> chat_recode){
        qDebug()<<"!!@#"<<endl;
        myCommunicationClient::chat_recode = chat_recode;
    });



    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();




}

PersonalForm::~PersonalForm()
{
    delete ui;
}

//圆形头像
void PersonalForm::circleAvatar(QImage my)
{
    qDebug()<<"draw:"<<endl;
    my.save("/home/piggy/桌面/bit/01.项目源码/clientfinal");
    int w = ui->avatarImage->width();
    int h = ui->avatarImage->height();

    QPixmap pixmapa = QPixmap::fromImage(my);//传入我自己的头像
    QPixmap pixmap(w,h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
       QPainterPath path;
       path.addEllipse(0, 0, w, h);    //绘制椭圆
       painter.setClipPath(path);
       painter.drawPixmap(0, 0, w, h, pixmapa);

       ui->avatarImage->setPixmap(pixmap);
}

//三个鼠标事件的重写
void PersonalForm::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void PersonalForm::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void PersonalForm::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}


void PersonalForm::on_closeBtn_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    QApplication *app;
    myCommunicationClient::myClient->client->disconnectFromHost();
    app->exit();
}

void PersonalForm::on_miniBtn_clicked()
{
    this->showMinimized();
}


//显示好友列表
void PersonalForm::friendItemView()
{
    ui->listWidget->clear();
    /************************************/
    for(int i = 0; i < FriendList.size(); i ++){
        FriendItem *fi = FriendList.at(i);
//        connect(fi,SIGNAL(openChatForm(QString)),this,SLOT(makeChatform(QString)));
        QListWidgetItem *item = new QListWidgetItem;
    /************************************/
//       FriendItem *fi = new FriendItem; // 不需要再new一个

//       fi->setFriendName(QString::number(i)); //名字已经在获取好友列表时已经有了
    /************************************/
        item->setSizeHint(QSize(380,120));

        ui->listWidget->addItem(item);

        ui->listWidget->setItemWidget(item,fi);
    }


}

bool PersonalForm::closePersonalForm()
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

//void PersonalForm::appendFriendList(FriendItem *friendItem){
//    FriendList.append(friendItem); // 添加好友位
//}

void PersonalForm::getFriendList(){
    /*************************************/
    // 通过List去接收服务器的返回值
//    QList<QString> FriendNameList;
//    connect(myCommunicationClient::myClient,
//            &Communication_client::friendList_ready,
//            this,
//            [=](QVector<PersonalInfo> friendList){
//        myCommunicationClient::allFriend = friendList;
//        int i = 0;
//        for(auto afriend : friendList){
//            FriendNameList[i]=afriend.idNumber;
//            i++;
//        }
//    });

    /*************************************/
    // 这里写如何接收返回值
    //
    /*************************************/
    FriendList.clear();
    for(auto afriend : myCommunicationClient::allFriend){
        if (afriend.idNumber==myCommunicationClient::my_id) continue;
        FriendItem* fi = new FriendItem(afriend);
        FriendList.append(fi);
//        fi->setFriendName(FriendNameList[i]);
//        this->appendFriendList(fi);
    }
    /*************************************/
}
/****************ldf*****************/

void PersonalForm::on_changeAvatarBtn_clicked()
{
    ChangeAvatarForm *changeAvatarForm = new ChangeAvatarForm(this);
    changeAvatarForm->show();
}

void PersonalForm::on_usersMotto_editingFinished()
{
    ui->usersMotto->clearFocus();
    myCommunicationClient::myClient->change_userMotto(ui->usersMotto->text());
}

void PersonalForm::on_addPersonBtn_clicked()
{

    AddPersonForm *paddPersonForm = new AddPersonForm;
    paddPersonForm->show();

}

void PersonalForm::on_friendRequest_clicked()
{
    FriendVerification *pfriendVerification = new FriendVerification;
    pfriendVerification->show();
}
