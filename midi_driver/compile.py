#run and add parameter of file to compile and name of file to create. Eg. source.cpp executable 

import sys
import os

def getArgs():
    if (len(sys.argv) !=3):
        print "Incorrect number of parameters pass in program to compile and name of executable to create"
        exit(1)
    else:
        return sys.argv[1], sys.argv[2]

def compile(cppFile,executable):
    command = "g++ -Wall -D__Linux_ALSA__ -o " + executable + " " + cppFile + " ../rtmidi/RtMidi.cpp -lasound -lpthread"
    os.system(command)

cppFile, executable = getArgs()
compile(cppFile, executable)
