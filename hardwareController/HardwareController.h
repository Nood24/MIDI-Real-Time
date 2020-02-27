
class Process{

  private:
    std::vector<unsigned char>* message;
    int chordNotes[3]; //CHANGE
    int chordIdx;
    int bassNote; //CHANGE
    int byte1;
    int byte2;
    unsigned int nBytes;
    bool is_bass;
    int tempo;
    std::vector<int> timeDeltas, channels, onOff;
    //bool is_set;

    bool isKthBitSet(int n, int k);
    
    void setChordNote(int note);

    int getChordNotes();

    void loadCSVToArray(std::string &filename, std::vector<int> &timeDeltas, std::vector<int> &channels, std::vector<int> &onOff);

 
  public:
    void setMessage(std::vector<unsigned char>* setMessage);

    void printMessage();

    void run();

    void *Play(void *arraySize);
};
 


