//*****************************************//
//  
//  HardwareController.h
//  Class Interfacing with hardware and
//  maintaining system state
//
//*****************************************// 
#include <string>
#include <mutex>
#include "../mainwindow.h"

#ifndef PLAYING_VAR
#define PLAYING_VAR
#include "../../midi_driver/driver/VirtualHardwareController.h"
#endif



class TerminalController
{

public:
    bool IsSongPlaying();
    void runThread(MainWindow& window, TerminalController& controller,VirtualHardwareController& virtualController);

private:
    void processInput(int input);
    void printSystemState();
    void startStopSong();
    void shiftSongRight();
    void shiftSongLeft();
    int getInput();
    void run(MainWindow& window,VirtualHardwareController& virtualController);
    char * getSong();
    char * getLeftSong();
    char * getRightSong();

    bool songPlaying;
    char songs [4][30] = {"The Gay \nGordons", "The Dashing White \nSergeant", "Canadian \nBarn Dance","Highland \nSchottishe"};
    int songIndex;

    std::mutex mutex_songPlaying;
    std::mutex mutex_songs;
    std::mutex mutex_songIndex;

};


