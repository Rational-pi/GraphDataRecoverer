#ifndef GDRTABGRAPHICSVIEW_H
#define GDRTABGRAPHICSVIEW_H

#include <QTabWidget>
#include "gdrgraphicsview.h"

class GDRtabGraphicsView : public QTabWidget
{
public:
    explicit GDRtabGraphicsView(QWidget *parent = Q_NULLPTR):QTabWidget(parent){
        setDocumentMode(true);
        setTabsClosable(true);
        setMovable(true);
        setTabBarAutoHide(false);
    }

    GDRgraphicsView *addGraphicsView(QString name){
        GDRgraphicsView *v=new GDRgraphicsView(this);
        addTab(v,name);
        return v;
    }

};

#endif // GDRTABGRAPHICSVIEW_H
