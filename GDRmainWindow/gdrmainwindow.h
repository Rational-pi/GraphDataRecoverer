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
protected:
    bool openSingle(QString filepath);
    virtual bool open(QStringList pathList);
};

#endif // GDRMAINWINDOW_H
