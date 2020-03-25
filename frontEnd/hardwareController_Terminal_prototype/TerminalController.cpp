//*****************************************//
//  
//  TerminalController.cpp
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


#include "TerminalController.h"
#include <iostream>
using namespace std;
#include <cstring>
#include <mutex>
#include <thread>
#include "../mainwindow.h"


//--------------------------------------------------

int TerminalController::getInput(){
    int i;
    cout << "\nPlease enter an integer value between 1-4 for pedal press: ";
    cin >> i;
    return i;
}

//--------------------------------------------------

void TerminalController::shiftSongLeft(){
    this->mutex_songs.lock();
    this->mutex_songIndex.lock();
    if (this->songIndex == 0){
        this->songIndex = (sizeof(this->songs)/sizeof(*(this->songs)))-1;
    }
    else{
        this->songIndex = this->songIndex - 1;
    }
    this->mutex_songs.unlock();
    this->mutex_songIndex.unlock();
    return;
}

//--------------------------------------------------

void TerminalController::shiftSongRight(){
    mutex_songs.lock();
    mutex_songIndex.lock();
    if(songIndex == (sizeof(songs)/sizeof(*songs))-1){
        songIndex = 0;
    }
    else{
        songIndex = songIndex + 1;
    }
    mutex_songs.unlock();
    mutex_songIndex.unlock();
    return;
}

//--------------------------------------------------

void TerminalController::startStopSong(){
    if(songPlaying){
        songPlaying = false;

    }
    else{
        songPlaying = true;
    }
}

//--------------------------------------------------

void TerminalController::printSystemState(){
    mutex_songs.lock();
    mutex_songIndex.lock();
    mutex_songPlaying.lock();
    cout << "\nCurrent Song is " << songs[songIndex];
    if(songPlaying){
        cout << "\nA song is currently playing\n---------------\n";
    }
    else{
        cout << "\nNo song is currently playing\n---------------\n";
    }
    mutex_songs.unlock();
    mutex_songIndex.unlock();
    mutex_songPlaying.unlock();
      
}

//--------------------------------------------------

void TerminalController::processInput(int input){
    mutex_songPlaying.lock();
    if(input == 1 && !songPlaying){
        shiftSongLeft();
    }
    else if(input == 1 && songPlaying){
        cout << "\nSong must be off to switch song!\n";
    }
    else if(input == 2 && !songPlaying){
        shiftSongRight();
    }
    else if(input == 2 && songPlaying){
        cout << "\nSong must be off to switch song!\n";
    }
    else if(input == 3){
        startStopSong();
    }
    else if(input == 4){
        cout << "\nButton 4 is placeholder\n";
    }
    else{
        cout << "\nInvalid Input\n";
    }
    mutex_songPlaying.unlock();
    printSystemState();
}

//--------------------------------------------------

char * TerminalController:: getSong(){
    return songs[songIndex];
}
//--------------------------------------------------

char * TerminalController::getLeftSong(){
    mutex_songs.lock();
    mutex_songIndex.lock();
    int temp = this->songIndex;
    if (temp == 0){
        temp = (sizeof(this->songs)/sizeof(*(this->songs)))-1;
    }
    else{
        temp = this->songIndex - 1;
    }
    mutex_songs.unlock();
    mutex_songIndex.unlock();
    return songs[temp];
}
//--------------------------------------------------

char * TerminalController:: getRightSong(){
    mutex_songs.lock();
    mutex_songIndex.lock();
    int temp = this->songIndex;
    if(temp == (sizeof(songs)/sizeof(*songs))-1){
        temp = 0;
    }
    else{
        temp = songIndex + 1;
    }
    mutex_songs.unlock();
    mutex_songIndex.unlock();
    return songs[temp];
}

//--------------------------------------------------

bool TerminalController::IsSongPlaying(){
    return songPlaying;
}

//--------------------------------------------------

void TerminalController::runThread(MainWindow& window, TerminalController& controller,VirtualHardwareController& virtualController){
     cout << "hello";
     std::thread t1(&TerminalController::run, &controller, std::ref(window),std::ref(virtualController) );
     t1.detach();
}

//--------------------------------------------------
void TerminalController::run(MainWindow& window,VirtualHardwareController& virtualController){
    songPlaying = true;
    virtualController.playing = this->songPlaying;
    this->songIndex = 0;
    printSystemState();
    int input; 
    window.setSongs(getLeftSong(),getSong(),getRightSong());
    window.setPlayButton(songPlaying);
    while(true){
        input = getInput();
        processInput(input);
        window.setSongs(getLeftSong(),getSong(),getRightSong());
        window.setPlayButton(songPlaying);
        virtualController.playing = this->songPlaying;
        cout << virtualController.playing <<" controller in TerminalCon \n";
    }

}
