//
// Created by Cameron Bennett on 11/03/2020.
//
#ifndef CEILIDHBAND_CONTROLLER_H
#define CEILIDHBAND_CONTROLLER_H
#define CSV_FILES './CSVFiles/'

#include "DanceSet.h"
#include "../../../rtmidi/RtMidi.h"

using namespace std;

class DanceSet;
class Controller {
public:
    Controller();
    static string get_file_location(string dance, int tempo);
    static bool playing;
    void load_dance(string dance_name, int tempo);
    void start_playing();
    void stop_playing();
    static DanceSet *current_dance;
    void create_midi_reader(int port_no);
    RtMidiIn *midiin;
    static void change_notes(double deltatime, vector< unsigned char > *message, void */*userData*/);
    static void replicate_midi(double deltatime, std::vector<unsigned char> *message, void */*userdata*/);
private:
    string file_location;
};

#endif
