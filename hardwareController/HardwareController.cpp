//*****************************************//
//  
//  HardwareController.cpp
//  Class Interfacing with hardware and
//  maintaining system state
//
//*****************************************//
#include "HardwareController.h"
#include <iostream>
using namespace std;

bool songPlaying = false;
char songs [4][30] = {"The Gay Gordons", "The Dashing White Sergeant", "Canadian Barn Dance","Highland Schottishe" }; 



int getInput(){
    int i;
    cout << "Please enter an integer value between 1-4 for pedal press: ";
    cin >> i;
    cout << "The value you entered is " << i << "\n";
    return i;
}



void HardwareController::run(){
    while(true){
    int input = getInput();
    }

}
