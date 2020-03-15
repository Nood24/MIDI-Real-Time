//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef CEILIDHBAND_INSTRUMENT_H
#define CEILIDHBAND_INSTRUMENT_H
#include "./cppThread-master/cppThread.h"
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

class Instrument : public CppThread {
public:
    Instrument(string csv_file);

private:
    void run();
    void extract_from_csv(string filename, vector<int> timeDeltas, vector<int> channels, vector<int> onOff);
    void sendNote(bool on, int channel, int note);
    void updateNote(int channel)
    vector<int> timeDeltas, channels, onOff;
    bool chordOn = false;
    bool bassOn = false;
    int size;
    bool bassOn=0;
    bool chordOn=0;
    std::vector<unsigned char>* message;
    int timing_factor;
};


#endif //CEILIDHBAND_INSTRUMENT_H
