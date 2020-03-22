//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef PLAYING_VAR
#define PLAYING_VAR
#include "HardwareController.h"
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
#include <shared_mutex>
#include <fstream>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include "DanceSet.h"
#include <cassert>

using namespace std;

void sendNote(bool on, int channel, int note);

class Instrument : public CppThread {
public:
    Instrument(std::string csv_file, int tempo, HardwareController hw){
	//vector<int> timeDeltas, channels, onOff;
<<<<<<< Updated upstream
        extract_from_csv(csv_file);
        this->size = this->timeDeltas.size();
        this->timing_factor = 20000000*60.0/tempo/12000.0;
	this->hardware = hw;
=======
        extract_from_csv(csv_file,this->timeDeltas,this->channels,this->onOff);
        size = this->timeDeltas.size();
        this->timing_factor = 20000000*60.0/tempo/12000.0;
	hardware = hw;
>>>>>>> Stashed changes
    }
    void updateNote(int channel);

private:
    void run();

private:
    void extract_from_csv(string filename);
    vector<int> timeDeltas, channels, onOff;
    bool chordOn = false;
    bool bassOn = false;
    HardwareController hardware;
    int size;
    int previousChord[3] = {60,64,67};
    int chordNotes[3] = {60,64,67};
    int previousBass = 48;
    int bassNote = 48;
    std::vector<unsigned char>* message;
    double timing_factor;
};


#endif //CEILIDHBAND_INSTRUMENT_H
