#include "gdrmainwindow.h"
#include <QMessageBox>
#include <QGraphicsView>
#include <QImageReader>
#include <QDir>
#include <QUrl>
#include "gdrtabgraphicsview.h"

GDRmainWindow::GDRmainWindow(QWidget *parent) : GDRdropOnMainWindow(parent)
{
    ui.setupUi(this);
}

bool GDRmainWindow::openSingle(QString filepath){
    QString filename=QUrl(filepath).fileName();
    QImageReader reader(filepath);
    reader.setAutoTransform(true);
    const QImage image = reader.read();
    if (image.isNull()) {
        QMessageBox::information(this,
                                 QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2").arg(QDir::toNativeSeparators(filepath),reader.errorString())
                                 );
        return false;
    }
    GDRgraphicsView *view=ui.p_tabWidget->addGraphicsView(filename);
    view->setScene(new QGraphicsScene(this));
    view->scene()->addPixmap(QPixmap::fromImage(image));
    statusBar()->showMessage(tr("Opened \"%1\", %2x%3, Depth: %4").arg(QDir::toNativeSeparators(filepath)).arg(image.width()).arg(image.height()).arg(image.depth()));
    return true;
}

bool GDRmainWindow::open(QStringList pathList){
    bool status=true;
    for (auto &filepath:pathList)status*=openSingle(filepath);
    return status;
}
