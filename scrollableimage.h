#ifndef SCROLLABLEIMAGE_H
#define SCROLLABLEIMAGE_H

#include <QScrollArea>

#include "pointpointerlabel.h"
#include "gdrscrollarea.h"

class QImage;
class QLabel;
class QScrollBar;

class ScrollableImage : public GDRscrollArea
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
    //double scaleFactor;

    void setImage(const QImage &newImage);
};

#endif // SCROLLABLEIMAGE_H
