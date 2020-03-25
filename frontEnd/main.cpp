#include "mainwindow.h"
#include "hardwareController_Terminal_prototype/TerminalController.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;
    TerminalController terminal_controller;

    VirtualHardwareController vitrualHardware;

    terminal_controller.runThread(w, terminal_controller,vitrualHardware);

    Controller controller = Controller(vitrualHardware);
    //Set create_midi_reader(1)on pi
    controller.create_midi_reader(1);


    controller.load_dance("gaygordons", 120);
    cout<<"finished loading\n";

    //controller.start_playing();
    std::thread t1(&Controller::start_playing, &controller);




    w.controllerInit();
    w.showMaximized();
    w.show();



    return a.exec();
}
