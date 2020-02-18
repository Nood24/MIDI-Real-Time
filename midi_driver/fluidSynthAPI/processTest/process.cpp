#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "fluidCustomAPI.h"
using namespace std;

std::vector<unsigned char>* message;

void setMessage(std::vector<unsigned char>* newMessage){
 message = newMessage;
  cout << "Message Recieved!\n";
 
}

void printMessage(){
  cout << "Hello World!\n";
}
