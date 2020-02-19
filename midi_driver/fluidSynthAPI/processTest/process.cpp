#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "fluidCustomAPI.h"
#include <stdlib.h>
#include <stdio.h>
#include <fluidsynth.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <iostream>


using namespace std;

std::vector<unsigned char>* message;

void setMessage(std::vector<unsigned char>* newMessage){
 message = newMessage;
 unsigned int nBytes = message->size();
 int byte1 =  message->at(0);
 int byte2 = message->at(1);
 int byte3 = message->at(2);
 printf("Printing MIDI Message %d %d %d \n", byte1,byte2,byte3);
 fluid_synth_init();
 noteOn(0,60);
  
 
}

void printMessage(){
  cout << "Hello World!\n";
  
}
