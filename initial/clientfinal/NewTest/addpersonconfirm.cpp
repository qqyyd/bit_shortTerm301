#include "addpersonconfirm.h"
#include "ui_addpersonconfirm.h"

AddPersonConfirm::AddPersonConfirm(QWidget *parent, QString friendName) :
    QWidget(parent),
    ui(new Ui::AddPersonConfirm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    //窗口设置
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint);
    //入场动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    this->friendName=friendName;

}

AddPersonConfirm::~AddPersonConfirm()
{
    delete ui;
}

//这里写前后端交接函数，之后在on_pushButton_ok_clicked()里引用一下




//以下为UI功能函数

//确认添加
void AddPersonConfirm::on_pushButton_ok_clicked()
{
    myCommunicationClient::myClient->add_friend(ui->verifiMsg->text(), myCommunicationClient::my_id, friendName);// 调用接口发送加好友请求给服务器

    closeAddPersonConfirm();

}
//关闭窗口
void AddPersonConfirm::on_closeBtn_clicked()
{
    closeAddPersonConfirm();
}
//取消添加
void AddPersonConfirm::on_pushButton_cancel_clicked()
{
    closeAddPersonConfirm();
}
//出场动画
bool AddPersonConfirm::closeAddPersonConfirm(){

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    return true;
}


//三个鼠标事件的重写
void AddPersonConfirm::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void AddPersonConfirm::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void AddPersonConfirm::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}


