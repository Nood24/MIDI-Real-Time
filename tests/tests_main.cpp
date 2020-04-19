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
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
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
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
}

TEST_CASE( "Load song into a controller" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
}

TEST_CASE( "Find Installed Dances" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    MidiController->find_installed_dances("./CSVFiles/gaygordons/");
    REQUIRE( true );
}


TEST_CASE( "Print System State" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    MidiController->find_installed_dances("./CSVFiles/gaygordons/");
    REQUIRE( true );
    MidiController->printSystemState();
    REQUIRE( true );
}


TEST_CASE( "Get Default Song" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    MidiController->find_installed_dances("./CSVFiles/");
    REQUIRE("gaygordons"==MidiController->get_dance_name());
    cout << MidiController->get_left_dance() << "\n";
    REQUIRE( true );
    cout << MidiController->get_right_dance() << "\n";
    REQUIRE( true );
}

TEST_CASE( "Switch Song Right" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    MidiController->find_installed_dances("./CSVFiles/");
    REQUIRE("gaygordons"==MidiController->get_dance_name());
    string right_song =  MidiController->get_right_dance();
    MidiController->shift_dance_right();
    REQUIRE(right_song==MidiController->get_dance_name());
}


TEST_CASE( "Switch Song Left" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    MidiController->find_installed_dances("./CSVFiles/");
    REQUIRE("gaygordons"==MidiController->get_dance_name());
    string left_song =  MidiController->get_left_dance();
    MidiController->shift_dance_left();
    REQUIRE(left_song==MidiController->get_dance_name());
}


TEST_CASE( "System innits as not playing" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    MidiController->find_installed_dances("./CSVFiles/");
    REQUIRE("gaygordons"==MidiController->get_dance_name());
    string left_song =  MidiController->get_left_dance();
    MidiController->shift_dance_left();
    MidiController->hardware->playing;
    REQUIRE(!MidiController->hardware->playing);
}


TEST_CASE( "Create Danceset" ) {
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    REQUIRE( true );
    int mock_int;
    REQUIRE( true );
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    DanceSet *current_dance = new DanceSet("gaygordons", 175, "./CSVFiles/gaygordons/", virtualHardware);
    REQUIRE( true );
}


TEST_CASE( "Create Instrument" ) {
    fluid_synth_init();
    REQUIRE( true );
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    int mock_int;
    REQUIRE( true );
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    DanceSet *current_dance = new DanceSet("gaygordons", 175, "./CSVFiles/gaygordons/", virtualHardware);
    REQUIRE( true );
    Instrument* piano = new Instrument("./CSVFiles/gaygordons/piano.csv", 175,virtualHardware,0, 0, 1,current_dance);
    REQUIRE( true );
    delete_fluidsynth();
    REQUIRE( true );

}


TEST_CASE( "Get current Dance Name" ) {
    fluid_synth_init();
    REQUIRE( true );
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    int mock_int;
    REQUIRE( true );
    char** mock_array;
    REQUIRE( true );
    QApplication a(mock_int, mock_array);
    REQUIRE( true );
    MainWindow window;
    REQUIRE( true );
    Controller *MidiController = new Controller(virtualHardware,&window);
    REQUIRE( true );
    MidiController->load_dance("gaygordons");
    REQUIRE( true );
    DanceSet *current_dance = new DanceSet("gaygordons", 175, "./CSVFiles/gaygordons/", virtualHardware);
    REQUIRE( true );
    Instrument* piano = new Instrument("./CSVFiles/gaygordons/piano.csv", 175,virtualHardware,0, 0, 1,current_dance);
    REQUIRE( true );
    delete_fluidsynth();
    REQUIRE( true );

}






//------ Fluidsynth API Tests ---------------------------------------------

TEST_CASE( "Create a Synth" ) {
    fluid_synth_init();
    REQUIRE( true );
}

TEST_CASE( "Create and delete a Synth" ) {
    fluid_synth_init();
    REQUIRE( true );
    delete_fluidsynth();
    REQUIRE( true );
}



TEST_CASE( "Play a Note" ) {
    fluid_synth_init();
    REQUIRE( true );
    cout << "Playing 3 second note!\n";
    play_note_of_length(0,60,3);
    REQUIRE( true );
}

TEST_CASE( "Change Instrument" ) {
    fluid_synth_init();
    REQUIRE( true );
    cout << "Change Instrument!\n";
    REQUIRE( true );
    change_instrument(0, 0, 20);
    REQUIRE( true );
    void changeInstrument(int channel, int bank, int instrument);
    REQUIRE( true );
    cout << "Playing 3 second note!\n";
    REQUIRE( true );
    play_note_of_length(0,60,3);
    REQUIRE( true );
    delete_fluidsynth();
    REQUIRE( true );
}

