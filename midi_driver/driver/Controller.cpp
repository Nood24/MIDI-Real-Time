#//
// Created by Cameron Bennett on 11/03/2020.
//
#include "../../rtmidi/RtMidi.h"
#include "Controller.h"


//MOVE TO PARAMETERS.H FILE
#define DEFAULT_DANCE "gaygordons"
#define DEFAULT_TEMPO 175
#define INSTALL_PATH "./CSVFiles/"
#define USB_PORT 1

void Controller::load_dance(string dance_name, int tempo){
    file_location = CSV_FILES + dance_name + "/";
    current_dance = new DanceSet(dance_name, tempo, file_location, this->hardware);
    current_dance->load_instruments();
}

void Controller::free_current_dance(){
    current_dance->free_instruments();
    delete current_dance;
}

void Controller::start_playing(){
    this->dance_playing = true;
    this->current_dance->start_dance();
}

void Controller::stop_playing(){
    current_dance->wait_loop_end();
    this->dance_playing = false;
}

void Controller::set_playing(bool play){
    this->hardware->playing = play;
}

void change_notes( double deltatime, vector< unsigned char > *message, Controller *controller ){
    //controller->hardware.playing = true;
    controller->current_dance->set_notes(message);
}


void callback( double deltatime, vector< unsigned char > *message, void *controller ){
    //cout<<"in callback"<<endl;
    if (((Controller *)controller)->hardware->playing){
        ((Controller *)controller)->current_dance->set_notes(message);
    }
    else{
        sendNote(((message->at(0)>> 4) & 1),0,message->at(1),90);
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

void Controller::find_installed_dances(const char* path){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
            if (ent->d_name[0]=='.'){
                continue;
            }
            string dir_name(ent->d_name);
            this->installed_dances.push_back(dir_name);
      }
      closedir (dir);
    }
}

void Controller::shift_dance_left(){
    if (this->dance_playing){
        cout << "\nSong must be finished to switch dance.\n";
        return;
    }
    if (this->dance_index == 0){
        this->dance_index = this->installed_dances.size()-1; //NEED A DIVIDE HERE?
    }
    else{
        this->dance_index = this->dance_index - 1;
    }
    this->free_current_dance();
    this->load_dance(this->installed_dances[this->dance_index], DEFAULT_TEMPO);
}

//--------------------------------------------------

void Controller::shift_dance_right(){
    if (this->dance_playing){
        cout << "\nSong must be finished to switch dance.\n";
        return;
    }
    if(this->dance_index == this->installed_dances.size()-1){
        this->dance_index = 0;
    }
    else{
        this->dance_index = this->dance_index + 1;
    }
    this->free_current_dance();
    load_dance(this->installed_dances[this->dance_index], DEFAULT_TEMPO);
}

void Controller::start_current_dance(Controller* controller){
    controller->start_playing();
}

void Controller::start_stop_dance(){
    if(this->hardware->playing){
        this->hardware->set_state(false);
        this->gui->set_play_button(this->dance_playing, true);
        this->stop_playing();
    }
    else if (!this->dance_playing){
        this->hardware->set_state(true);
        thread t1(&start_current_dance, this);
        t1.detach();
    }
    else{
        cout<< "\n\nPlease wait the song is not yet ready to start. This may take a few seconds\n";
    }
}

//--------------------------------------------------

void Controller::printSystemState(){
    cout << "\nCurrent Song is " << this->installed_dances[this->dance_index];
    if(this->dance_playing){
        cout << "\nA song is currently playing\n---------------\n";
    }
    else{
        cout << "\nNo song is currently playing\n---------------\n";
    }
      
}

void Controller::process_input(int input){
    switch(input){
        case 1:
            this->shift_dance_left();
            break;
        case 2:
            this->shift_dance_right();
            break;
        case 3:
            this->start_stop_dance();
            break;
        default:
            cout << "\nInvalid Input\n";
    }
    this->printSystemState();
}

string Controller::get_right_dance(){
    int right_idx = (this->dance_index + 1) % this->installed_dances.size();
    return this->installed_dances[right_idx];
}

string Controller::get_left_dance(){
    int left_idx = this->dance_index - 1;
    if (this->dance_index == 0)
        left_idx = this->installed_dances.size()-1;
    cout << "IDX:"<<left_idx <<endl;
    cout << this->installed_dances[left_idx] << endl;
    return this->installed_dances[left_idx];
}

string Controller::get_dance_name(){
    return this->installed_dances[this->dance_index];
}

void Controller::monitor_input(){
    int input;
    cout<<"monitoring..."<<endl;
    while(true){
        input = this->hardware->get_input();
        this->process_input(input);
        this->gui->set_songs(this->get_left_dance(),this->get_dance_name(),this->get_right_dance());
        this->gui->set_play_button(this->dance_playing);
    }
}

void Controller::run(){
    this->create_midi_reader(USB_PORT);
    this->find_installed_dances(INSTALL_PATH);
    //raise error if not loaded properly
    cout << this->installed_dances[0]<<" and "<<this->installed_dances[1]<<endl;
    this->load_dance(DEFAULT_DANCE, DEFAULT_TEMPO);
    this->gui->set_songs(this->get_left_dance(),this->get_dance_name(),this->get_right_dance());
    this->gui->set_play_button(this->dance_playing);
    this->monitor_input();
}
    
        
    //while true
    //observe current state and if changes then free and load dance
/*
int main(){

int main(){
    HardwareController hwtest;
    Controller controller = Controller(hwtest);
    //Set create_midi_reader(1)on pi
    controller.create_midi_reader(1);
    char c;
    cin.get(c);
    
    
    controller.load_dance("gaygordons", 190);
    cout<<"finished loading\n";
    while true:
    *   if 
    controller.start_playing();
    
}
*/
