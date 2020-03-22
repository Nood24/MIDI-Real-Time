//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Instrument.h"

void sendNote(bool on, int channel, int note){
    
    if (on){
        noteOn(channel,note);
    }
    else{
        noteOff(channel,note);
}
}

void Instrument::updateNote(int channel){
    return;
    if (this->bassOn){
        sendNote(0,channel,this->previousBass);
        sendNote(1,channel,this->bassNote);
    }
    if (this->chordOn){
        sendNote(0,channel,this->previousChord[0]);
        sendNote(0,channel,this->previousChord[1]);
        sendNote(0,channel,this->previousChord[2]);
        sendNote(1,channel,this->chordNotes[0]);
        sendNote(1,channel,this->chordNotes[1]);
        sendNote(1,channel,this->chordNotes[2]);
    }
}

void Instrument::run() {
    //fluid_synth_init should be called in danceSet.
    //fluid_synth_init();
    int d = 0;
    while(this->hardware.playing || d%this->size!=0){
        usleep(this->timing_factor*this->timeDeltas[d%this->size]);

        if (this->channels[d%this->size]==2){
            sendNote(this->onOff[d%this->size],0,this->bassNote);
            this->bassOn = this->onOff[d%this->size];
        }
        else{
            sendNote(this->onOff[d%this->size],0,this->chordNotes[0]);
            sendNote(this->onOff[d%this->size],0,this->chordNotes[1]);
            sendNote(this->onOff[d%this->size],0,this->chordNotes[2]);
            this->chordOn = this->onOff[d%this->size];
 
        }
        d=d+1;
    }
}

void Instrument::extract_from_csv(string filename){
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

        this->timeDeltas.push_back(delta);
        this->channels.push_back(channel);
        this->onOff.push_back(on);
    }
}

