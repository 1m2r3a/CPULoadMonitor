#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //glutInit();
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Monitor");
    w.show();

    return a.exec();
}
