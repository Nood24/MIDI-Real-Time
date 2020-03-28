#//
// Created by Cameron Bennett on 11/03/2020.
//
#include "../../rtmidi/RtMidi.h"
#include "Controller.h"
#define DEFAULT_DANCE "gaygordons"
#define DEFAULT_TEMPO 210

void Controller::load_dance(string dance_name, int tempo){
    file_location = CSV_FILES + dance_name + "/";
    current_dance = new DanceSet(dance_name, tempo, file_location, this->hardware);
    current_dance->load_instruments();
}

void Controller::start_playing(VirtualHardwareController& vhc){
    this->current_dance->start_dance(vhc);

}

void Controller::stop_playing(){
    //this->hardware.playing = false;
    current_dance->wait_loop_end();
    //midiin->setCallback( &replicate_midi );
}

void Controller::set_playing(bool play){
    this->hardware.playing = play;
}

void change_notes( double deltatime, vector< unsigned char > *message, Controller *controller ){
    //controller->hardware.playing = true;
    controller->current_dance->set_notes(message);
}


void callback( double deltatime, vector< unsigned char > *message, void *controller ){
    //cout<<"in callback"<<endl;
    if (((Controller *)controller)->hardware.playing){
        ((Controller *)controller)->current_dance->set_notes(message);
    }
    else{
        sendNote(((message->at(0)>> 4) & 1),0,message->at(1));
    }
}

/*
void callback( double deltatime, std::vector< unsigned char > *message, void *){
    DanceSet::set_notes(message);
}
*/

void Controller::create_midi_reader(int port_no){
    midiin = 0;
    RtMidiOut *midiout = new RtMidiOut();

    try {
        // RtMidiIn constructor
        midiin = new RtMidiIn();

        // Call function to select port.
        midiin->openPort( port_no);

        midiin->setCallback( &callback, (void *)this ); //&mycallback

        // Don't ignore sysex, timing, or active sensing messages.
        midiin->ignoreTypes( false, false, false );

    } catch ( RtMidiError &error ) {
        error.printMessage();
    }
}
/*
int main(){

int main(){
    HardwareController hwtest;
    Controller controller = Controller(hwtest);
    //Set create_midi_reader(1)on pi
    controller.create_midi_reader(1);
    char c;
    cin.get(c);
    
    
    controller.load_dance("gaygordons", 175);
    cout<<"finished loading\n";
    controller.start_playing();
    
}
*/
