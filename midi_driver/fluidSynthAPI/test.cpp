/*
// Compile with g++ -Wall -D__LINUX_ALSA__ -o test  test.cpp fluidCustomAPI.c  ../../rtmidi/RtMidi.cpp -lasound -lpthread `pkg-config fluidsynth --libs`

*/


#include <iostream>
#include <cstdlib>
#include "../../rtmidi/RtMidi.h"
#include "fluidCustomAPI.h"


int main( void ){
noteOn(0,64);
playNoteOfLength(0,60,3);

}
