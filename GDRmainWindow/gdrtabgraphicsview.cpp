#include "gdrtabgraphicsview.h"

GDRtabGraphicsView::GDRtabGraphicsView(QWidget *parent):QTabWidget(parent){
    setDocumentMode(true);
    setTabsClosable(true);
    setMovable(true);
    setTabBarAutoHide(false);
    connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(tabCloseRequestedHandler(int)));
    connect(this,SIGNAL(currentChanged(int)),this,SLOT(tabChangedHandler(int)));
}

GDRgraphicsView *GDRtabGraphicsView::addGraphicsView(QString name){
    GDRgraphicsView *v=new GDRgraphicsView(this);
    addTab(v,name);
    return v;
}

void GDRtabGraphicsView::tabCloseRequestedHandler(int id){
    QWidget *w=widget(id);
    removeTab(id);
    delete w;
}

void GDRtabGraphicsView::tabChangedHandler(int id){
    emit viewChanged((GDRgraphicsView*)widget(id));
}
