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

using namespace std;

std::vector<unsigned char>* message;

mutex readWrite;

int chordNotes[3];
int chordIdx = 0;
int bassNote;

bool isKthBitSet(int n, int k) 
{ 
    if ((n >> (k - 1)) & 1) 
        return true;
    else
        return false; 
} 


void setChordNote(int note){
    readWrite.lock();
    chordNotes[chordIdx] = note;
    chordIdx = (chordIdx+1)%3;
}

int getChordNotes(){
    readWrite.lock();
    return 1;
    //TO DO
}
void setMessage(std::vector<unsigned char>* newMessage){
    message = newMessage;
    unsigned int nBytes = message->size();

    //b1 channel on/off, b2 note, b3 velocity
    int byte1 =  message->at(0);
    int byte2 = message->at(1);
    int byte3 = message->at(2);
    char result = byte1 && 00010000;

    bool is_set = isKthBitSet(byte1,5);

    bool is_bass = isKthBitSet(byte1,2);


    //std::cout << res;
    if( is_set){
	if (is_bass)
		bassNote = byte2;
	else
		setChordNote(byte2);
        noteOn(0,byte2);
        printf("true\n");
    }
    else{
        noteOff(0,byte2);
        printf("false\n");
    }
    if (is_bass){
        printf("Bass ON\n");
    }

 //printf("Number of bytes %d Printing MIDI Message %d %d %d \n",nBytes, byte1,byte2,byte3);


  
 
}

void printMessage(){
  cout << "Hello World!\n";
  
}

struct Instrument {
    vector<int> *timeDeltas;
    vector<int> *channels;
    vector<int> *onOff;
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

void *Play(void *instrument){

    struct Instrument *data = (struct Instrument*)instrument;
    int i = 0;
    int size = (*(*data).timeDeltas).size();
    while(i<800){
        cout << (*(*data).timeDeltas)[i%size] << "\t" << (*(*data).channels)[i%size] << "\t" << (*(*data).onOff)[i%size] << "\n";
        i++;
        //wait timeDeltas*tempo seconds
        //check current chord and bass
        //send midi stuff
    }
    pthread_exit(NULL);
}


int run(){
    string testfile = "Piano.csv";
    vector<int> timeDeltas, channels, onOff;
    loadCSVToArray(testfile,timeDeltas,channels,onOff);

    struct Instrument Piano;
    Piano.timeDeltas = &timeDeltas;
    Piano.channels = &channels;
    Piano.onOff = &onOff;

    int size = onOff.size();
    int check;
    pthread_t threads[2];
    check = pthread_create(&threads[0], NULL, Play, (void *) &Piano);
    pthread_exit(NULL);


}

