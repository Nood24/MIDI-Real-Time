# Welcome to the One Man Ceilidh Wiki

One Man Ceilidh is a University of Glasgow Masters project that aims to allow an accordion player to put on a full ceilidh solo by synthesizing backing music in real time off of a midi input from the accordion.

This site aims to provide useful information to aid in working with the codebase. 

Key topics covered include the Tools, the Codebase and Compiling the project. 

## Tools

Three open source tools have been used to create this project. These tools are fluidsynth, RtMidi and Qt. This section will provide a short overview of tool with the use of said tools being detailed in the codebase section.

### RtMidi

RtMidi is an open source project providing an API that allows systems to interface with Midi input and outputs. One Man Ceilidh used this software to recive midi input from the accordion. 

See the rtmidi git for more information:

<https://github.com/thestk/rtmidi>

### FluidSynth

FluidSynth is an open source and real time synthesizer used by the One Man Ceilidh project to synthesize the sounds of the Ceilidh band via the use of SoundFont files.  


See the FluidSynth homepage and github for more information:

<http://www.fluidsynth.org/>
<https://github.com/FluidSynth/fluidsynth>



### Qt

Qt is an open source widget toolkit which is used by One Man Ceilidh to provide the front end and to compile the project. The Qt Creator IDE is the recommended way of working on the project. Downloading Qt Creator and opening the MIDI-Real-Time/frontEnd/OMC_FrontEnd.pro file in the IDE will import all One Man Ceilidh code into the IDE.

For more information see the qt website.

<https://www.qt.io/>

## Codebase

The One Man Ceilidh project is primary written in C++ to gain the performance related benefits of this language in a real time system. 

This section will walk through the files within the system. 

Note: This section will only discus .cpp files. Each .cpp file also has a .h file associated with it.

### main.pp

main.cpp is the file with the highest level of abstraction in the One Man Ceilidh project. It instantiates the key objects in the system and sets them running. main.cpp can be found at  <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/main.cpp>.

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
```

main.cpp does the following:
1. Creates the Qt front end my calling MainWindow w. Mainwindow being defined in mainwindow.cpp.
1. Creates a terminalController defined in TerminalController.cpp which keeps track of the state of the system and accepts inputs inputs through the terminal.
1. Creates a virtualHardware object. This object contains system state information such as. If a song is playing and which song is playing. 
1. Creates a MidiController object which is defined in controller.cpp. This is the object which is responsible for receiving inputs from accordion midi, loading songs and synthesizing the correct output sounds.


### mainwindow.cpp

mainwindow.cpp implements the Qt front end of the system. It can be seen at <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/mainwindow.cpp>.



### vitrualHardware.cpp

vitrualHardware.cpp is a small class that keeps track of is a song is playing and what song is playing. The system looks to this object to determine state. This file can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/VirtualHardwareController.cpp>

### controller.cpp

controller.cpp is the object that loads songs, revieves Midi inputs and passes on those values to lower evels of abstraction and contrtolls the state of the system through interacting with the user through the terminal. The object can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/Controller.cpp>. 

### DanceSet.cpp

DanceSet is an object initializes and keeps track of individual instruments in a song and manages the starting and stopping of a song. It can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/DanceSet.cpp>. Dance set does this by loading pre defined CSVs, and setting up the fluidsynth synthesizer to play the correct instruments on the correct channels. 

### Instrument.cpp

Instrument.cpp is the object which plays sounds via the FluidSynth API. This class contains the logic responsible for paying notes and making sure that the sound output is synchronized, musical and responding to the MIDI input from the accordion. It can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/Instrument.cpp>.

### fluidCustomApi.c

The fluidCustomApi.c is a wrapper written for the FuildSynth API to simplify functionality. Note that this is a c file as the FluidSynth API is written in c. This is a very DRY bit of code. It is very reusable and could be used for many real time FluidSynth applications. 

The fluidcustomAPI can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/fluidCustomAPI.c>.


### CppThread.h

CppThread.h is a class which is extended by instrument.h and instrument.cpp to allow the instruments to run concurrently in threads. Elsewhere in the project std:thread method is used to run threads. This is not ideal as these classes are less extensible. However they are perfectly functional. 

CppThread.h can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/cppThread-master/CppThread.h>. 

### TerminalController.cpp

TerminalController.cpp is a depricated replacement for the planned hardware pedals which unfortunaty coud not be completed due to the closure of labs. This class has been merged with the controler class. It was last used in the change_song branch. This object can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/hardwareController_Terminal_prototype/TerminalController.cpp>. The terminal controller is responsible for receiving inputs from the terminal, keeping track of system state and then updating the virtual hardware object which is passed to other parts of the system to make this information accessible. 

## Compiling 

### Simple How to Compile

To compile the project do the following.

1. Get yourself a machine running linux. Eg Raspberry Pi or Ubuntu system.
1. Clone the project with git clone --recurse-submodules -j8 https://github.com/Nood24/MIDI-Real-Time.git
1. Install dependencies. They are listed in the project README and in .travis.yml <https://github.com/Nood24/MIDI-Real-Time/blob/master/README.md>.
1. cd into the build_and_run directory
1. run make
1. This will project a OneManCeilidh file. Run it with ./OneManCeilidh command and the system will start. 
1. If this fails it is most likely an issue with your environment. 

### Detailed How to Compile

The make file in the build_and_run directory is for user convenience. It makes calls in other files and copies the built executibles into the buildAndRun directory. The project compiles using Qmake. Qmake is called on the project .pro file at MIDI-Real-Time/frontEnd/OMC_FrontEnd.pro. This produces a make file which can be run to compile the project. The OMC_FrontEnd.pro file contains all the programs that make up the project and the libraries that they depend upon. If a new file is created and you wish to integrate it into the project, you must add this file name to the .pro file so that it will link and compile. 

## Using the System

### Basic Opperation

Using the system is pretty straight forward. Running the system brings up a Qt display which shows left song, right song, current song and a play/pause button. 

Interact with this Qt display via the terminal in which you are running the system. Enter "1" to switch song left, "2" to switch song right and "3" to play/pause a song. 

When pausing a song the song will always continue to the end of the tune before ending. Text will become red when pause is pressed to show that a stop command has been queued. 

### Installing a New Song

Songs are installed as CSV files made up of a top level directory with a song name and then sub direcroties of CSV files providing the notes of the different instruments. Add a song directory to the following directory /MIDI-Real-Time/midi_driver/driver/CSVFiles for the song to be automaticay loaded into the system on startup. 

## CI and Testing 

CI and Test tools are being used in this project to ensure that the latest version of the project is always in a releasable state. 

### CI

CI is managed using Travis https://travis-ci.com/. Travis automatically build and runs the project release build and test build upon every commit to ensure that the project is always in good health. The the Travis build setup is defined in /MIDI-Real-Time/.travis.yml.

### Tests

Unfortunately the team has not been able to configure Travis to run tests with every commit. Because of this tests are run manually by developers. This is done by the following process: 

1. Open a terminal
1. cd into /MIDI-Real-Time/tests
1. run "qmake"
1. run "make"
1. run ./tests

The projects tests have been created using Catch2 https://github.com/catchorg/Catch2. The team has found this to be a very useful open source framework for producing tests. The project tests can be found at https://github.com/Nood24/MIDI-Real-Time/blob/master/tests/tests_main.cpp.


## Conclusion

The One Man Ceilidh team have had good fun working on this project and we hope you do too! If you have any questions feel free to drop us a message on twitter @OneManCeilidh https://twitter.com/OneManCeilidh.

Best Regards,

The One Man Ceilidh Team. 




