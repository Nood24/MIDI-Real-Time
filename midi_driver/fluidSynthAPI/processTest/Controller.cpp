//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Controller.h"
#define DEFAULT_DANCE "gaygordons"
#define DEFAULT_TEMPO 210

void Controller::load_dance(string dance_name, int tempo){
    file_location = CSV_FILES + dance_name + "/";
    DanceSet dance = DanceSet(dance_name, tempo, file_location, hardware);
    current_dance = &dance;
    current_dance->load_instruments();
}

void Controller::start_playing(){
    //stop rtmidi out
    //while (not playing){};
    hardware.playing = true;
    current_dance->start_dance();
}

void Controller::stop_playing(){
    hardware.playing = false;
    current_dance->wait_loop_end();
    //midiin->setCallback( &replicate_midi );
}

void Controller::set_playing(bool play){
    hardware.playing = play;
}

void change_notes( double deltatime, vector< unsigned char > *message, Controller *controller ){
    controller->hardware.playing = true;
    controller->current_dance->set_notes(message);
}

void callback( double deltatime, vector< unsigned char > *message, void *controller ){
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
    fluid_synth_init();
    midiin = 0;

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

int main(){
    HardwareController hwtest;
    Controller controller = Controller(hwtest);
    controller.create_midi_reader(1);
    controller.load_dance("gaygordons", 120);
    controller.start_playing();

}
