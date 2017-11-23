#ifndef GDRMAINWINDOW_H
#define GDRMAINWINDOW_H

#include "gdrdroponmainwindow.h"
#include "ui_gdrmainwindow.h"

class GDRmainWindow : public GDRdropOnMainWindow
{
    Q_OBJECT
public:
    explicit GDRmainWindow(QWidget *parent = 0);
private:
    Ui::MainWindow ui;
private slots:
    void viewChangedHandler(GDRgraphicsView *graphicsViewInFocus);
protected:
    bool openSingleImage(QString filepath);
    virtual bool open(QStringList pathList);
};

#endif // GDRMAINWINDOW_H
