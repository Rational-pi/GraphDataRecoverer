#ifndef GDRGRAPHICSVIEW_H
#define GDRGRAPHICSVIEW_H
#include <QGraphicsView>

class GDRgraphicsView : public QGraphicsView
{
public:
    GDRgraphicsView(QWidget *parent = Q_NULLPTR);

protected:
    virtual void wheelEvent(QWheelEvent *event);
    virtual void drawBackground(QPainter *painter, const QRectF &rect);
    virtual void mousePressEvent(QMouseEvent *event);
private:
    qreal m_scale;
    QBrush bkgBrush;
    QPen borderPen;
};

#endif // GDRGRAPHICSVIEW_H
