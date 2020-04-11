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
    void runThread(MainWindow& window, TerminalController& controller,VirtualHardwareController* virtualController);

private:
    void processInput(int input);
    void printSystemState();
    void startStopSong();
    void shiftSongRight();
    void shiftSongLeft();
    int getInput();
    void run(MainWindow& window,VirtualHardwareController* virtualController);
    char * getSong();
    char * getLeftSong();
    char * getRightSong();

    bool songPlaying;
    std::vector<std::vector<std::string>> songs{{"The Gay \nGordons", "gaygordons"},{"The Dashing White \nSergeant", "gaygordons"},{"Canadian \nBarn Dance", "gaygordons"},{"Highland \nSchottishe", "gaygordons"}};
    int songIndex;
    VirtualHardwareController* virtualController;

    std::mutex mutex_songPlaying;
    std::mutex mutex_songs;
    std::mutex mutex_songIndex;

};


