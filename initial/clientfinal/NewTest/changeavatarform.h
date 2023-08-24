#ifndef CHANGEAVATARFORM_H
#define CHANGEAVATARFORM_H

#include <QWidget>
#include <QPoint>
#include <QSlider>
#include <QPixmap>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QPainter>
#include <functional>
#include <QMessageBox>
#include <QPropertyAnimation>
#include "mycommunicationclient.h"
#include "personalform.h"

namespace Ui {
class ChangeAvatarForm;
}

class ChangeAvatarForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeAvatarForm(void *father, QWidget *parent = 0);
    ~ChangeAvatarForm();

    void LoadAvatar(const QPixmap& pixmap);
    void RotateAvatar(bool bClock);

private slots:
    void on_closeBtn_clicked();

    void on_pushButton_upload_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::ChangeAvatarForm *ui;

    void *father;

    QWidget* m_pDivWidget;
    QPixmap m_sourceAvatar;
    QPoint last;
    bool isElement = true;

//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);

    bool closeChangeAvatarForm();
protected:
    virtual bool eventFilter(QObject *watched, QEvent *event);

protected slots:
    void onScaledChanged(int nValue);

signals:
    void updateAvatar(const QPixmap& avatarImage);
};

#endif // CHANGEAVATARFORM_H
