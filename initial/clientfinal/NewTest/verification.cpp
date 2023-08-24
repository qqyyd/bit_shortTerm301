#include <QTimer>
#include "verification.h"
#include <QString>
#include <QPainter>
#include <QPushButton>
#include <QTime>


Verification::Verification(QWidget *parent) : QPushButton(parent)
{
    m_timer = new QTimer(this);
    //QTime::currentTime()获取当前时间 QTime::currentTime().msec()是取时间作为产生随机数的种子.
    qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec());
    m_captcha = getCaptcha();//产生新的验证码
    m_color = getColor();//产生新的颜色
    connect(m_timer,SIGNAL(timeout()),this,SLOT(TimeoutSlot()));//如果图片被点击则产生新的颜色
    m_timer->start(200);//每200微秒变化一次颜色
    connect(this,SIGNAL(clicked(bool)),this,SLOT(getCaptcha()));//如果图片被点击则产生新的验证码
}


QString Verification::getCaptcha()
{
    QString ret = "";
    for(int i = 0; i < 4; i++){
        int c = (qrand() % 2) ? 'a' : 'A';
        ret += static_cast<QChar>(c + qrand() % 26);
    }
    m_captcha = ret;
    return ret;
}

Qt::GlobalColor *Verification::getColor()
{
    static Qt::GlobalColor colors[4];//定义填充样式的颜色
    for(int i = 0; i < 4; i++)
    {
        //static_cast< new_type >(expression) 类似于C语言中的强制转化，该运算符把expression转换为new_type类型
        colors[i] = static_cast<Qt::GlobalColor>((qrand() % 16) + 2);
    }
    return colors;
}
//虚函数 接收绘制事件
void Verification::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, 84, 24, Qt::white);//背景设为白色
    painter.setFont(QFont("Comic Sans MS"));

    //绘制噪点
    for(int i = 0; i < 100; i++){
        painter.setPen(m_color[i % 4]);
        painter.drawPoint(0 + (qrand() % 84), 0 + (qrand() % 24));
    }
    //绘制验证码
    for(int i = 0; i < 4; i++){
        painter.setPen(m_color[i]);
        painter.drawText(0 + 20 * i, 0, 20, 24, Qt::AlignCenter, QString(m_captcha[i]));
    }
}


void Verification::TimeoutSlot()
{
    m_color = getColor();
    update();
}
