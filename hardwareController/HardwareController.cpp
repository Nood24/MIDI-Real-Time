//*****************************************//
//  
//  HardwareController.cpp
//  Class Interfacing with hardware and
//  maintaining system state
//
//*****************************************//
//
// Button 1 song left
// Button 2 song right
// Button 3 start/stop song
// Button 4 redundency 
//
//*****************************************//





#include "HardwareController.h"
#include <iostream>
using namespace std;

bool songPlaying = false;
char songs [4][30] = {"The Gay Gordons", "The Dashing White Sergeant", "Canadian Barn Dance","Highland Schottishe" }; 
int songIndex = 0;


int getInput(){
    int i;
    cout << "\nPlease enter an integer value between 1-4 for pedal press: ";
    cin >> i;
    return i;
}


void shiftSongLeft(){
    if (songIndex == 0){
        songIndex = (sizeof(songs)/sizeof(*songs))-1;
    }
    else{
        songIndex = songIndex - 1;
    }
    cout << "\nCurrent Song is " << songs[songIndex];
    return;
}


void processInput(int input){
    if(input == 1){
        shiftSongLeft();
    }
    else if(input == 2){

    }
    else if(input == 3){

    }
    else{
    
    }
}



void HardwareController::run(){
    while(true){
    int input = getInput();
    processInput(input);
    }

}
