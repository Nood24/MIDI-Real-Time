//
// Created by Cameron Bennett on 11/03/2020.
//

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
#include <shared_mutex>
#include <fstream>
#include <vector>
#include "CSVParse.h"
#include <pthread.h>
#include <unistd.h>
#include "DanceSet.h"
#include "Controller.h"
#include <cassert>

using namespace std;

class Instrument : public CppThread {
public:
    Instrument(std::string csv_file, int tempo){
	vector<int> timeDeltas, channels, onOff;
        extract_from_csv(csv_file,timeDeltas,channels,onOff);
        size = timeDeltas.size();
        timing_factor = 60/tempo/12000;
    }

private:
    void run();
    void extract_from_csv(string filename, vector<int> timeDeltas, vector<int> channels, vector<int> onOff);
    void sendNote(bool on, int channel, int note);
    void updateNote(int channel);
    vector<int> timeDeltas, channels, onOff;
    bool chordOn = false;
    bool bassOn = false;
    int size;
    int previousChord[3] = {60,64,67};
    int chordNotes[3] = {60,64,67};
    int previousBass = 48;
    int bassNote = 48;
    std::vector<unsigned char>* message;
    int timing_factor;
};


#endif //CEILIDHBAND_INSTRUMENT_H
