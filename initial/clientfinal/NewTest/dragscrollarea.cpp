#include "dragscrollarea.h"
#include "ui_dragscrollarea.h"

DragScrollArea::DragScrollArea(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::DragScrollArea)
{
    ui->setupUi(this);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

DragScrollArea::~DragScrollArea()
{
    delete ui;
}

bool DragScrollArea::event(QEvent *event)
{
    if(widget())
    {
        static QPoint point;
        if(QEvent::MouseButtonPress == event->type())
        {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            point = mouseEvent->pos();
        }
        else if(QEvent::MouseMove == event->type())
        {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if(Qt::LeftButton & mouseEvent->buttons())
            {
                const QPoint& offset = mouseEvent->pos() - point;
                horizontalScrollBar()->setValue(horizontalScrollBar()->value() - offset.x()*horizontalScrollBar()->maximum() / widget()->width());
                verticalScrollBar()->setValue(verticalScrollBar()->value() - offset.y()*verticalScrollBar()->maximum() / widget()->height());
                point = mouseEvent->pos();
            }
        }
    }
    return QScrollArea::event(event);
}
