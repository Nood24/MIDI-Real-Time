//
// Created by Cameron Bennett on 11/03/2020.
//

#include "DanceSet.h"
#include <cassert>
#include <typeinfo>

using namespace std;

void DanceSet::load_instruments() {
    fluid_synth_init();
    //See instruments https://musical-artifacts.com/artifacts/738
    Instrument* piano = new Instrument(this->file_location + "piano.csv", this->tempo,this->hardware,0, 1,this);
    Instrument* accordion = new Instrument(this->file_location + "Accordion.csv", this->tempo, this->hardware, 1, 21,this);
    //Instrument* drums = new Instrument(this->file_location + "Drums.csv", this->tempo,this->hardware,2, 118,this);
    Instrument* bass = new Instrument(this->file_location + "Bass.csv", this->tempo, this->hardware, 3, 34,this);
   
    this->instruments.push_back(accordion);
    this->instruments.push_back(piano);
    //this->instruments.push_back(drums);
    this->instruments.push_back(bass);

}

void DanceSet::wait_loop_end(){
    for (int i=0;i<2;i++){
        this->instruments[i]->join();
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
        this->previousBass = this->bassNote;
        this->bassNote = byte2;
    }
    else{
        setChordNote(byte2);
    }
    if (this->previousBass!=this->bassNote || this->previousChord!=this->chordNotes)
       for (int i=0; i<3; i++){
         instruments[i]->updateNote(0);
       } 
}

void DanceSet::start_dance(){
    cout<<"starting dance \n";
    for (int i=0; i<3; i++){
	//cout << this->instruments[i].timeDeltas.size()<<endl;
        this->instruments[i]->start();
    }
    for (int i=0; i<3; i++){
        this->instruments[i]->join();
    }
    
}

int DanceSet::get_tempo(){
    return this->tempo;
}

void DanceSet::set_tempo(int tempo) {
    assert((tempo>0)&&(tempo<200));
    this->tempo = tempo;
}

