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
    cout << "about to run\n";
    while(hardware.playing || d%size!=0){
        usleep(timing_factor*timeDeltas[d%size]);
        if (this->channels[d%this->size]==2){
            sendNote(this->onOff[d%size],0,this->bassNote);
            this->bassOn = this->onOff[d%size];
        }
        else{
            sendNote(this->onOff[d%size],0,this->chordNotes[0]);
            sendNote(this->onOff[d%size],0,this->chordNotes[1]);
            sendNote(this->onOff[d%size],0,this->chordNotes[2]);
            chordOn = this->onOff[d%size];
        }
        d=d+1;
    }
}

void Instrument::extract_from_csv(string filename, vector<int> &timeDeltas, vector<int> &channels, vector<int> &onOff){
    int delta, channel, on;
    string strdelta, strchannel, stron;

    ifstream csvfile;
    cout<<filename<<"\n";
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

