#ifndef GDRSCROLLAREA_H
#define GDRSCROLLAREA_H

#include <QScrollArea>

class GDRscrollArea : public QScrollArea
{
    class GDRscrollAreaContent
    {
    public:
        virtual QSize getOriginalSize()=0;
    };
public:
    GDRscrollArea():scaleFactor(1),Content(nullptr){}
    void setContent(GDRscrollAreaContent *Content){this->Content=Content;}
private:
    void wheelEvent(QWheelEvent *event);
    void scaleContent(double factor);
    double scaleFactor;
    GDRscrollAreaContent *Content;
};

#endif // GDRSCROLLAREA_H
