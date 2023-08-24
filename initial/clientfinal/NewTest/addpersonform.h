#ifndef ADDPERSONFORM_H
#define ADDPERSONFORM_H

#include <QWidget>
#include <QPoint>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QMessageBox>
#include "personalform.h"
#include "addpersonconfirm.h"
#include "communication_client.h"
#include "mycommunicationclient.h"

namespace Ui {
class AddPersonForm;
}

class AddPersonForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddPersonForm(QWidget *parent = 0);
    ~AddPersonForm();

    bool isFindPerson;

private slots:
    void on_searchNameEdit_editingFinished();

    void on_searchNameBtn_clicked();

    void on_closeBtn_clicked();

private:

    Ui::AddPersonForm *ui;
    bool closeAddPersonForm();
    QPoint last;

protected:

    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // ADDPERSONFORM_H
