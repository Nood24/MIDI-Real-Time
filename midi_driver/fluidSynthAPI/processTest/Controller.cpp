//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Controller.h"

Controller::Controller(){}

void Controller::load_dance(string dance_name, int tempo){
    file_location = CSV_FILES + dance_name + '/';
    current_dance = DanceSet(dance_name, tempo, file_location);
    current_dance.load_instruments();
}

void Controller::start_playing(){
    playing = True;
    current_dance.start_dance();
}

void Controller::stop_playing(){
    playing = false;
}