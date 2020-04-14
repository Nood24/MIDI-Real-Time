// Let Catch provide main():

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../midi_driver/driver/Instrument.h"
#include "mock_mainwindow.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>
#include <thread>

//------ Custom Object Tests ---------------------------------------------


TEST_CASE( "Create a Qt mainwindow") {
    int mock_int;
    char** mock_array;
    QApplication a(mock_int, mock_array);
    MainWindow window;
    REQUIRE(true);
}


TEST_CASE( "Create Virtual Hardware") {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
}


TEST_CASE( "Create a MidiController") {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    int mock_int;
    char** mock_array;

    QApplication a(mock_int, mock_array);

    MainWindow window;
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
}

TEST_CASE( "Load song into a controller" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    int mock_int;
    char** mock_array;

    QApplication a(mock_int, mock_array);

    MainWindow window;
    Controller *MidiController = new Controller(virtualHardware,&window);
    MidiController->load_dance("gaygordons",175);
    REQUIRE( true );
}

//------ Fluidsynth API Tests ---------------------------------------------

TEST_CASE( "Create a Synth" ) {
    fluid_synth_init();
    REQUIRE( true );
}

TEST_CASE( "Create and delete a Synth" ) {
    fluid_synth_init();
    deleteFluidSynth();
    REQUIRE( true );
}



TEST_CASE( "Play a Note" ) {
    fluid_synth_init();
    cout << "Playing 3 second note!\n";
    playNoteOfLength(0,60,3);
    REQUIRE( true );
}

TEST_CASE( "Change Instrument" ) {
    fluid_synth_init();
    cout << "Change Instrument!\n";
    changeInstrument(0, 0, 20);
    void changeInstrument(int channel, int bank, int instrument);

    cout << "Playing 3 second note!\n";
    playNoteOfLength(0,60,3);

    deleteFluidSynth();
    REQUIRE( true );
}


