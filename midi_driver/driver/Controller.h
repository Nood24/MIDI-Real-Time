//
// Created by Cameron Bennett on 11/03/2020.
//
#ifndef PLAYING_VAR
#define PLAYING_VAR
#include "VirtualHardwareController.h"
#endif

#ifndef CEILIDHBAND_CONTROLLER_H
#define CEILIDHBAND_CONTROLLER_H
#define CSV_FILES "./CSVFiles/"

#include "../../rtmidi/RtMidi.h"
#include "DanceSet.h"
#include <fluidsynth.h>
#include "fluidCustomAPI.h"

using namespace std;

class Controller {
public:
    Controller(VirtualHardwareController& hw){
    	this->hardware = hw;
        cout<<hw.playing << "controler.h\n";
    };
    static string get_file_location(string dance, int tempo);
    void load_dance(string dance_name, int tempo);
    void start_playing(VirtualHardwareController& vhc);
    void stop_playing();
    void set_playing(bool play);
    void create_midi_reader(int port_no);
    RtMidiIn *midiin;
    DanceSet *current_dance;
    VirtualHardwareController hardware;
    //static void change_notes(double deltatime, vector< unsigned char > *message, void */*userData*/);
    //static void replicate_midi(double deltatime, std::vector<unsigned char> *message, void */*userdata*/);
private:
    string file_location;
};

#endif
