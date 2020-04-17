#include "VirtualHardwareController.h"
#include <iostream>
using namespace std;

VirtualHardwareController::VirtualHardwareController(){
    this->playing = false;
}

int VirtualHardwareController::get_input(){
    int i;
    cout << "\nPlease enter an integer value between 1-4 for pedal press: ";
    cin >> i;
    return i;
}

void VirtualHardwareController::set_state(bool state){
    this->playing = state;
}
