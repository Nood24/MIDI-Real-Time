# Welcome to the One Man Ceilidh Wiki

One Man Ceilidh is a University of Glasgow project Masters project that aims to allow an accordion player to put on a full ceilidh solo by synthesizing backing music in real time off of a midi input from the addordion.

This site aims to provide useful information to aid in working with the codebase. 

Key topics covered include the Tools, the Codebase and Compiling the project. 

## Tools

Three open source toos have been used to create this project. These tools are fluidsynth, RtMidi and Qt. This section will provide a short overview of tool with the use of said tools being detaied in the codebase section.

### RtMidi

RtMidi is an open source project providing an API that allows systems to interface with Midi input and outputs. One Man Ceilidh used this software to revieve midi input from the accordion. 

See the rtmidi git for more information:

<https://github.com/thestk/rtmidi>

### FluidSynth

FluidSynth is an open source and real time synthesizer used by the One Man Ceilidh project to synthesize the sounds of the Ceilidh band via the use of SoundFont files.  

![Branching](https://github.com/Nood24/MIDI-Real-Time/tree/master/other/images/)

See the FluidSynth homepage and github for more information:

<http://www.fluidsynth.org/>
<https://github.com/FluidSynth/fluidsynth>



### Qt

Qt is an open source widget toolkit which is used by One Man Ceilidh to provide the front end and to compile the project. The Qt Creator IDE is the reccomended way of working on the priject. Downloading Qt Creator and opening the MIDI-Real-Time/frontEnd/OMC_FrontEnd.pro file in the IDE will import all One Man Ceilidh code into the IDE.

For more information see the qt website.

<https://www.qt.io/>

## Codebase

The One Man Ceilidh project is primariy written in C++ to gain the perfamance related benifits of this language in a real time system. 

This section will walk through the files within the system. 

### main.pp

blah

### TerminalController.cpp

blah

### vitrualHardware.cpp

blah

### controller.cpp

blah

### DanceSet.cpp

blah

### Instrument.cpp

blah

### fluidCustomApi.c

blah

## Compiling 
