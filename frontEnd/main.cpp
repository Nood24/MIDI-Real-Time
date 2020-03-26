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
    Controller MidiController = Controller(vitrualHardware);
    //Set create_midi_reader(1)on pi
    MidiController.create_midi_reader(1);

    w.controllerInit();
    w.showMaximized();
    w.show();

    MidiController.load_dance("gaygordons", 120);
    //controller.start_playing();
    std::thread t1(&Controller::start_playing, std::ref(MidiController), std::ref(vitrualHardware));  


    return a.exec();
}
