//
// Created by Cameron Bennett on 11/03/2020.
//

#include "Controller.h"
#define DEFAULT_DANCE "gaygordons"
#define DEFAULT_TEMPO 210

void Controller::load_dance(string dance_name, int tempo){
    file_location = CSV_FILES + dance_name + "/";
    DanceSet dance = DanceSet(dance_name, tempo, file_location, this);
    current_dance = &dance;
    dance.load_instruments();
}

void Controller::start_playing(){
    //stop rtmidi out
    midiin->setCallback( &change_notes, this );
    while (not playing){};
    current_dance->start_dance();
}

void Controller::stop_playing(){
    playing = false;
    current_dance->wait_loop_end();
    midiin->setCallback( &replicate_midi );
}

void Controller::set_playing(bool play){
    playing = play;
}

static void change_notes( double deltatime, std::vector< unsigned char > *message, Controller *controller ){
    controller.playing = true;
    controller.current_dance->set_notes(message);
}

static void replicate_midi( double deltatime, std::vector< unsigned char > *message, void */*userData*/ ){
    sendNote(((message->at(0)>> 4) & 1),0,message->at(1));
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
        midiin->openPort( port_no );

        midiin->setCallback( &replicate_midi ); //&mycallback

        // Don't ignore sysex, timing, or active sensing messages.
        midiin->ignoreTypes( false, false, false );

    } catch ( RtMidiError &error ) {
        error.printMessage();
    }
}

int main(){
    Controller controller = Controller();
    controller.create_midi_reader(1);
    controller.load_dance("gaygordons", 120);
    controller.start_playing();

}
