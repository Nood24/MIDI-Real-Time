#include "HardwareController.h"
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <thread>

using namespace std;

int main(){
    HardwareController controller;
    //get song example
    cout << controller.getSong();

    //get if song playing example
    if(!controller.IsSongPlaying()){
    cout<< "\nSong not playing\n";
    }
    else{
        cout<< "\nSong playing\n";
    }

    controller.runThread();

}
