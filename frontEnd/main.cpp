#include "mainwindow.h"
#include "hardwareController_Terminal_prototype/TerminalController.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    TerminalController terminal_controller;

    terminal_controller.runThread(w, terminal_controller);

    HardwareController hwtest;
    Controller controller = Controller(hwtest);
    //Set create_midi_reader(1)on pi
    controller.create_midi_reader(1);


    controller.load_dance("gaygordons", 120);
    cout<<"finished loading\n";
    controller.start_playing();




    w.controllerInit();
    w.showMaximized();
    w.show();
    return a.exec();
}
