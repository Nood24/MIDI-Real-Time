// Let Catch provide main():

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../midi_driver/driver/Instrument.h"
#include "mock_mainwindow.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>

int mock_int;
char** mock_array;

QApplication a(mock_int, mock_array);

MainWindow window;

VirtualHardwareController *virtualHardware = new VirtualHardwareController();

Controller *MidiController = new Controller(virtualHardware,&window);


TEST_CASE( "Load songs into a controller" ) {
    
    REQUIRE( "gaygordons" == "swag" );
}

