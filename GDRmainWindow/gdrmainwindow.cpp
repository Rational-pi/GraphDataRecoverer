#include "gdrmainwindow.h"
#include <QMessageBox>
#include <QGraphicsView>
#include <QImageReader>
#include <QDir>
#include "gdrgraphicsview.h"

GDRmainWindow::GDRmainWindow(QWidget *parent) : GDRdropOnMainWindow(parent)
{
    ui.setupUi(this);
    ui.p_graphicsView->setScene(new QGraphicsScene(this));
    ui.p_graphicsView->setHidden(true);
    ui.p_graphicsView->scene()->addRect(10,10,100,100);
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
    ui.p_graphicsView->scene()->clear();
    ui.p_graphicsView->scene()->addPixmap(QPixmap::fromImage(image));
    ui.p_graphicsView->setHidden(false);
    statusBar()->showMessage(tr("Opened \"%1\", %2x%3, Depth: %4").arg(QDir::toNativeSeparators(pathList[0])).arg(image.width()).arg(image.height()).arg(image.depth()));
    setWindowFilePath(pathList[0]);
    return true;
}
