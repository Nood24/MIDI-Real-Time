//
// Created by Cameron Bennett on 11/03/2020.
//
#ifndef CEILIDHBAND_CONTROLLER_H
#define CEILIDHBAND_CONTROLLER_H
#define CSV_FILES "./CSVFiles/"

#include "../../../rtmidi/RtMidi.h"
#include "DanceSet.h"

using namespace std;

class Controller {
public:
    bool playing;
    Controller(){
       playing = false;
    }
    static string get_file_location(string dance, int tempo);
    void load_dance(string dance_name, int tempo);
    void start_playing();
    void stop_playing();
    void set_playing(bool play);
    void create_midi_reader(int port_no);
    RtMidiIn *midiin;
    DanceSet *current_dance;
    static void change_notes(double deltatime, vector< unsigned char > *message, void */*userData*/);
    static void replicate_midi(double deltatime, std::vector<unsigned char> *message, void */*userdata*/);
private:
    string file_location;
};

#endif
