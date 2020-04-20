class VirtualHardwareController{
public:
    bool playing;
    bool playing_ready;
    VirtualHardwareController();
    void set_state(bool state);
    int get_input();
};

