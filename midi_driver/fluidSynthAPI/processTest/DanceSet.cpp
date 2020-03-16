//
// Created by Cameron Bennett on 11/03/2020.
//

#include "DanceSet.h"
#include <cassert>

using namespace std;

void DanceSet::load_instruments() {
    fluid_synth_init();

    Instrument bass = Instrument(file_location + "bass.csv", tempo);
    Instrument piano = Instrument(file_location + "piano.csv", tempo);
    Instrument accordion = Instrument(file_location + "accordion.csv", tempo);
    Instrument drumkit = Instrument(file_location + "drumkit.csv", tempo);

    instruments = {bass, piano, accordion, drumkit};
}

void DanceSet::wait_loop_end(){
    for (int i=0;i<4;i++){
        instruments[i].join();
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
    for (int i=0; i<4; i++){
        instruments[i].start();
    }
    for (int i=0; i<4; i++){
        instruments[i].join();
    }
}

int DanceSet::get_tempo(){
    return tempo;
}

void DanceSet::set_tempo(int tempo) {
    assert((tempo>0)&&(tempo<200));
    tempo = tempo;
}

