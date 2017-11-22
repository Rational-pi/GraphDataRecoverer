#include "gdrmainwindow.h"
#include <QMessageBox>
#include <QGraphicsView>
#include <QImageReader>
#include <QDir>
#include "gdrtabgraphicsview.h"

GDRmainWindow::GDRmainWindow(QWidget *parent) : GDRdropOnMainWindow(parent)
{
    ui.setupUi(this);
}

bool GDRmainWindow::open(QStringList pathList){
    QImageReader reader(pathList[0]);
    reader.setAutoTransform(true);
    const QImage image = reader.read();
    if (image.isNull()) {
        QMessageBox::information(this,
                                 QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2").arg(QDir::toNativeSeparators(pathList[0]),reader.errorString())
                                 );
        return false;
    }
    GDRgraphicsView *view=ui.p_tabWidget->addGraphicsView(pathList[0]);
    view->setScene(new QGraphicsScene(this));
    view->scene()->addPixmap(QPixmap::fromImage(image));
    statusBar()->showMessage(tr("Opened \"%1\", %2x%3, Depth: %4").arg(QDir::toNativeSeparators(pathList[0])).arg(image.width()).arg(image.height()).arg(image.depth()));
    setWindowFilePath(pathList[0]);
    return true;
}
