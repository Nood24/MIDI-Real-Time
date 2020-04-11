#include "mainwindow.h"
#include "hardwareController_Terminal_prototype/TerminalController.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    TerminalController terminal_controller;

    w.controllerInit();
    w.showMaximized();
    w.show();


    VirtualHardwareController* vitrualHardware = new VirtualHardwareController();
    cout << "vitrualHardware\n";
    terminal_controller.runThread(w, terminal_controller,vitrualHardware);


    Controller MidiController = Controller(vitrualHardware);
    //Set create_midi_reader(1)on pi
    MidiController.create_midi_reader(1);


    //MidiController.load_dance("gaygordons", 175);
    std::thread t1(&Controller::start_playing, std::ref(MidiController));


    return a.exec();

}
