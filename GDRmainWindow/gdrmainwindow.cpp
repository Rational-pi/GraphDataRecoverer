#include "gdrmainwindow.h"
#include <QMessageBox>
#include <QGraphicsView>
#include <QImageReader>
#include <QDir>
#include <QUrl>
#include "gdrtabgraphicsview.h"
#include "GDRscenes/gdrgraphscene.h"
#include "macros.h"

GDRmainWindow::GDRmainWindow(QWidget *parent) : GDRdropOnMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.p_tabWidget,SIGNAL(viewChanged(GDRgraphicsView*)),this,SLOT(viewChangedHandler(GDRgraphicsView*)));
}

void GDRmainWindow::viewChangedHandler(GDRgraphicsView *graphicsViewInFocus){
    if (graphicsViewInFocus){
        GDRsceneBase *scene=dynamic_cast<GDRsceneBase*>(graphicsViewInFocus->scene());
        if (scene) statusBar()->showMessage(tr("Focused \"%1\"").arg(scene->getName()));
    }
}



bool GDRmainWindow::openSingleImage(QString filepath){
    QString filename=QUrl(filepath).fileName();
    QImageReader reader(filepath);
    reader.setAutoTransform(true);
    const QImage image = reader.read();
    if (image.isNull()){
        MSG_CANT_LOAD(filepath,reader.errorString());
        return false;
    }
    GDRgraphicsView *view=ui.p_tabWidget->addGraphicsView(filename);
    view->setScene(new GDRGraphScene(image,filename,this));
    statusBar()->showMessage(tr("Opened \"%1\", %2x%3, Depth: %4").arg(QDir::toNativeSeparators(filepath)).arg(image.width()).arg(image.height()).arg(image.depth()));
    return true;
}

bool GDRmainWindow::open(QStringList pathList){
    bool status=true;
    for (auto &filepath:pathList)status&=openSingleImage(filepath);
    return status;
}
