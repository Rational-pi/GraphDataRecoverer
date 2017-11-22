#include "gdrgraphicsview.h"
#include <QtWidgets>

#define CTRL Qt::ControlModifier & QApplication::keyboardModifiers()
void GDRgraphicsView::wheelEvent(QWheelEvent *event){
    bool up = event->delta()>0;
    if (CTRL){
        qreal scaleFactor=up?1.1:0.9;
        scale(scaleFactor,scaleFactor);
    }else QGraphicsView::wheelEvent(event);
}
