# Welcome to the One Man Ceilidh Wiki

One Man Ceilidh is a University of Glasgow Masters project that allows an accordion player to put on a full ceilidh solo by synthesizing backing music in real time off of a midi input from the accordion.

The full system ran be run on a Raspberry Pi 3B+ or most other Linux systems, with the whole system being fully open source and avalable to the public. 

This site aims to provide useful information to aid in working with the codebase. 

Key topics covered include the Tools, the Codebase, Compiling the project, running the project, a short program guide and the testing/CI of the github project. 

---

## Tools

Three open source tools have been used to create this project. These tools are FluidSynth, RtMidi and Qt. This section will provide a short overview of these tools. 

### RtMidi

RtMidi is an open source project providing an API that allows systems to interface with Midi input and outputs. One Man Ceilidh used this software to receive midi input from the accordion. 


See the RtMidi git for more information:

<https://github.com/thestk/rtmidi>

### FluidSynth

FluidSynth is an open source and real time synthesizer used by the One Man Ceilidh project to synthesize the sounds of the Ceilidh band via the use of SoundFont files.  


See the FluidSynth homepage and github for more information:

1. <http://www.fluidsynth.org/>
1. <https://github.com/FluidSynth/fluidsynth>

The One Man Ceilidh system uses a custom SoundFont file which is used to provide FluidSynth with the instruments that create or sound. The One Man Ceilidh soundFont can be seen at <https://github.com/Nood24/MIDI-Real-Time/tree/master/CustomSoundfonts>

---

### Qt

Qt is an open source widget toolkit which is used by One Man Ceilidh to provide the front end of the project. Qmake is used to compile the project and the Qt Creator IDE is the recommended way of working on the project. Downloading Qt Creator and opening the MIDI-Real-Time/frontEnd/OMC_FrontEnd.pro file in the IDE will import all One Man Ceilidh code into the IDE and provides a good way of quickly getting up to speed with the source code. 

For more information see the Qt website.

<https://www.qt.io/>

## Codebase

The One Man Ceilidh project is primarily written in C++ to gain the performance-related benefits of this language in a real time system.

This section will walk through the files within the system. 

Note: This section will only discuss .cpp files. Each .cpp file also has a .h file associated with it.

### main.pp

main.cpp is the file with the highest level of abstraction in the One Man Ceilidh project. It instantiates the key objects in the system and sets them running. main.cpp can be found at  <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/main.cpp>.

It is worth running through this file quickly. A figure of its operation is shown below. 


```cpp
#include "mainwindow.h"
#include "../midi_driver/driver/Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.showMaximized();
    window.show();

    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    Controller *MidiController = new Controller(virtualHardware,&window);
    std::thread t1(&Controller::run, std::ref(MidiController));

    a.exec();
    MidiController->free_current_dance();
    delete MidiController->midiin;
    delete MidiController->midiout;
    delete virtualHardware;
}

```

main.cpp does the following:
1. Creates the Qt front end my calling MainWindow window. Mainwindow being defined in mainwindow.cpp.
1. Creates a virtualHardware object. This object contains system state information such as if a song is playing and which song is playing. 
1. Creates a MidiController object which is defined in controller.cpp. This is the object which is responsible for receiving inputs from accordion midi, maintaining system state, interfacing with the user through command line controlling the objects responsible for playing a song.


### mainwindow.cpp

mainwindow.cpp implements the Qt front end of the system. It can be seen at <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/mainwindow.cpp>.



### VirtualHardwareController.cpp.cpp

vitrualHardware.cpp is a small class that has been made to replace the foot pedals which could not be completed due to Covid-19. The class  keeps track of is a song is playing, what song is playing and gets inputs from the user via the terminal. The system looks to this object to determine system state. This file can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/VirtualHardwareController.cpp>

### controller.cpp

controller.cpp is the object that loads songs, receives Midi inputs and passes on those values to lower levels of abstraction and controls the state of the system through interacting with the user through the terminal. The object can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/Controller.cpp>. 

### DanceSet.cpp

DanceSet is an object initializes and keeps track of individual instruments in a song and manages the starting and stopping of a song. It can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/DanceSet.cpp>. Dance set does this by loading pre-defined CSVs, and setting up the FluidSynth synthesizer to play the correct instruments on the correct channels. 

