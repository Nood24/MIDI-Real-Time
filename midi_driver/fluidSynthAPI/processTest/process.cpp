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
bool bassOn=0;
bool chordOn=0;
int previousBass;
int previousChord[3] = {60,64,67};
int chordNotes[3] = {60,64,67}; //CHANGE
int chordIdx = 0;
int bassNote = 48; //CHANGE

bool isKthBitSet(int n, int k) 
{ 
    return ((n >> (k - 1)) & 1);
}

void setChordNote(int note){
    //readWrite.lock();
    previousChord[chordIdx] = chordNotes[chordIdx];
    chordNotes[chordIdx] = note;
    chordIdx = (chordIdx+1)%3;
    //readWrite.unlock();
}

int getChordNotes(){
    //readWrite.lock();
    return 1;
    //TO DO
}

bool equalList(int *list1, int *list2){
	return ((list1[0] == list2[0]) && (list1[1] == list2[1]) && (list1[2] == list2[2]));
}
int byte1;
int byte2;
unsigned int nBytes;
bool is_bass;
//bool is_set;


 
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

void updateNote(int channel){
   if (bassOn){
	sendNote(0,channel,previousBass);
	sendNote(1,channel,bassNote);
   }
   if (chordOn){
	sendNote(0,channel,previousChord[0]);
	sendNote(0,channel,previousChord[1]);
	sendNote(0,channel,previousChord[2]);
	sendNote(1,channel,chordNotes[0]);
	sendNote(1,channel,chordNotes[1]);
	sendNote(1,channel,chordNotes[2]);
   }
}
int tempo = 650;
void Loop(vector<int> &timeDeltas, vector<int> &channels, vector<int> &onOff){
	int d = 0;
	int size = timeDeltas.size();
	while(1){
		usleep(tempo*timeDeltas[d%size]);
		//cout << "just waited"<<timeDeltas[d%size]<<"\n";
		if (channels[d%size]==2){
			sendNote(onOff[d%size],0,bassNote);
			bassOn = onOff[d%size];
		}
		else{
			sendNote(onOff[d%size],0,chordNotes[0]);
			sendNote(onOff[d%size],0,chordNotes[1]);
			sendNote(onOff[d%size],0,chordNotes[2]);
			chordOn = onOff[d%size];
		}
		d=d+1;
		//cout << "chord notes are currently " << chordNotes[0] << chordNotes[1] << chordNotes[2] << "\n";
	}
}

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
    if (is_bass){
	previousBass = bassNote;
	bassNote = byte2;
    }
    else{
	setChordNote(byte2);
    }
    if (previousBass!=bassNote || !equalList(previousChord,chordNotes)){
    	updateNote(0);
	cout<<"It's worked\n";
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
    string testfile = "../../Piano.csv";
    vector<int> timeDeltas, channels, onOff;
    loadCSVToArray(testfile,timeDeltas,channels,onOff);
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
    check = pthread_create(&threads[0], NULL, Loop, (void *) &Piano);
    */

}

