#include "friendverification.h"
#include "ui_friendverification.h"

FriendVerification::FriendVerification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendVerification)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    showFriendVerificationList();

}

FriendVerification::~FriendVerification()
{
    delete ui;
}

//申请加好友列表
void FriendVerification::showFriendVerificationList()
{
    for (auto friendrequest : myCommunicationClient::allRequest) {
//        do something
        QListWidgetItem *item=new QListWidgetItem;

        FriendVerificationItem *fvi = new FriendVerificationItem;

        fvi->setName(friendrequest.first.idNumber);
        fvi->setVerifiMsg(friendrequest.second);

        item->setSizeHint(QSize(500,90));

        ui->listWidget->addItem(item);

        ui->listWidget->setItemWidget(item,fvi);// 渲染出申请添加好友列表
    }
//    for(int i = 0;i < 10;i++){

//        QListWidgetItem *item=new QListWidgetItem;

//        FriendVerificationItem *fvi = new FriendVerificationItem;

//        item->setSizeHint(QSize(500,90));

//        ui->listWidget->addItem(item);

//        ui->listWidget->setItemWidget(item,fvi);
//    }
}











//三个鼠标事件的重写
void FriendVerification::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void FriendVerification::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void FriendVerification::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

bool FriendVerification::closeFriendVerification()
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


void FriendVerification::on_closeBtn_clicked()
{
    closeFriendVerification();
}
