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

class HardwareController
{

public:
    bool IsSongPlaying();
    char * getSong();
    void runThread(MainWindow& window, HardwareController& controller);

private:
    void processInput(int input);
    void printSystemState();
    void startStopSong();
    void shiftSongRight();
    void shiftSongLeft();
    int getInput();
    void run();
    
    bool songPlaying;
    char songs [4][30] = {"The Gay Gordons", "The Dashing White Sergeant", "Canadian Barn Dance","Highland Schottishe"};  
    int songIndex;

    std::mutex mutex_songPlaying;
    std::mutex mutex_songs;
    std::mutex mutex_songIndex;

};


