//
// Created by Cameron Bennett on 11/03/2020.
//

#include "DanceSet.h"
#include <cassert>
#include <typeinfo>

using namespace std;

void DanceSet::load_instruments() {
    fluid_synth_init();
    Instrument bass = Instrument(this->file_location + "piano.csv", this->tempo,this->hardware);
    Instrument piano = Instrument(this->file_location + "piano2.csv", this->tempo,this->hardware);
    Instrument accordion = Instrument(this->file_location + "piano3.csv", this->tempo,this->hardware);
    Instrument drumkit = Instrument(this->file_location + "piano4.csv", this->tempo,this->hardware);
    this->instruments.push_back(bass);
    this->instruments.push_back(piano);
    this->instruments.push_back(accordion);
    this->instruments.push_back(drumkit);
}

void DanceSet::wait_loop_end(){
    for (int i=0;i<4;i++){
        this->instruments[i].join();
    }
}

void DanceSet::setChordNote(int note){
    //readWrite.lock();
    previousChord[chordIdx] = chordNotes[chordIdx];
    chordNotes[chordIdx] = note;
    chordIdx = (chordIdx+1)%3;
    //readWrite.unlock();
}

void DanceSet::set_notes(std::vector< unsigned char >* message){
    byte1 =  message->at(0);
    byte2 = message->at(1);

    is_bass = ((byte1>> 1) & 1);

    if (is_bass){
        previousBass = bassNote;
        bassNote = byte2;
    }
    else{
        setChordNote(byte2);
    }
    if (previousBass!=bassNote || previousChord!=chordNotes)
       for (int i=0; i<4; i++){
         instruments[i].updateNote(0);
       } 
}

void DanceSet::start_dance(){
    cout<<"starting dance \n";
    for (int i=0; i<4; i++){
	//cout << this->instruments[i].timeDeltas.size()<<endl;
        this->instruments[i].start();
    }
    for (int i=0; i<4; i++){
        instruments[i].join();
    }
}

int DanceSet::get_tempo(){
    return this->tempo;
}

void DanceSet::set_tempo(int tempo) {
    assert((tempo>0)&&(tempo<200));
    tempo = tempo;
}

