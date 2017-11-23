#ifndef GDRTABGRAPHICSVIEW_H
#define GDRTABGRAPHICSVIEW_H

#include <QTabWidget>
#include "gdrgraphicsview.h"

class GDRtabGraphicsView : public QTabWidget
{
    Q_OBJECT
public:
    explicit GDRtabGraphicsView(QWidget *parent = Q_NULLPTR);

    GDRgraphicsView *addGraphicsView(QString name);
public slots:
    void tabCloseRequestedHandler(int id);






};

#endif // GDRTABGRAPHICSVIEW_H
