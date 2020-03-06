#include "HardwareController.h"
#include "hardwareInterface.h"
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <thread>

using namespace std;

int main(){

    //get song example
    cout << getSong();

    //get if song playing example
    if(!IsSongPlaying()){
    cout<< "\nSong not playing\n";
    }
    else{
        cout<< "\nSong playing\n";
    }
    
    //run hardware controller example
    //run();
    std::thread t1(runHardwareInterface);

    //Pause Till Complete
    t1.join();
}
