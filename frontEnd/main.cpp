#include "mainwindow.h"
//#include "hardwareController_Terminal_prototype/TerminalController.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.showMaximized();
    window.show();

    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    Controller *MidiController = new Controller(virtualHardware,&window);
    std::thread t1(&Controller::run, std::ref(MidiController));

    a.exec();
    MidiController->free_current_dance();
    delete MidiController->midiin;
    delete MidiController->midiout;
    delete virtualHardware;
}
