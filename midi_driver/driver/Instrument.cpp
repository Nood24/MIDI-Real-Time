//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Instrument.h"

Instrument::Instrument(std::string csv_file, int tempo, VirtualHardwareController& hw, int channel_number, int bank, int sf_ID, DanceSet *dance, int pitch_transform, int velocity, bool drumkit){
	//vector<int> timeDeltas, channels, onOff;
        extract_from_csv(csv_file);
        this->size = this->timeDeltas.size();
        this->timing_factor = 1000000*60.0/(tempo*480.0);
        this->hardware = hw;
        this->instrument_sfID = sf_ID;
        this->FS_channel = channel_number;
        changeInstrument(this->FS_channel,bank,this->instrument_sfID);
        this->dance = dance;
        this->pitch_transform = pitch_transform;
	this->drumkit = drumkit;
	this->velocity = velocity;
	cout << "drumkit: "<< this->drumkit<<endl;
    }


void Instrument::updateNote(bool bass,bool chord){
    if (this->drumkit)
	return;
    if (bass && this->bassOn){
        sendNote(0,this->FS_channel,this->dance->previousBass+this->pitch_transform,this->velocity);
        sendNote(1,this->FS_channel,this->dance->bassNote+this->pitch_transform,this->velocity);
    }
    if (chord && this->chordOn){
        sendNote(0,this->FS_channel,this->dance->previousChord[0]+this->pitch_transform,this->velocity);
        sendNote(0,this->FS_channel,this->dance->previousChord[1]+this->pitch_transform,this->velocity);
        sendNote(0,this->FS_channel,this->dance->previousChord[2]+this->pitch_transform,this->velocity);
        sendNote(1,this->FS_channel,this->dance->chordNotes[0]+this->pitch_transform,this->velocity);
        sendNote(1,this->FS_channel,this->dance->chordNotes[1]+this->pitch_transform,this->velocity);
        sendNote(1,this->FS_channel,this->dance->chordNotes[2]+this->pitch_transform,this->velocity);
    }
}

void Instrument::setVirtualHardware(VirtualHardwareController& hw){
    this->hardware = hw;
}


void Instrument::run(VirtualHardwareController& vhw) {
    int d = 0;
    int drumnotes[3] = {0,59,52};
    while(vhw.playing || d%this->size!=0){
        usleep(this->timing_factor*this->timeDeltas[d%this->size]);
	if (this->drumkit){
		cout<< "sending: "<< drumnotes[this->channels[d%this->size]]<<endl;
		sendNote(this->onOff[d%this->size],this->FS_channel,drumnotes[this->channels[d%this->size]],this->velocity);}
        else if (this->channels[d%this->size]==2){
            sendNote(this->onOff[d%this->size],this->FS_channel,this->dance->bassNote+this->pitch_transform,this->velocity);
            this->bassOn = this->onOff[d%this->size];
        }
        else{
            sendNote(this->onOff[d%this->size],this->FS_channel,this->dance->chordNotes[0]+this->pitch_transform,this->velocity);
            sendNote(this->onOff[d%this->size],this->FS_channel,this->dance->chordNotes[1]+this->pitch_transform,this->velocity);
            sendNote(this->onOff[d%this->size],this->FS_channel,this->dance->chordNotes[2]+this->pitch_transform,this->velocity);
            this->chordOn = this->onOff[d%this->size];
        }
        d=d+1;
    }
}

void Instrument::extract_from_csv(string filename){
    int delta, channel, on;
    string strdelta, strchannel, stron;

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

        this->timeDeltas.push_back(delta);
        this->channels.push_back(channel);
        this->onOff.push_back(on);
    }
}

