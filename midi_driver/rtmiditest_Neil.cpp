#include "../../rtmidi/RtMidi.h"
#include <iostream>
#include <cstdlib>

int main() {

  RtMidiIn *midiin = 0;
  RtMidiOut *midiout = 0;
  try {
    midiin = new RtMidiIn();
  }
  catch (RtMidiError &error) {
    error.printMessage();
    exit( EXIT_FAILURE );
  }
}
