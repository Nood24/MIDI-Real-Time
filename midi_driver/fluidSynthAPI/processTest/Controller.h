//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef CEILIDHBAND_CONTROLLER_H
#define CEILIDHBAND_CONTROLLER_H
#define CSV_FILES './CSVFiles/'

#include "DanceSet.h"



class Controller {
public:
    Controller();
    const string
    static string get_file_location(string dance, int tempo);
    bool playing = false;
    void load_dance(string dance_name)
    void start_playing();
private:

    DanceSet current_dance;
    string file_location;
};


#endif //CEILIDHBAND_CONTROLLER_H
