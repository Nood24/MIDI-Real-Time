#include "../rtmidi/RtMidi.h"
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
  unsigned int nPorts = midiin->getPortCount();
  std::cout << "\n There are "<< nPorts << "Input MIDI inputs available.\n";
  std::string portName;
  for ( unsigned int i=0; i<nPorts; i++ ) {
    try {
      portName = midiin->getPortName(i);
    }
    catch ( RtMidiError &error ) {
      error.printMessage();
      goto cleanup;
    }
    std::cout << " Input Port Number "<< i+1 << ": " << portName << '\n';
  }
 cleanup:
  delete midiin;
  delete midiout;
  return 0;
}