### Instrument.cpp

Instrument.cpp is the object which plays sounds via the FluidSynth API. This class contains the logic responsible for paying notes and making sure that the sound output is synchronized, musical and responding to the MIDI input from the accordion. It can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/Instrument.cpp>.

### fluidCustomApi.c

The fluidCustomApi.c is a wrapper written for the FuildSynth API to simplify functionality. Note that this is a c file as the FluidSynth API is written in c. This is a very DRY bit of code. It is very reusable and could be used for many real time FluidSynth applications. 

The fluidcustomAPI can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/fluidCustomAPI.c>.


### CppThread.h

CppThread.h is a class which is extended by instrument.h and instrument.cpp to allow the instruments to run concurrently in threads. Elsewhere in the project std:thread method is used to run threads. This is not ideal as these classes are less extensible. However, they are perfectly functional. 

CppThread.h can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/midi_driver/driver/cppThread-master/CppThread.h>. 

### TerminalController.cpp

TerminalController.cpp is a deprecated replacement for the planned hardware pedals which unfortunately could not be completed due to the closure of labs. This class has been merged with the controller class. It was last used in the change_song branch. This object can be found at <https://github.com/Nood24/MIDI-Real-Time/blob/master/frontEnd/hardwareController_Terminal_prototype/TerminalController.cpp>. The terminal controller was responsible for receiving inputs from the terminal, keeping track of system state and then updating the virtual hardware object which is passed to other parts of the system to make this information accessible. It is included in this wiki as it is a useful reference to understand the systems state machine. 

---

## Compiling 

### Simple How to Compile

To compile the project do the following.

1. Get yourself a machine running Linux. Eg Raspberry Pi or Ubuntu system.
1. Clone the project with git clone --recurse-submodules -j8 https://github.com/Nood24/MIDI-Real-Time.git
1. Install dependencies. They are listed in the project README and in .travis.yml <https://github.com/Nood24/MIDI-Real-Time/blob/master/README.md>.
1. cd into the build_and_run directory
1. run make
1. This will project a OneManCeilidh file. Run it with ./OneManCeilidh command and the system will start. 
1. If this fails it is most likely an issue with your environment. 

### Detailed How to Compile

The make file in the build_and_run directory is for user convenience. It makes calls in other files and copies the built executables into the buildAndRun directory. The project compiles using Qmake. Qmake is called on the project .pro file at MIDI-Real-Time/frontEnd/OMC_FrontEnd.pro. This produces a make file which can be run to compile the project. The OMC_FrontEnd.pro file contains all the programs that make up the project and the libraries that they depend upon. If a new file is created and you wish to integrate it into the project, you must add this file name to the .pro file so that it will compile and link. 

---

## Using the System

### Basic Opperation

Using the system is pretty straight forward. Running the system brings up a Qt display which shows left song, right song, current song and a play/pause button. 

Interact with this Qt display via the terminal in which you are running the system. Enter "1" to switch song left, "2" to switch song right and "3" to play/pause a song. 

When pausing a song the song will always continue to the end of the tune before ending. Text will become red when pause is pressed to show that a stop command has been queued. 

### Installing a New Song

Songs are installed as CSV files made up of a top-level directory with a song name and then sub directories of CSV files providing the notes of the different instruments. Add a song directory to the following directory /MIDI-Real-Time/midi_driver/driver/CSVFiles for the song to be automatically loaded into the system on startup following a fresh build of the system. 

---

## CI and Testing 

CI and Test tools are being used in this project to ensure that the latest version of the project is always in a releasable state. 

### CI

CI is managed using Travis https://travis-ci.com/. Travis automatically builds and runs the project release build and test build upon every commit to ensure that the project is always in good health. The Travis build setup is defined in /MIDI-Real-Time/.travis.yml.

### Tests

Unfortunately, the team has not been able to configure Travis to run tests with every commit. Because of this tests are run manually by developers. This is done by the following process: 

1. Open a terminal
1. cd into /MIDI-Real-Time/tests
1. run "qmake"
1. run "make"
1. run ./tests

