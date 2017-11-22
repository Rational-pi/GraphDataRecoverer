#include "gdrdroponmainwindow.h"

#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>

GDRdropOnMainWindow::GDRdropOnMainWindow(QWidget *parent) : QMainWindow(parent){
    setAcceptDrops(true);
}

void GDRdropOnMainWindow::dragEnterEvent(QDragEnterEvent *event){
    event->acceptProposedAction();
}

void GDRdropOnMainWindow::dragMoveEvent(QDragMoveEvent *event){
    event->acceptProposedAction();
}

void GDRdropOnMainWindow::dragLeaveEvent(QDragLeaveEvent *event){
    event->accept();
}

void GDRdropOnMainWindow::dropEvent(QDropEvent *event){
    const QMimeData* mimeData = event->mimeData();
    if (mimeData->hasUrls()){
        QStringList pathList;
        QList<QUrl> urlList = mimeData->urls();
        for (int i = 0; i < urlList.size() && i < 32;++i) {
            pathList.append(urlList.at(i).toLocalFile());
        }

        if(open(pathList))event->acceptProposedAction();
    }
}
