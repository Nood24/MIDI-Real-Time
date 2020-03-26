//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Instrument.h"

Instrument::Instrument(std::string csv_file, int tempo, VirtualHardwareController& hw, int channel_number, int sf_ID){
	//vector<int> timeDeltas, channels, onOff;
        extract_from_csv(csv_file);
        this->size = this->timeDeltas.size();
        this->timing_factor = 20000000*60.0/tempo/12000.0;
	this->hardware = hw;
        this->instrument_sfID = sf_ID;
        this->FS_channel = channel_number;
        changeInstrument(this->FS_channel,this->instrument_sfID);
    }


void Instrument::updateNote(int channel){
    return;
    if (this->bassOn){
        sendNote(0,this->FS_channel,this->previousBass);
        sendNote(1,this->FS_channel,this->bassNote);
    }
    if (this->chordOn){
        sendNote(0,this->FS_channel,this->previousChord[0]);
        sendNote(0,this->FS_channel,this->previousChord[1]);
        sendNote(0,this->FS_channel,this->previousChord[2]);
        sendNote(1,this->FS_channel,this->chordNotes[0]);
        sendNote(1,this->FS_channel,this->chordNotes[1]);
        sendNote(1,this->FS_channel,this->chordNotes[2]);
    }
}

void Instrument::setVirtualHardware(VirtualHardwareController& hw){
    this->hardware = hw;
}


void Instrument::run(VirtualHardwareController& vhw) {
    int d = 0;
    this->hardware.playing = vhw.playing;
    while(vhw.playing ){
        usleep(this->timing_factor*this->timeDeltas[d%this->size]);
        if (this->channels[d%this->size]==2){
            sendNote(this->onOff[d%this->size],this->FS_channel,this->bassNote);
            this->bassOn = this->onOff[d%this->size];
        }
        else{
            sendNote(this->onOff[d%this->size],this->FS_channel,this->chordNotes[0]);
            sendNote(this->onOff[d%this->size],this->FS_channel,this->chordNotes[1]);
            sendNote(this->onOff[d%this->size],this->FS_channel,this->chordNotes[2]);
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

