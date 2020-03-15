//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef CEILIDHBAND_DANCESET_H
#define CEILIDHBAND_DANCESET_H

#include "Instrument.h"



using namespace std;

class DanceSet {
public:
    DanceSet(string _dance, int _tempo);
    void start_dance();
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
private:
    string dance;
    int tempo;
    Instrument instruments[4];
};


#endif //CEILIDHBAND_DANCESET_H
