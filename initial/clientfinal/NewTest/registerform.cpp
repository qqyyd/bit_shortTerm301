#include "registerform.h"
#include "ui_registerform.h"
#include "personalform.h"
#include "widget.h"
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QSaveFile>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "registerform.h"
#include "ui_registerform.h"
#include "personalform.h"
#include "widget.h"
#include "md5.cpp"
#include "verification.h"
#include "mycommunicationclient.h"


registerForm::registerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);

    //入场动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    connect(ui->Password,  SIGNAL(textChanged(const QString &)), this, SLOT(passwordchangeslot()));

    ui->verification->setMaxLength(4);//设置长度为4
    ui->verification->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z]{4}$")));

    connect(myCommunicationClient::myClient,
            &Communication_client::register_feedback,
            this,
            [=](int state){
       if (state==1) {
           QMessageBox::information(this,"注册成功","恭喜，注册成功");
           Widget *widget = new Widget(0,ui->usersName->text(),ui->Password->text());
           closeRegisterForm();
           widget->show();
       }else{
            if (state==0) {
                QMessageBox::critical(this, "错误", "用户名已被占用！");
                //register failed, idNumber has been used
            }
       }
    });
}

registerForm::~registerForm()
{
    delete ui;
}

//密码强度检验
QString registerForm::PasswordStrength(QString pw)
{
    int teshuzifugeshu = 0, shuzigeshu = 0, xiaoxiezimugeshu = 0, daxiezimugeshu = 0;
    int num = pw.length();
    for (int i = 0; i < pw.length(); i++)
    {
        QCharRef zifu = pw[i];
        if (48 <= zifu && zifu <= 57)//检测数字
        {
            shuzigeshu += 1;
        }
        else if (97 <= zifu && zifu <= 122)//检测小写字母
        {
            xiaoxiezimugeshu += 1;
        }
        else if (65 <= zifu && zifu <= 90)//检测大写字母
        {
            daxiezimugeshu += 1;
        }
        else  // if ((32 < zifu && zifu < 48) || (57 < zifu && zifu < 65) || (90 < zifu && zifu < 97) || (122 < zifu && zifu < 127))//检测特殊字符
        {
            teshuzifugeshu += 1;
        }
    }
    if (num < 6)
    {
        return "INVALID";
    }
    else if (shuzigeshu == 0)
    {
        return "INVALID";
    }
    else if (xiaoxiezimugeshu == num || daxiezimugeshu == num || shuzigeshu == num || teshuzifugeshu == num)
    {
        return "INVALID";
    }
    else if ((shuzigeshu + teshuzifugeshu) == num)
    {
        return "INVALID";
    }
    else if ((daxiezimugeshu + xiaoxiezimugeshu) == num)
    {
        return "INVALID";
    }
    else if ((daxiezimugeshu + teshuzifugeshu) == num)
    {
        return "INVALID";
    }
    else if ((xiaoxiezimugeshu + teshuzifugeshu) == num)
    {
        return "INVALID";
    }
    else if ((daxiezimugeshu + xiaoxiezimugeshu + teshuzifugeshu) == num)
    {
        return "INVALID";
    }
    else if (num < 10 && teshuzifugeshu == 0 && (xiaoxiezimugeshu == 0 || daxiezimugeshu == 0))
    {
        return "RUO";
    }
    else if (num >= 10 && daxiezimugeshu > 0 && xiaoxiezimugeshu > 0 && teshuzifugeshu > 0)
    {
        return "QIANG";
    }
    //if (num >= 10 || (daxiezimugeshu != 0 && xiaoxiezimugeshu != 0) || teshuzifugeshu != 0)
    else
    {
        return "ZHONG";
    }
}

void registerForm::on_ReturnBtn_clicked()
{
    closeRegisterForm();

    Widget *pwidget = new Widget;
    pwidget->show();
}

void registerForm::on_ConfirmBtn_clicked()
{

    //获得注册账号、密码、确认密码
    QString usersName = ui->usersName->text();
    QString Password = ui->Password->text();
    QString PasswordConfirmed = ui->PasswordConfirmed->text();

    if(usersName == "")
    {
        QMessageBox::critical(this, "错误", "用户名不能为空！");
    }
    else if(Password == "" || PasswordStrength(Password) == "INVALID")
    {
        QMessageBox::critical(this, "错误", "非法密码！");
    }
    else if(Password != PasswordConfirmed)
    {
        QMessageBox::critical(this, "错误", "两次输入的密码不同！");
    }
    else if(ui->verification->text().toLower() != ui->verification_code->m_captcha.toLower())
    {
        QMessageBox::critical(this, "错误", "验证码错误！");
    }
    else
    {
        MD5 password_to_md5;
        string tmp_password;
        tmp_password = Password.toStdString();
        QString md5_password = QString::fromStdString(password_to_md5.encode(tmp_password));

        qDebug() << md5_password << endl;

        //将昵称密码发送给服务器写入数据库
        myCommunicationClient::myClient->try_to_register(usersName,md5_password);
        //close();
//        QMessageBox::information(this,"注册成功","恭喜，注册成功");


//        Widget *pwidget = new Widget;
//        closeRegisterForm();
//        pwidget->show();

//        closeRegisterForm();


    }
}

bool registerForm::closeRegisterForm()
{
    //依然是动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();

    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    return true;
}

//三个鼠标事件的重写
void registerForm::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void registerForm::mouseMoveEvent(QMouseEvent *e)
{

     int dx = e->globalX() - last.x();
     int dy = e->globalY() - last.y();
     last = e->globalPos();
     move(x()+dx, y()+dy);
}

void registerForm::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void registerForm::passwordchangeslot()
{
    QString password = ui->Password->text();
//    qDebug() << "change" << endl;
    if (PasswordStrength(password) == "QIANG")
    {
        ui->PasswordStrong->setText("强");
//        qDebug() << "强" << endl;
    }
    else if (PasswordStrength(password) == "ZHONG")
    {
        ui->PasswordStrong->setText("中");
//        qDebug() << "中" << endl;
    }
    else if (PasswordStrength(password) == "RUO")
    {
        ui->PasswordStrong->setText("弱");
//        qDebug() << "弱" << endl;
    }
    else
    {
        ui->PasswordStrong->setText("非法");
//        qDebug() << "非法" << endl;
    }
}
