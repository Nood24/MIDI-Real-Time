//
// Created by Cameron Bennett on 11/03/2020.
//

#include "DanceSet.h"
#include <cassert>
#include <typeinfo>

using namespace std;

void DanceSet::load_instruments() {
    fluid_synth_init();
    this->instruments.clear();
    //See instruments https://musical-artifacts.com/artifacts/738
    Instrument* piano = new Instrument(this->file_location + "piano.csv", this->tempo,this->hardware,0, 0, 1,this);
    Instrument* accordion = new Instrument(this->file_location + "Accordion.csv", this->tempo, this->hardware, 1, 1, 1,this,-12,80);
    Instrument* drums = new Instrument(this->file_location + "Drums.csv", this->tempo,this->hardware,2, 1, 3,this,0,80,true);
    Instrument* bass = new Instrument(this->file_location + "Bass.csv", this->tempo, this->hardware, 3, 1, 4,this,-12,127);
    
    this->instruments.push_back(piano);
    this->instruments.push_back(accordion);
    this->instruments.push_back(drums);
    this->instruments.push_back(bass);

}

void DanceSet::wait_loop_end(){
    for (int i=0; i < this->instruments.size();i++){
        this->instruments[i]->join();
    }
}

void DanceSet::free_instruments(){
    for (int i=0;i< this->instruments.size();i++){
        delete this->instruments[i];
    }
}

void DanceSet::setChordNote(int note){
    //readWrite.lock();
    previousChord[chordIdx] = chordNotes[chordIdx];
    chordNotes[chordIdx] = note;
    chordIdx = (chordIdx+1)%3;
    //readWrite.unlock();
}

bool DanceSet::checkEqual(int *first, int *second){
    for (int i=0; i<4; i++){
        if (first[i] != second[i])
            return 0;
    }
    return 1;
}    

void DanceSet::set_notes(std::vector< unsigned char >* message){
    byte1 =  message->at(0);
    byte2 = message->at(1);
    if (!((byte1>> 4) & 1)){
        return;
    }
    is_bass = ((byte1>> 1) & 1);

    if (is_bass){
        this->previousBass = this->bassNote;
        this->bassNote = byte2;
    }
    else{
        setChordNote(byte2);
    }
    
    if (this->previousBass!=this->bassNote || !checkEqual(this->previousChord,this->chordNotes)){
       cout<<"update \n";
       for (int i=0; i<4; i++){
         instruments[i]->updateNote(this->previousBass!=this->bassNote, this->previousChord!=this->chordNotes);
       } 
    }
}

void DanceSet::start_dance(){
    for (int i=0; i<4; i++){
        this->instruments[i]->start();
    }
}

int DanceSet::get_tempo(){
    return this->tempo;
}

void DanceSet::set_tempo(int tempo) {
    assert((tempo>0)&&(tempo<200));
    this->tempo = tempo;
}

