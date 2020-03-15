//
// Created by Cameron Bennett on 11/03/2020.
//

#ifndef CEILIDHBAND_CONTROLLER_H
#define CEILIDHBAND_CONTROLLER_H
#define CSV_FILES './CSVFiles/'

#include "DanceSet.h"

using namespace std;


class Controller {
public:
    Controller();
    static string get_file_location(string dance, int tempo);
    static bool playing;
    void load_dance(string dance_name);
    void start_playing();
private:

    DanceSet current_dance;
    string file_location;
};


#endif //CEILIDHBAND_CONTROLLER_H
