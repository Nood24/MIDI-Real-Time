all:
	gcc -c -o fluidCustomAPI.o fluidCustomAPI.c `pkg-config fluidsynth --libs`
	g++ -c -o APIUseExample.o APIUseExample.cpp `pkg-config fluidsynth --libs`
	g++ -o test2 fluidCustomAPI.o APIUseExample.o `pkg-config fluidsynth --libs`

