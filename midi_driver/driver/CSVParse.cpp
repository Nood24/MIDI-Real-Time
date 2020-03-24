#include <fstream>
#include <iostream>
#include <vector>
#include "CSVParse.h"
#include <pthread.h>
using namespace std;

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


int main(){
    string testfile = "../midiparser/GayGordons/Piano.csv";
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

