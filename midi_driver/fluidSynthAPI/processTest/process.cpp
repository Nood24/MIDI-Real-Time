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
#include <bitset>

using namespace std;

std::vector<unsigned char>* message;


bool isKthBitSet(int n, int k) 
{ 
    if ((n >> (k - 1)) & 1) 
        return true;
    else
        return false; 
} 
 

void setMessage(std::vector<unsigned char>* newMessage){
 message = newMessage;
 unsigned int nBytes = message->size();
 int byte1 =  message->at(0);
 int byte2 = message->at(1);
 int byte3 = message->at(2);
 char result = byte1 && 00010000;

 bool is_set = isKthBitSet(byte1,5);



//std::cout << res;
if( is_set){
 printf("true\n");
}
else{
 printf("false\n");
}

 //printf("Number of bytes %d Printing MIDI Message %d %d %d \n",nBytes, byte1,byte2,byte3);
 fluid_synth_init();

 noteOn(0,60);
  
 
}

void printMessage(){
  cout << "Hello World!\n";
  
}
