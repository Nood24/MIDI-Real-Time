all:
	gcc -c -o fluidCustomAPI.o fluidCustomAPI.c `pkg-config fluidsynth --libs`
	g++ -c -o process.o process.cpp `pkg-config fluidsynth --libs`
	g++ -c -o MidiInDummy.o cmidiin.cpp 
	g++ -Wall -D__LINUX_ALSA__ -o executible fluidCustomAPI.o process.o MidiInDummy.o `pkg-config fluidsynth --libs` ../../../rtmidi/RtMidi.cpp -lasound -lpthread
	rm *.o

