#ifndef DRAGSCROLLAREA_H
#define DRAGSCROLLAREA_H

#include <QScrollArea>
#include <QEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QPoint>

namespace Ui {
class DragScrollArea;
}

class DragScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit DragScrollArea(QWidget *parent = 0);
    ~DragScrollArea();

private:
    Ui::DragScrollArea *ui;
    virtual bool event(QEvent* event);
};

#endif // DRAGSCROLLAREA_H
