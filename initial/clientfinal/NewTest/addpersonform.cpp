#include "addpersonform.h"
#include "ui_addpersonform.h"

AddPersonForm::AddPersonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPersonForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    //窗口设置
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);
    //入场动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    connect(myCommunicationClient::myClient,
            &Communication_client::find_friend_result, // 未实现信号
            this,
            [=](QString state){
        if (state=="success")
        {
            closeAddPersonForm();
            AddPersonConfirm *addPersonConfirm = new AddPersonConfirm(0,ui->searchNameEdit->text());
            addPersonConfirm->show();
        }
        if (state=="id_not_found") {
            ui->hintLabel->setText("查无此人，请确认ID是否输入正确！");
        }
        if (state=="already_add") {
            ui->hintLabel->setText("已经是好友啦，你这么喜欢ta吗?");
        }
    });
}

AddPersonForm::~AddPersonForm()
{
    delete ui;
}


//搜索好友
void AddPersonForm::on_searchNameBtn_clicked()
{
    myCommunicationClient::myClient->find_friend(myCommunicationClient::my_id,ui->searchNameEdit->text());// 未实现函数

//    //搜索功能

//    //我先默认找到
//    isFindPerson = true;

//    if(isFindPerson)
//    {
//        closeAddPersonForm();
//        AddPersonConfirm *addPersonConfirm = new AddPersonConfirm;
//        addPersonConfirm->show();
//    }
//    else
//    {
//        ui->hintLabel->setText("查无此人，请确认ID是否输入正确");
//    }
}
//关闭窗口
void AddPersonForm::on_closeBtn_clicked()
{
    closeAddPersonForm();

}
//取消焦点
void AddPersonForm::on_searchNameEdit_editingFinished()
{
    ui->searchNameEdit->clearFocus();
}

//出场动画
bool AddPersonForm::closeAddPersonForm(){

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    return true;
}


//三个鼠标事件的重写
void AddPersonForm::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void AddPersonForm::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void AddPersonForm::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

