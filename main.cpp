#include "GDRmainWindow/gdrmainwindow.h"
#include <QApplication>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale("en_EN"));
    GDRmainWindow w;
    w.show();

    return a.exec();
}
