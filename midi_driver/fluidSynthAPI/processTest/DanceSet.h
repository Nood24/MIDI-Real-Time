//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef CEILIDHBAND_DANCESET_H
#define CEILIDHBAND_DANCESET_H


#include "Controller.h"
#include "Instrument.h"
#include <cassert>

using namespace std;

class Controller;
class Instrument;

class DanceSet {
public:
    DanceSet(string dance, int tempo, string file_location, Controller& controller) {
       dance = dance;
       tempo = tempo;
       file_location = file_location;
       controller = controller;
    }
    void start_dance();
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
    Controller *controller;
private:
    string dance;
    int tempo;
    int byte1;
    int byte2;
    bool is_bass;
    vector<Instrument> instruments;
    void setChordNote(int note);
    string file_location;
};
#endif
