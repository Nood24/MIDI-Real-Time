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

(https://github.com/Nood24/MIDI-Real-Time/blob/master/other/images/QtCreator.png)

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

main.cpp is the file with the highest level of abstraction in the One Man Ceilidh project. It instantiates the key objects in the system and sets them runnig. main.cpp can be found at  <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/main.cpp>.

It is worth running through this file quickly. A figure of it's operation is shown below. 


```cpp
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    TerminalController terminal_controller;

    w.controllerInit();
    w.showMaximized();
    w.show();

    VirtualHardwareController* vitrualHardware = new VirtualHardwareController();
    cout << "vitrualHardware\n";
    terminal_controller.runThread(w, terminal_controller,vitrualHardware);

    Controller MidiController = Controller(vitrualHardware);
    //Set create_midi_reader(1)on pi
    MidiController.create_midi_reader(1);

    MidiController.load_dance("gaygordons", 175);
    //controller.start_playing();
    std::thread t1(&Controller::start_playing, std::ref(MidiController));

    return a.exec();

}
}
```

main.cpp does the following:
1. Creates the Qt front end my caling MainWindow w. Mainwindow being defined in mainwindow.cpp.
1. Creates a terminalController defined in TerminalController.cpp which keeps track of the state of the system and accepts inputs inputs through the terminal.
1. Creates a virtualHardware object. This object contains system state information such as. If a song is playing and which song is playing. 
1. Creates a MidiController object which is defined in controller.cpp. This is the object which is responsible for recieving inputs from accordion midi, loading songs and synthesizing the correct output sounds.


### mainwindow.cpp

### TerminalController.cpp

TerminalController.cpp is a replacement for the planned hardware pedals which unfortunaty coud not be completed due to the closure of labs. This object can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/hardwareController_Terminal_prototype/TerminalController.cpp>. The terminal controler is responsible for revieing inputs from the terminal, keeping track of system state and then updateing the virtual hardware object which is passed to other parts of the system to make this information accessible. 

### vitrualHardware.cpp

vitrualHardware.cpp is a small class that keeps track of is a song is playing and what song is playing. The system looks to this object to determine state. This file can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/VirtualHardwareController.cpp>

### controller.cpp

controller.cpp is the object that loads songs, revieves Midi inputs and passes on those values to lower evels of abstraction. The object can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/Controller.cpp>. 

### DanceSet.cpp

DanceSet is an object initializes and keeps track of individual instruments in a song and manages the starting and stopping of a song. It can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/DanceSet.cpp>. Dance set does this by loading pre defined CSVs, and setting up the fluidsynth synthesizer to play the correct instruments on the correct channels. 

### Instrument.cpp

Instrument.cpp is the object which plays sounds via the fluidsynth API. It can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/Instrument.cpp>.

### fluidCustomApi.c

The fluidCustomApi.c is a wrapper written for the FuildSynth API to simplify functionality. Note that this is a c file as the FluidSynth API is written in c.

## Compiling 

### Simple How to Compile

To compile the project do the following.

1. Get yourself a machine running linux. Eg Raspberry Pi or Ubuntu system.
1. Clone the projec with git clone --recurse-submodules -j8 https://github.com/Nood24/MIDI-Real-Time.git
1. Install dependancies. They are listed in the project README and in .travis.yml <https://github.com/Nood24/MIDI-Real-Time/blob/master/README.md>.
1. cd into the build_and_run directory
1. run make
1. This will project a OneManCeilidh file. Run it with ./OneManCeilidh command and the system will start. 
1. If this fails it is most liky an issue with your enviromnent. 

### Detailed How to Compile

The make file in the build_and_run directory is for convienience. The project compies using Qmake. Qmake is called on the project .pro file at MIDI-Real-Time/frontEnd/OMC_FrontEnd.pro. This produces a make file which can be run to compile the project.  