The projects tests have been created using Catch2 https://github.com/catchorg/Catch2. The team has found this to be a very useful open source framework for producing tests. The project tests can be found at https://github.com/Nood24/MIDI-Real-Time/blob/master/tests/tests_main.cpp.


---
## Program Execution Event Guide

The project environment is set up in main.cpp this creates the highest level objects of the system and gets them running. The code snippet below shows main creating the front end window, creating a virtual hardware object, creating the backend controller and setting the controller running in a thread. 


```cpp
    MainWindow window;
    VirtualHardwareController *virtualHardware = new VirtualHardwareController();
    Controller *MidiController = new Controller(virtualHardware,&window);
    std::thread t1(&Controller::run, std::ref(MidiController));
```
Running the controller causes the songs to be installed and set in the front end. Once this has happened the system waits to receive inputs from the terminal, processes those inputs accordingly and then updates the front end to reflect the new system state.  

```cpp
void Controller::monitor_input(){
    int input;
    while(true){
        input = this->hardware->get_input();
        this->process_input(input);
        this->gui->set_songs(this->get_left_dance(),this->get_dance_name(),this->get_right_dance());
        this->gui->set_play_button(this->dance_playing);
    }
}

void Controller::run(){
    this->create_midi_reader(USB_PORT);
    this->find_installed_dances(INSTALL_PATH);
    this->load_dance(DEFAULT_DANCE);
    this->gui->set_songs(this->get_left_dance(),this->get_dance_name(),this->get_right_dance());
    this->gui->set_play_button(this->dance_playing);
    this->monitor_input();
}
```

If the input process determines a song had been started then start_stop dance is called. This starts the selected dance by starting the selected Danceset object.


```cpp
void Controller::start_stop_dance(){
    if(this->hardware->playing){
        this->hardware->set_state(false);
        this->gui->set_play_button(this->dance_playing, true);
        this->stop_playing();
    }
    else if (!this->dance_playing){
        this->hardware->set_state(true);
        thread t1(&start_current_dance, this);
        t1.detach();
    }
```
A dance is made up of multiple instruments playing their part of a song. The instruments change the notes that they are playing to support music being played on the accordion through a callback function setup in the controller class that works with RtMidi to be called each time a Midi input is recieved. This callback function sets the key in the dance class to which all instruments refer, allowing instruments to generate real time musical acompanyment.

```cpp
void callback( double deltatime, vector< unsigned char > *message, void *controller ){
    if (((Controller *)controller)->dance_playing){
        ((Controller *)controller)->current_dance->set_notes(message);
    }
    else{
        sendNote(((message->at(0)>> 4) & 1),0,message->at(1),127);
        ((Controller *)controller)->current_dance->set_notes(message);
    }
}
```
Finally when a song is set to pause the instruments will reach the end of a tune and then return setting the system into a song paused state.

---

## A Note on the Effects of Covid-19 on the Project.

Covid-19 caused the cancellation of the hardware foot peddles that were planned to be used to control the project. The system is controlled through the terminal and not through pedals because of this. If peddles became available they would replace the virtual hardware object that has been created to replace the foot pedals. (Code shown below). The main task here is replacing current get input function that gets an input from the terminal with code that gets an input from the foot pedals. A start had been made to this functionality 

The code for running the pedals has been written in https://github.com/Nood24/MIDI-Real-Time/blob/master/hardwareController/hardwareInterface.cpp. While this interface is not fully implemented it could provide a blueprint for the design of a class which gets inputs from the hardware.  

```cpp
#include "VirtualHardwareController.h"
#include <iostream>
using namespace std;

VirtualHardwareController::VirtualHardwareController(){
	this->playing = false;
}
    
int VirtualHardwareController::get_input(){
    int i;
    cout << "\nPlease enter an integer value between 1-4 for pedal press: ";
    cin >> i;
    return i;
}

void VirtualHardwareController::set_state(bool state){
    this->playing = state;
}

```

---

## Conclusion

The One Man Ceilidh team have had good fun working on this project and we hope you do too! If you have any questions feel free to drop us a message on twitter @OneManCeilidh https://twitter.com/OneManCeilidh.

Best Regards,

The One Man Ceilidh Team. 




