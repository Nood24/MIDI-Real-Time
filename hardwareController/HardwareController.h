//*****************************************//
//  
//  HardwareController.h
//  Class Interfacing with hardware and
//  maintaining system state
//
//*****************************************//
#include <string>

class HardwareController{

  public:
    void run();
    bool IsSongPlaying();
    char * getSong();

};
 


