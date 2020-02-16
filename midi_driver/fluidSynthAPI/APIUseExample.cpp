/*
// Compile with g++ -Wall -D__LINUX_ALSA__ -o test  test.cpp fluidCustomAPI.c  ../../rtmidi/RtMidi.cpp -lasound -lpthread `pkg-config fluidsynth --libs`

*/

#include <stdlib.h>
#include <stdio.h>
#include <fluidsynth.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include "../../rtmidi/RtMidi.h"
#include <iostream>
#include "fluidCustomAPI.h"

using namespace std;

int main( void ){

fluid_synth_init();
cout << "Playing 3 second note!\n";
playNoteOfLength(0,60,3);


cout << "Change Instrument!\n";
changeInstrument(0, 5);

cout << "Playing 3 second note!\n";
playNoteOfLength(0,60,3);

cout << "Closing FluidSynth\n";
deleteFluidSynth();

}
