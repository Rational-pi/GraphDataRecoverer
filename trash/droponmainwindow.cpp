#include "droponmainwindow.h"

#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>

DropOnMainWindow::DropOnMainWindow(QWidget *parent) : QMainWindow(parent){
    setAcceptDrops(true);
}

void DropOnMainWindow::dragEnterEvent(QDragEnterEvent *event){
    event->acceptProposedAction();
}

void DropOnMainWindow::dragMoveEvent(QDragMoveEvent *event){
    event->acceptProposedAction();
}

void DropOnMainWindow::dragLeaveEvent(QDragLeaveEvent *event){
    event->accept();
}

void DropOnMainWindow::dropEvent(QDropEvent *event){
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
