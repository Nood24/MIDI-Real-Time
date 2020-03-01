#include "HardwareController.h"
#include <iostream>
#include <unistd.h>
using namespace std;


HardwareController controller1;

int main(){

    //get song example
    cout << controller1.getSong();

    //get if song playing example
    if(!controller1.IsSongPlaying()){
    cout<< "\nSong not playing\n";
    }
    else{
        cout<< "\nSong playing\n";
    }
    
    //run hardware controller example
    controller1.run();
}
