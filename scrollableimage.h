#ifndef SCROLLABLEIMAGE_H
#define SCROLLABLEIMAGE_H

#include <QScrollArea>

#include "pointpointerlabel.h"

class QImage;
class QLabel;
class QScrollBar;

class ScrollableImage : public QScrollArea
{
public:
    ScrollableImage();
    void scaleImage(double factor);
    bool loadFile(const QString &);
public slots:
    void loadFromClipboard();
private:
    QImage image;
    PointPointerLabel *imageLabel;
    double scaleFactor;

    void setImage(const QImage &newImage);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);


    //TODO implement whell interactions
    void wheelEvent(QWheelEvent *event);

};

#endif // SCROLLABLEIMAGE_H
