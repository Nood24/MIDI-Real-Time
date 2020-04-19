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
#include <cstring>
#include <mutex>
#include <thread>
#include "hardwareInterface.h"
#include <pthread.h>
using namespace std;

//-------------------------------------------------

std::mutex mutex_songPlaying;
std::mutex mutex_songs;
std::mutex mutex_songIndex;

//-------------------------------------------------

bool songPlaying = false;
char songs [4][30] = {"The Gay Gordons", "The Dashing White Sergeant", "Canadian Barn Dance","Highland Schottishe" }; 
int songIndex = 0;

//--------------------------------------------------

int getInput(){
    int i;
    i = getState();
    return i;
}

//--------------------------------------------------

void shiftSongLeft(){
    mutex_songs.lock();
    mutex_songIndex.lock();
    if (songIndex == 0){
        songIndex = (sizeof(songs)/sizeof(*songs))-1;
    }
    else{
        songIndex = songIndex - 1;
    }
    mutex_songs.unlock();
    mutex_songIndex.unlock();
    return;
}

//--------------------------------------------------

void shiftSongRight(){
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

void startStopSong(){
    if(songPlaying){
        songPlaying = false;
    }
    else{
        songPlaying = true;
    }
}

//--------------------------------------------------

void printSystemState(){
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

void processInput(int input){
    mutex_songPlaying.lock();
    if (input == 0){
		//No change in state
		return;
	}
   else if(input == 1 && !songPlaying){
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
        cout << "\nInvalid Input\n" << input;
    }
    mutex_songPlaying.unlock();
    printSystemState();
}


//--------------------------------------------------

char * getSong(){
    return songs[songIndex];
}

//--------------------------------------------------

bool IsSongPlaying(){
    return songPlaying;
}

//--------------------------------------------------

/*
void run(){
    std::thread t1(runHardwareInterface);
    printSystemState();
    while(true){
    int input = getInput();
    processInput(input);
    }

}
*/
