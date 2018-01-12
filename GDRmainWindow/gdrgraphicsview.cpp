#include "gdrgraphicsview.h"
#include <QtWidgets>
#include <QRect>
#include <iostream>

#define CTRL Qt::ControlModifier & QApplication::keyboardModifiers()
GDRgraphicsView::GDRgraphicsView(QWidget *parent):QGraphicsView(parent),m_scale(1){
    bkgBrush=QBrush(QPixmap("://GDRres/BKGtexture.png"));
    bkgBrush.setStyle(Qt::TexturePattern);
    borderPen.setStyle(Qt::SolidLine);
    borderPen.setColor(QColor(Qt::gray));
}

void GDRgraphicsView::wheelEvent(QWheelEvent *event){
    bool up = event->delta()>0;
    if (CTRL){
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        qreal scaleFactor=up?1.1:0.9;
        scale(scaleFactor,scaleFactor);
        m_scale*=scaleFactor;
    }else QGraphicsView::wheelEvent(event);
}

void GDRgraphicsView::drawBackground(QPainter *painter, const QRectF &rect){
    painter->scale(1/m_scale, 1/m_scale);
        // background color
        painter->fillRect(-1+rect.x()*m_scale,-1+rect.y()*m_scale,1+geometry().width(),1+geometry().height(),Qt::lightGray);

        // graphics background and border
        painter->setBrush(bkgBrush);
        painter->setPen(borderPen);
        QRectF sR = this->scene()->sceneRect();
        painter->drawRect(sR.x()*m_scale,sR.y()*m_scale,sR.width()*m_scale,sR.height()*m_scale);

        painter->scale(m_scale, m_scale);
}

void GDRgraphicsView::mousePressEvent(QMouseEvent *event){
    QPointF pt = mapToScene(event->pos());
    if (CTRL){
        xRemaper.feed(pt.x(),QInputDialog::getDouble(this,"Ask ?","X value Clicked:",0,-2147483647,2147483647,10));
        yRemaper.feed(pt.y(),QInputDialog::getDouble(this,"Ask ?","Y value Clicked:",0,-2147483647,2147483647,10));
    }
    std::cout <<"("<< xRemaper.remap(pt.x()) << ", "<< yRemaper.remap(pt.y())<< ")," << std::endl;
}
