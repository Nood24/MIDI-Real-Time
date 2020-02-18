//*****************************************//
//  cmidiin.cpp
//  by Gary Scavone, 2003-2004.
//
//  Simple program to test MIDI input and
//  use of a user callback function.
//
//*****************************************//

#include <iostream>
#include <cstdlib>
#include "../../../rtmidi/RtMidi.h"
#include "process.h"


bool chooseMidiPort( RtMidiOut *rtmidi )
{
    std::cout << "\nWould you like to open a virtual output port? [y/N] ";

    std::string keyHit;
    std::getline( std::cin, keyHit );

    if ( keyHit == "y" ) {
        rtmidi->openVirtualPort("RtMidi");
        return true;
    }

    std::string portName;
    unsigned int i = 0, nPorts = rtmidi->getPortCount();
    if ( nPorts == 0 ) {
        std::cout << "No output ports available!" << std::endl;
        return false;
    }

    if ( nPorts == 1 ) {
        std::cout << "\nOpening " << rtmidi->getPortName() << std::endl;
    }
    else {
        for ( i=0; i<nPorts; i++ ) {
            portName = rtmidi->getPortName(i);
            std::cout << "  Output port #" << i << ": " << portName << '\n';
        }

        do {
            std::cout << "\nChoose a port number: ";
            std::cin >> i;
        } while ( i >= nPorts );
    }

    std::cout << "\n";
    rtmidi->openPort( i );

    return true;
}


void usage( void ) {
  // Error function in case of incorrect command-line
  // argument specifications.
  std::cout << "\nuseage: cmidiin <port>\n";
  std::cout << "    where port = the device to use (first / default = 0).\n\n";
  exit( 0 );
}
RtMidiOut *midiout = new RtMidiOut();
//check available ports


void mycallback( double deltatime, std::vector< unsigned char > *message, void */*userData*/ )
{
  unsigned int nBytes = message->size();
  setMessage(message);
  //midiout->sendMessage( message );
  for ( unsigned int i=0; i<nBytes; i++ )
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  /*
  if ( nBytes > 0 )
    std::cout << "stamp = " << deltatime << std::endl;
  */
}

// This function should be embedded in a try/catch block in case of
// an exception.  It offers the user a choice of MIDI ports to open.
// It returns false if there are no ports available.
bool chooseMidiPort( RtMidiIn *rtmidi );

int main( int argc, char ** /*argv[]*/ )
{
  RtMidiIn *midiin = 0;

  // Minimal command-line check.
  if ( argc > 2 ) usage();

  try {

    // RtMidiIn constructor
    midiin = new RtMidiIn();

    // Call function to select port.
    if ( chooseMidiPort( midiin ) == false ) goto cleanup;

    // Set our callback function.  This should be done immediately after
    // opening the port to avoid having incoming messages written to the
    // queue instead of sent to the callback function.
    midiin->setCallback( &mycallback );

    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes( false, false, false );


      // Call function to select port.

//      try {
//          if ( chooseMidiPort( midiout ) == false ) goto cleanup;
//      }
//      catch ( RtMidiError &error ) {
//          error.printMessage();
//          goto cleanup;
//      }

    std::cout << "\nReading MIDI input ... press <enter> to quit.\n";
    char input;
    std::cin.get(input);

 } catch ( RtMidiError &error ) {
    error.printMessage();
  
}

 cleanup:

  delete midiin;

  return 0;
}

bool chooseMidiPort( RtMidiIn *rtmidi )
{
  std::cout << "\nWould you like to open a virtual input port? [y/N] ";

  std::string keyHit;
  std::getline( std::cin, keyHit );
  if ( keyHit == "y" ) {
    rtmidi->openVirtualPort();
    return true;
  }

  std::string portName;
  unsigned int i = 0, nPorts = rtmidi->getPortCount();
  if ( nPorts == 0 ) {
    std::cout << "No input ports available!" << std::endl;
    return false;
  }

  if ( nPorts == 1 ) {
    std::cout << "\nOpening " << rtmidi->getPortName() << std::endl;
  }
  else {
    for ( i=0; i<nPorts; i++ ) {
      portName = rtmidi->getPortName(i);
      std::cout << "  Input port #" << i << ": " << portName << '\n';
    }

    do {
      std::cout << "\nChoose a port number: ";
      std::cin >> i;
    } while ( i >= nPorts );
    std::getline( std::cin, keyHit );  // used to clear out stdin
  }

  rtmidi->openPort( i );

  return true;
}
