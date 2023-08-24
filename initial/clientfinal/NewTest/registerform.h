#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QString>
#include <QDialog>
#include <QPainter>
#include <QTimer>
#include "widget.h"

namespace Ui {
class registerForm;
}

class registerForm : public QWidget
{
    Q_OBJECT

public:
    explicit registerForm(QWidget *parent = 0);
    ~registerForm();

    QString PasswordStrength(QString pw);

private slots:

    void on_ReturnBtn_clicked();

    void on_ConfirmBtn_clicked();

    bool closeRegisterForm();

    void passwordchangeslot();

private:
    Ui::registerForm *ui;


    QPoint last;

    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // REGISTERFORM_H
