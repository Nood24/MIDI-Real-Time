# One Man Ceiidh

A University of Glasgow ENG5220: Real Time Embedded Programming (2019-20) project that aims to allow a single accordion player to perform a full ceilidh solo by generating the backing music in real time as they play.
 
The system is made up of a Rasperry Pi 3B+ with a normal monitor and keyboard. The keyboard and monitor allow the the system to be controlled the pi provides the procesing of the accordion MIDI signal into an AUX output of a full ceilidh band. An overview of the system software is shown in the UML at the bottom of this README.

You can get up this system on a Raspberry Pi or Ubuntu computer. A list of project dependancies is kept at the bottom of this README which aims to help you set up you're environment and get started. 

![One Man Ceilidh Front End](/other/images/Screenshot%20from%202020-04-15%2009-17-10.png)

Please check out or wiki page for a detailed overview of the project or help getting started. https://nood24.github.io/MIDI-Real-Time/?fbclid=IwAR27X-9Kugiw643k3CEA-yfcTT6ZXq6-MGSo7AEuBK4x8Z-nUWYBc6VSuKA

If you have any questions please feel free to message us via twitter @OneManCeilidh https://twitter.com/OneManCeilidh.

---

## Authors:

*  Neil Wood: neilwood1997@gmail.com	
  *  Toolset, front end, fluidsynth, RtMidi, Testing and CI. 
*   Cameron Bennett:Cameron.b97.cb@gmail.com
  * Backend, processing MIDI, creating dances and playing songs.
*  Seun Ajijola: sajijola@gmail.com
  *  Hardware.

Project Twitter: https://twitter.com/OneManCeilidh

Project Wiki Page: https://nood24.github.io/MIDI-Real-Time/?fbclid=IwAR27X-9Kugiw643k3CEA-yfcTT6ZXq6-MGSo7AEuBK4x8Z-nUWYBc6VSuKA


 ---
 
## One Man Ceilidh UML Diagram: Shows the system's software architecture. 
 
 ![One Man Ceilidh UML](/other/images/UML.png)
 
 ---

## Project Dependancies:

RTMidi Dependancies:

* sudo apt-get install libtool
* sudo apt-get install automake
* sudo apt-get install autoconf

FluidSynth Dependancies:

* sudo apt-get install libasound2-dev : Allows RTMIDI to interact with ALSA.
* sudo apt-get install fluidsynth : Synth MIDI into analogue output.
* sudo apt-get install libfluidsynth-dev: Allows use of fluidsynth API.

Other Dependancies:

* Qt 5, Qmake: Support front end and build the project. 
 
