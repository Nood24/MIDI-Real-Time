//*****************************************//
//  
//  
//  process.cpp
//    
//
//*****************************************//



#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "fluidCustomAPI.h"
#include <stdlib.h>
#include <stdio.h>
#include <fluidsynth.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <mutex>
#include <shared_mutex>
#include <fstream>
#include <vector>
#include "CSVParse.h"
#include <pthread.h>
#include <unistd.h>

using namespace std;

std::vector<unsigned char>* message;

mutex readWrite;

int chordNotes[3] = {60,64,67}; //CHANGE
int chordIdx = 0;
int bassNote = 48; //CHANGE

bool isKthBitSet(int n, int k) 
{ 
    if ((n >> (k - 1)) & 1) 
        return true;
    else
        return false; 
} 


void setChordNote(int note){
    //readWrite.lock();
    chordNotes[chordIdx] = note;
    chordIdx = (chordIdx+1)%3;
    //readWrite.unlock();
}

int getChordNotes(){
    //readWrite.lock();
    return 1;
    //TO DO
}
int byte1;
int byte2;
unsigned int nBytes;
bool is_bass;
//bool is_set;

void setMessage(std::vector<unsigned char>* newMessage){
    message = newMessage;
    nBytes = message->size();
    //b1 channel on/off, b2 note, b3 velocity
    byte1 =  message->at(0);
    byte2 = message->at(1);
    //int byte3 = message->at(2);
    //char result = byte1 && 00010000;

    //is_set = isKthBitSet(byte1,5);

    is_bass = isKthBitSet(byte1,2);


    //std::cout << res;
    if (is_bass)
	bassNote = byte2;
    else{
	setChordNote(byte2);
    }
 }

 //printf("Number of bytes %d Printing MIDI Message %d %d %d \n",nBytes, byte1,byte2,byte3)
/*
void printMessage(){
  cout << "Hello World!\n";  
}
*/
struct Instrument {
    vector<int> timeDeltas;
    vector<int> channels;
    vector<int> onOff;
};


void loadCSVToArray(string &filename, vector<int> &timeDeltas, vector<int> &channels, vector<int> &onOff){
    ifstream csvfile;
    csvfile.open(filename);

    if (!csvfile.is_open())
        cout << "Error opening"<<filename<<"\n";

    int delta, channel, on;
    string strdelta, strchannel, stron;
    int line = 0;

    while(csvfile.good()){
        getline(csvfile,strdelta,',');
        getline(csvfile,strchannel,',');
        getline(csvfile,stron,'\n');

        delta = stoi(strdelta);
        channel = stoi(strchannel);
        on = stoi(stron);

        timeDeltas.push_back(delta);
        channels.push_back(channel);
        onOff.push_back(on);
    }
}
void sendNote(bool on, int channel, int note){
	if (on)
		noteOn(channel,note);
	else
		noteOff(channel,note);
}
int tempo = 650;
void Loop(vector<int> &timeDeltas, vector<int> &channels, vector<int> &onOff){
	int d = 0;
	int size = timeDeltas.size();
	while(1){
		usleep(tempo*timeDeltas[d%size]);
		//cout << "just waited"<<timeDeltas[d%size]<<"\n";
		if (channels[d%size]==2)
			sendNote(onOff[d%size],0,bassNote);
		else{
			sendNote(onOff[d%size],0,chordNotes[0]);
			sendNote(onOff[d%size],0,chordNotes[1]);
			sendNote(onOff[d%size],0,chordNotes[2]);
		}
		d=d+1;
		//cout << "chord notes are currently " << chordNotes[0] << chordNotes[1] << chordNotes[2] << "\n";
	}
}

/*
void *Play(void *instrument){

    struct Instrument *data = (struct Instrument*)instrument;
    int d = 0;
    int size =(*data).timeDeltas.size();
    cout << size;
    while(1){
	//int rand = (*data).timeDeltas[0];
        //cout << (*data).timeDeltas[d%size] << "\t" << (*data).channels[d%size] << "\t" << (*data).onOff[d%size] << "\n";
        d++;
        //wait timeDeltas*tempo seconds
        //check current chord and bass
        //send midi stuff
    }
    pthread_exit(NULL);
}
*/

void run(){
    printf("in run");
    string testfile = "../../Piano.csv";
    vector<int> timeDeltas, channels, onOff;
    cout<<"About to load arrays";
    loadCSVToArray(testfile,timeDeltas,channels,onOff);
    cout<<"loaded arrays";
    fluid_synth_init();
    Loop(timeDeltas,channels,onOff);
    /*
    struct Instrument Piano;
    Piano.timeDeltas = timeDeltas;
    Piano.channels = channels;
    Piano.onOff = onOff;

    int size = onOff.size();
    int check;
    cout << "About to do threads..";
    pthread_t threads[2];
    check = pthread_create(&threads[0], NULL, Play, (void *) &Piano);
    */

}

