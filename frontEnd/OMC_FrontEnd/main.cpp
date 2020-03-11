#include "mainwindow.h"
#include "hardwareController_Terminal_prototype/HardwareController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    HardwareController controller;

    controller.runThread(w);
    w.controllerInit();
    w.showMaximized();
    w.show();
    return a.exec();
}
