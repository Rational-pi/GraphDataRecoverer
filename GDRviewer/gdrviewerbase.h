#ifndef GDRVIEWERBASE_H
#define GDRVIEWERBASE_H

#include <QScrollArea>
#include "GDRdataBase/gdrviewbase.h"

class GDRviewerBase : public QScrollArea
{
    GDRviewBase *view;
public:
    GDRviewerBase(){}
private:
    void wheelEvent(QWheelEvent *event);
};

#endif // GDRVIEWERBASE_H
