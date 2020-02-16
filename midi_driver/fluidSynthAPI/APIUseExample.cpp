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
cout << "Hello World!\n";
playNoteOfLength(0,60,3);
cout << "leaving!\n";

}
