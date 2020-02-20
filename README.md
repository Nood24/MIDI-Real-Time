# MIDI-Real-Time
Real Time Project

A University of Glasgow ENG5220: Real Time Embedded Programming (2019-20) project.

This project aims to use the MIDI signal from the playing of a single accordion to produce the sound of a full ceilidh band. 
 
The system is made up of a custom pedal box, a Rasperry Pi 3B+ and an LCD display. The Pedals and LCD display allow the system to be controlled in a hands free environment and the pi will provide the procesing of the accordion MIDI signal into an AUX output of a full ceilidh band.

![High level system architecture](/Documentation/systemArchitecture.PNG)

Authors:

Neil Wood: neilwood1997@gmail.com
Seun Ajijola: sajijola@gmail.com
Cameron Bennett:Cameron.b97.cb@gmail.com

Twitter: https://twitter.com/OneManCeilidh

Dependancies:

RTMidi Dependancies:

sudo apt-get install libtool

sudo apt-get install automake

sudo apt-get install autoconf

Other:

sudo apt-get install libasound2-dev : Allows RTMIDI to interacvt with ALSA.

sudo apt-get install fluidsynth : Synth MIDI into analogue output.

sudo apt-get install libfluidsynth-dev: Allows use of fluidsynth API.
