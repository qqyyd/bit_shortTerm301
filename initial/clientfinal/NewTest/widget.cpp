#include "widget.h"
#include "ui_widget.h"
#include "personalform.h"
#include "registerform.h"
#include <QMouseEvent>
#include <QObject>
#include <string>
#include <QPropertyAnimation>
#include <QMessageBox>
#include "md5.cpp"
#include "mycommunicationclient.h"

Widget::Widget(QWidget *parent, QString id, QString password) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    ui->usersName->setText(id);
    ui->Password->setText(password);

    connect(myCommunicationClient::myClient,
            &Communication_client::login_feedback,
            this,
            [=](int state){
        if (state==1) {
            myCommunicationClient::my_id = ui->usersName->text();
            closeWidget();
            PersonalForm *personalForm = new PersonalForm;
            QThread::sleep(1);
            personalForm->show();
        }else{
            if (state==0)
            {
                QMessageBox::critical(this, "错误", "密码错误！");
            }
            //login failed(password incorrect) -> retry
            if (state==-1)
            {
                QMessageBox::critical(this, "错误", "用户名不存在！");
            }
            //login failed(login_error-id_not_exist) -> retry
        }
    });


}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_submit_clicked()
{
    //获得账号密码
    QString usersName = ui->usersName->text();
    if (usersName=="") {
        QMessageBox::critical(this, "错误", "用户名不能为空！");
        return;
    }
    QString Password = ui->Password->text();



    //将密码转为MD5码
    MD5 password_to_md5;
    string tmp_password;
    tmp_password = Password.toStdString();
    QString md5_password = QString::fromStdString(password_to_md5.encode(tmp_password));

//    qDebug() << md5_password << endl;

    //确认身份
    //将账号、密码的MD5值发送至服务器
    myCommunicationClient::myClient->try_to_login(usersName,md5_password);
    //服务器进行数据库查询，查询账号有无，无则返回wrong，前端提示用户名或密码错误
    //账号存在则服务器继续查询密码MD5值，与输入的密码MD5值作比对，错误返回wrong，前端提示密码错误
    //正确则返回ok，前端关闭登录界面，打开好友列表
    //if(usersName == "Fishko" && Password == "123456")
    //{


    //}
}

void Widget::on_signup_clicked()
{

    closeWidget();

    registerForm *pregisterForm = new registerForm;
    pregisterForm->show();
}

bool Widget::closeWidget()
{
   //界面动画，改变透明度的方式消失1 - 0渐变
   QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
   animation->setDuration(300);
   animation->setStartValue(1);
   animation->setEndValue(0);
   animation->start();
   //connect(animation, SIGNAL(finished()), this, SLOT(close()));

   return true;
}


//三个鼠标事件的重写
void Widget::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}


void Widget::on_closeBtn_clicked()
{
    myCommunicationClient::myClient->client->disconnectFromHost();
    closeWidget();
}
