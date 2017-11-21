#ifndef GDRVIEWBASE_H
#define GDRVIEWBASE_H

#include <QWidget>
#include "gdrcontrollerbase.h"

class GDRviewBase : public QWidget
{
    Q_OBJECT
    GDRcontrollerBase *controller;
public:
    explicit GDRviewBase(QWidget *parent = 0);
    GDRcontrollerBase *getController(){return controller;}
protected:
    virtual void paintEvent(QPaintEvent *event)=0;
    virtual void moveEvent(QMoveEvent *event)=0;
    virtual void resizeEvent(QResizeEvent *event)=0;
};

#endif // GDRVIEWBASE_H
