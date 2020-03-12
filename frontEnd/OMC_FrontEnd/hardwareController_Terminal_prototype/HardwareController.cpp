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
#include <cstring>
#include <mutex>
#include <thread>
#include "../mainwindow.h"


//--------------------------------------------------

int HardwareController::getInput(){
    int i;
    cout << "\nPlease enter an integer value between 1-4 for pedal press: ";
    cin >> i;
    return i;
}

//--------------------------------------------------

void HardwareController::shiftSongLeft(){
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

void HardwareController::shiftSongRight(){
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

void HardwareController::startStopSong(){
    if(songPlaying){
        songPlaying = false;
    }
    else{
        songPlaying = true;
    }
}

//--------------------------------------------------

void HardwareController::printSystemState(){
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

void HardwareController::processInput(int input){
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

char * HardwareController:: getSong(){
    return songs[songIndex];
}

//--------------------------------------------------

bool HardwareController::IsSongPlaying(){
    return songPlaying;
}

//--------------------------------------------------
void HardwareController::runThread(MainWindow& window, HardwareController& controller){
     cout << "hello";
     window.setSongs("hello", "hello", "hello");
     std::thread t1(&HardwareController::run, &controller, std::ref(window));
     t1.detach();
}

//--------------------------------------------------
void HardwareController::run(MainWindow& window){
    songPlaying = false;
    this->songIndex = 0;
    printSystemState();
    int input; 
    while(true){
    input = getInput();
    processInput(input);
    window.setSongs(getSong(),getSong(),getSong());
    }

}
