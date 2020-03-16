all:
	gcc -c -g -o fluidCustomAPI.o fluidCustomAPI.c `pkg-config fluidsynth --libs`
	g++ -c -g -o Controller.o Controller.cpp  `pkg-config fluidsynth --libs`
	g++ -c -g -o DanceSet.o DanceSet.cpp  `pkg-config fluidsynth --libs`
	g++ -c -g -o Instrument.o Instrument.cpp  `pkg-config fluidsynth --libs`
	g++ -Wall -D__LINUX_ALSA__ -o executible fluidCustomAPI.o Instrument.o Controller.o DanceSet.o `pkg-config fluidsynth --libs` ../../../rtmidi/RtMidi.cpp -lasound -lpthread
	rm *.o


