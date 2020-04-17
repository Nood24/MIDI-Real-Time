//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef CEILIDHBAND_DANCESET_H
#define CEILIDHBAND_DANCESET_H

#include <iostream>
#include "Instrument.h"
#include <cassert>
//#include <experimental/barrier>

using namespace std;

class Instrument;

class DanceSet {
public:
    DanceSet(string dance, int tempo, string file_location, VirtualHardwareController* hw);
    void start_dance();
    VirtualHardwareController * hardware;
    void set_notes(std::vector<unsigned char>* message);
    void load_instruments();
    void wait_loop_end();
    int get_tempo();
    void set_tempo(int tempo);
    string get_dance_name();
    int previousChord[3] = {60,64,67};
    int chordNotes[3] = {60,64,67};
    int chordIdx = 0;
    int bassNote = 48;
    int previousBass = 48;
    bool checkEqual(int *first, int *second);
    void free_instruments();
private:
    string dance_name;
    int tempo;
    int byte1;
    int byte2;
    bool is_bass;
    vector<Instrument*> instruments;
    Instrument* bass;
    Instrument* piano;
    void setChordNote(int note);
    string file_location;
    void resize_midi_loops();
};
#endif
