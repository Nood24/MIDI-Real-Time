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
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "fluidCustomAPI.h"
#include "../../frontEnd/mainwindow.h"

using namespace std;


class Controller {
public:
    Controller(VirtualHardwareController* hw, MainWindow* window){
    	this->hardware = hw;
        this->gui = window;
    };
    void run();
    void free_current_dance();
    static string get_file_location(string dance, int tempo);
    void load_dance(string dance_name);
    void start_playing();
    void stop_playing();
    void set_playing(bool play);
    void create_midi_reader(int port_no);
    void find_installed_dances(const char* path);
    void shift_dance_left();
    void shift_dance_right();
    void start_stop_dance();
    void printSystemState();
    void process_input(int input);
    string get_right_dance();
    string get_left_dance();
    string get_dance_name();
    int get_tempo(string file_location);
    void monitor_input();
    static void start_current_dance(Controller* controller);
    int dance_index = 0;
    MainWindow* gui;
    RtMidiIn *midiin;
    DanceSet *current_dance;
    vector<string> installed_dances;
    VirtualHardwareController* hardware;
    bool dance_playing = false;
    RtMidiOut *midiout;
    //static void change_notes(double deltatime, vector< unsigned char > *message, void */*userData*/);
    //static void replicate_midi(double deltatime, std::vector<unsigned char> *message, void */*userdata*/);
private:
    string file_location;
};

#endif
