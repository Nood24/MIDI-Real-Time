//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef PLAYING_VAR
#define PLAYING_VAR
#include "VirtualHardwareController.h"
#endif

#ifndef CEILIDHBAND_INSTRUMENT_H
#define CEILIDHBAND_INSTRUMENT_H
#include "./cppThread-master/CppThread.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "fluidCustomAPI.h"
#include <stdlib.h>
#include <stdio.h>
#include <fluidsynth.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <shared_mutex>
#include <fstream>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include "DanceSet.h"
#include <cassert>

using namespace std;

void send_note(bool on, int channel, int note);

class DanceSet;

class Instrument : public CppThread {
public:
    Instrument(std::string csv_file, int tempo, VirtualHardwareController *hw, int channel, int bank, int sf_ID, DanceSet* dance ,int pitch_transform = 0, int velocity = 90, bool drumkit = false);
    void update_note(bool bass, bool chord);
    void set_virtual_hardware(VirtualHardwareController* hw);
    void resize_midi_loops();
    string name;
    static int longest_loop_time;
private:
    void run();

private:
    int total_loop_time;
    void extract_from_csv(string filename);
    static void arrive_and_wait();
    vector<int> timeDeltas, channels, onOff;
    static int threads_waiting;
    static bool threads_finished;
    bool chordOn = false;
    int velocity;
    bool bassOn = false;
    int pitch_transform;
    VirtualHardwareController* hardware;
    int size;
    bool drumkit;
    int previousChord[3] = {60,64,67};
    int chordNotes[3] = {60,64,67};
    int previousBass = 48;
    int bassNote = 48;
    std::vector<unsigned char>* message;
    double timing_factor;
    int FS_channel;
    DanceSet *dance;
    int instrument_sfID;
};



#endif //CEILIDHBAND_INSTRUMENT_H
