#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QTimer>
#include "verification.h"
#include <QString>
#include <QPainter>
#include <QPushButton>
#include <QTime>

class Verification : public QPushButton
{
    Q_OBJECT
public:
    explicit Verification(QWidget *parent = nullptr);

    Qt::GlobalColor* getColor();
    //虚函数 接收绘制事件
    void paintEvent(QPaintEvent *event);
    QString m_captcha;
    Qt::GlobalColor* m_color;
    QTimer *m_timer;
signals:

public slots:

    QString getCaptcha();

    void TimeoutSlot();
};


#endif // VERIFICATION_H

