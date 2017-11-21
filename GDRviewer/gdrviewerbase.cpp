#include "gdrviewerbase.h"
#include <QtWidgets>

#define CTRL Qt::ControlModifier & QApplication::keyboardModifiers()
#define SHIFT  Qt::ShiftModifier & QApplication::keyboardModifiers()
void GDRviewerBase::wheelEvent(QWheelEvent *event){
    bool up = event->delta()>0;
    if (CTRL){
        view->getController()->scaleContent(up?1.1:0.9);
    }else{
        int delta = view->getController()->getContentScale()*(up?-5:5);
        if (SHIFT){
            this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value()+delta);
        }else{
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->value()+delta);
        }
    }
    event->accept();
}
