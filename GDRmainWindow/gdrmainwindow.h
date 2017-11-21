#ifndef GDRMAINWINDOW_H
#define GDRMAINWINDOW_H

#include <QMainWindow>

#include "ui_gdrmainwindow.h"

class GDRmainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GDRmainWindow(QWidget *parent = 0);

signals:

public slots:

private:
    Ui::MainWindow ui;
};

#endif // GDRMAINWINDOW_H
