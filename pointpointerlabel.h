#ifndef POINTPOINTERLABEL_H
#define POINTPOINTERLABEL_H

#include <QLabel>

class PointPointerLabel : public QLabel
{
public:
    PointPointerLabel(QWidget *parent = 0);
    void resize(int w, int h);
    void resize(const QSize &p);

protected:
    virtual void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    virtual void moveEvent(QMoveEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // POINTPOINTERLABEL_H
