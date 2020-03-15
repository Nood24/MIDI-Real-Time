//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Instrument.h"

void sendNote(bool on, int channel, int note){
    if (on)
        noteOn(channel,note);
    else
        noteOff(channel,note);
}

void Instrument::updateNote(int channel){
    if (bassOn){
        sendNote(0,channel,previousBass);
        sendNote(1,channel,bassNote);
    }
    if (chordOn){
        sendNote(0,channel,previousChord[0]);
        sendNote(0,channel,previousChord[1]);
        sendNote(0,channel,previousChord[2]);
        sendNote(1,channel,chordNotes[0]);
        sendNote(1,channel,chordNotes[1]);
        sendNote(1,channel,chordNotes[2]);
    }
}

void Instrument::run() {
    int d = 0;
    while(Controller::playing || d%size!=0){
        usleep(timing_factor*timeDeltas[d%size]);
        if (channels[d%size]==2){
            sendNote(onOff[d%size],0,bassNote);
            bassOn = onOff[d%size];
        }
        else{
            sendNote(onOff[d%size],0,chordNotes[0]);
            sendNote(onOff[d%size],0,chordNotes[1]);
            sendNote(onOff[d%size],0,chordNotes[2]);
            chordOn = onOff[d%size];
        }
        d=d+1;
    }
}

void Instrument::extract_from_csv(string filename, vector<int> timeDeltas, vector<int> channels, vector<int> onOff){
    int delta, channel, on;
    string strdelta, strchannel, stron;
    int line = 0;

    ifstream csvfile;
    csvfile.open(filename);
    assert(csvfile.is_open());

    while(csvfile.good()){
        getline(csvfile,strdelta,',');
        getline(csvfile,strchannel,',');
        getline(csvfile,stron,'\n');

        delta = stoi(strdelta);
        channel = stoi(strchannel);
        on = stoi(stron);

        timeDeltas.push_back(delta);
        channels.push_back(channel);
        onOff.push_back(on);
    }
}

