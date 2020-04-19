//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Instrument.h"

int Instrument::threads_waiting = 0;
int Instrument::longest_loop_time = 0;
bool Instrument::threads_finished = false;
mutex cv_m;
condition_variable synchronised;

Instrument::Instrument(std::string csv_file, int tempo, VirtualHardwareController *hw, int channel, int bank, int sf_ID, DanceSet* dance ,int pitch_transform, int velocity, bool drumkit){
    extract_from_csv(csv_file);
    this->size = this->timeDeltas.size();
    this->timing_factor = 1000000*60.0/(tempo*480.0);
    this->hardware = hw;
    this->instrument_sfID = sf_ID;
    this->FS_channel = channel;
    change_instrument(this->FS_channel,bank,this->instrument_sfID);
    this->dance = dance;
    this->pitch_transform = pitch_transform;
    this->drumkit = drumkit;
    this->velocity = velocity;
}


void Instrument::update_note(bool bass,bool chord){
    if (this->drumkit)
	return;
    if (bass && this->bassOn){
        send_note(0,this->FS_channel,this->dance->previousBass+this->pitch_transform,0);
        usleep(50);
        send_note(1,this->FS_channel,this->dance->bassNote+this->pitch_transform,this->velocity-20);
    }
    if (chord && this->chordOn){
        send_note(0,this->FS_channel,this->dance->previousChord[0]+this->pitch_transform,0);
        send_note(0,this->FS_channel,this->dance->previousChord[1]+this->pitch_transform,0);
        send_note(0,this->FS_channel,this->dance->previousChord[2]+this->pitch_transform,0);
        usleep(50);
        send_note(1,this->FS_channel,this->dance->chordNotes[0]+this->pitch_transform,this->velocity-20);
        send_note(1,this->FS_channel,this->dance->chordNotes[1]+this->pitch_transform,this->velocity-20);
        send_note(1,this->FS_channel,this->dance->chordNotes[2]+this->pitch_transform,this->velocity-20);
    }
}

void Instrument::resize_midi_loops(){
    int n_loops = Instrument::longest_loop_time/this->total_loop_time;
    int time, channel, on;
    for (int loop=1; loop< n_loops; loop++){
        for (int idx=0; idx<this->size; idx++){
            time = this->timeDeltas[idx];
            channel = this->channels[idx];
            on = this->onOff[idx];
            this->timeDeltas.push_back(time);
            this->channels.push_back(channel);
            this->onOff.push_back(on);
        }
    }
    if (n_loops !=1)
        this->sync_frequency = this->timeDeltas.size()/SYNC_FREQUENCY;
    else
        this->sync_frequency = this->timeDeltas.size();
}
    


void Instrument::set_virtual_hardware(VirtualHardwareController* hw){
    this->hardware = hw;
}

void Instrument::arrive_and_wait(int total_threads){
    Instrument::threads_waiting +=1;
    if (Instrument::threads_waiting == total_threads){
        Instrument::threads_finished = true;
        synchronised.notify_all();
        Instrument::threads_waiting -=1;
        return;
    }
    unique_lock<mutex> lk(cv_m);
    synchronised.wait(lk, []{return Instrument::threads_finished;});
    Instrument::threads_waiting -=1;
}

void Instrument::run() {
    int d = 0;
    int idx = 0;
    int drumnotes[3] = {52,59,52};
    int loop_size = this->timeDeltas.size();
    int total_threads;
    while(this->hardware->playing || d%loop_size!=0){
        idx = d%loop_size;
        usleep(this->timing_factor*this->timeDeltas[idx]);
        if (this->drumkit){
            send_note(this->onOff[idx],this->FS_channel,drumnotes[this->channels[idx]],this->velocity);}
        else if (this->channels[idx]==2){
            send_note(this->onOff[idx],this->FS_channel,this->dance->bassNote+this->pitch_transform,this->velocity);
            this->bassOn = this->onOff[idx];
        }
        else{
            send_note(this->onOff[idx],this->FS_channel,this->dance->chordNotes[0]+this->pitch_transform,this->velocity);
            send_note(this->onOff[idx],this->FS_channel,this->dance->chordNotes[1]+this->pitch_transform,this->velocity);
            send_note(this->onOff[idx],this->FS_channel,this->dance->chordNotes[2]+this->pitch_transform,this->velocity);
            this->chordOn = this->onOff[idx];
        }
        d=d+1;
        
        if (d%this->sync_frequency==0){
            if (d==loop_size){
                d=0;
                total_threads = 4;
            }
            else{
                total_threads = 3;
            }
            Instrument::threads_finished = false;
            arrive_and_wait(total_threads);
        }
    }
}

void Instrument::extract_from_csv(string filename){
    int delta, channel, on;
    string strdelta, strchannel, stron;

    ifstream csvfile;
    csvfile.open(filename);    
    assert(csvfile.is_open());
    this->total_loop_time = 0;
    
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
        
        this->total_loop_time += delta;
    }
    if (this->total_loop_time > Instrument::longest_loop_time){
        Instrument::longest_loop_time = this->total_loop_time;
    }
}

