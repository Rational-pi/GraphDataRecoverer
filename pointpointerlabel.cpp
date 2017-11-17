#include "pointpointerlabel.h"
#include <QPainter>

PointPointerLabel::PointPointerLabel(QWidget *parent):QLabel(parent){}

void PointPointerLabel::resize(int w, int h)
{
    QLabel::resize(w,h);
}

void PointPointerLabel::resize(const QSize &p)
{
    QLabel::resize(p);
}

void PointPointerLabel::paintEvent(QPaintEvent *event){
    //QLabel::paintEvent(event);
    QPainter p(this);
    p.drawLine(10,10,111,111);
}

void PointPointerLabel::moveEvent(QMoveEvent *event)
{

}

void PointPointerLabel::resizeEvent(QResizeEvent *event)
{

}
