#ifndef GDRGRAPHICSVIEW_H
#define GDRGRAPHICSVIEW_H
#include <QGraphicsView>

class GDRgraphicsView : public QGraphicsView
{
public:
    GDRgraphicsView(QWidget *parent = Q_NULLPTR):QGraphicsView(parent){}
protected:

virtual void wheelEvent(QWheelEvent *event);
};

#endif // GDRGRAPHICSVIEW_H
