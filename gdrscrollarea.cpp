#include "gdrscrollarea.h"

#include <QtWidgets>

static void adjustScrollBar(QScrollBar *scrollBar, double factor){
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep()/2)));
}
void GDRscrollArea::scaleContent(double factor) {
    if (!Content) return;
    scaleFactor *= factor;
    this->widget()->resize(scaleFactor * Content->getOriginalSize());
    adjustScrollBar(this->horizontalScrollBar(), factor);
    adjustScrollBar(this->verticalScrollBar(), factor);
}

#define CTRL Qt::ControlModifier & QApplication::keyboardModifiers()
#define SHIFT  Qt::ShiftModifier & QApplication::keyboardModifiers()
void GDRscrollArea::wheelEvent(QWheelEvent *event){
    bool up = event->delta()>0;
    if (CTRL){
        scaleContent(up?1.1:0.9);
    }else{
        int delta = scaleFactor*(up?-5:5);
        if (SHIFT){
            this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value()+delta);
        }else{
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->value()+delta);
        }
    }
    event->accept();
}
