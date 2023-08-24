#ifndef ADDPERSONCONFIRM_H
#define ADDPERSONCONFIRM_H

#include <QWidget>
#include <QString>
#include <QPoint>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include "mycommunicationclient.h"


namespace Ui {
class AddPersonConfirm;
}

class AddPersonConfirm : public QWidget
{
    Q_OBJECT

public:
    explicit AddPersonConfirm(QWidget *parent = 0, QString friendName="");
    ~AddPersonConfirm();

private:
    Ui::AddPersonConfirm *ui;
    QPoint last;
    QString friendName;

    bool closeAddPersonConfirm();

protected:

    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_closeBtn_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_ok_clicked();
};

#endif // ADDPERSONCONFIRM_H
