#ifndef DROPONMAINWINDOW_H
#define DROPONMAINWINDOW_H

#include <QMainWindow>
class QStringList;

class DropOnMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit DropOnMainWindow(QWidget *parent = nullptr);

signals:

public slots:

protected:
    virtual bool open(QStringList pathList)=0;
    ///this event is called when the mouse enters the widgets area during a drag/drop operation
    void dragEnterEvent(QDragEnterEvent *event);
    ///this event is called when the mouse moves inside the widgets area during a drag/drop operation
    void dragMoveEvent(QDragMoveEvent *event);
    ///this event is called when the mouse leaves the widgets area during a drag/drop operation
    void dragLeaveEvent(QDragLeaveEvent *event);
    ///this event is called when the drop operation is initiated at the widget
    void dropEvent(QDropEvent *event);
};

#endif // DROPONMAINWINDOW_H
