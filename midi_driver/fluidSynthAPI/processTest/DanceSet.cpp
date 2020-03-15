//
// Created by Cameron Bennett on 11/03/2020.
//

#include "DanceSet.h"

using namespace std;

DanceSet::DanceSet(string dance, int tempo, filelocation) {
    dance = dance;
    tempo = tempo;
    file_location = filelocation;
}

void DanceSet::load_instruments() {
    fluid_synth_init();

    Instrument bass = Instrument(file_location + 'bass.csv');
    Instrument piano = Instrument(file_location + 'piano.csv');
    Instrument accordion = Instrument(file_location + 'accordion.csv');
    Instrument drumkit = Instrument(file_location + 'drumkit.csv');

    instruments = [bass, piano, accordion, drumkit];
}

void DanceSet::wait_loop_end(){
    for (i=0;i<4;i++;){
        instruments[i].join();
    }
}

void setChordNote(int note){
    //readWrite.lock();
    previousChord[chordIdx] = chordNotes[chordIdx];
    chordNotes[chordIdx] = note;
    chordIdx = (chordIdx+1)%3;
    //readWrite.unlock();
}

static void set_notes(double deltatime, std::vector< unsigned char > *message, void */*userData*/ ){
    Controller::playing = True;
    message = newMessage;
    byte1 =  message->at(0);
    byte2 = message->at(1);

    is_bass = isKthBitSet(byte1,2);

    if (is_bass){
        previousBass = bassNote;
        bassNote = byte2;
    }
    else{
        setChordNote(byte2);
    }
    if (previousBass!=bassNote || previousChord!=chordNotes)
        updateNote(0);
}

void DanceSet::start_dance(){
    for (i=0; i<4; i++){
        instruments[i].start();
    }
    for (i=0; i<4; i++){
        instruments[i].join();
    }
}

void DanceSet::get_tempo(int tempo){
    return tempo;
}

void DanceSet::set_tempo(int tempo) {
    assert((tempo>0)&&(tempo<200))
    tempo = tempo;
}

