#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0, QString id = "", QString password = "");
    ~Widget();

private slots:

    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void on_signup_clicked();
    void on_submit_clicked();

    bool closeWidget();

    void on_closeBtn_clicked();

private:
    Ui::Widget *ui;
    QPoint last;

};

#endif // WIDGET_H
