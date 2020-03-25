#include "mainwindow.h"
#include "hardwareController_Terminal_prototype/TerminalController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    TerminalController terminal_controller;

    terminal_controller.runThread(w, terminal_controller);
    w.controllerInit();
    w.showMaximized();
    w.show();
    return a.exec();
}
