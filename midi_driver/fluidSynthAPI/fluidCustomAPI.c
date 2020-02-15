/* 
 *
 * To compile:
 *   gcc -o fluidEventsExample -lfluidsynth fluidEventsExample.c
 *   I prefer gcc -o fluidEventsExample -lfluidsynth fluidEventsExample.c 'pkg-config fluidsynth --libs'
 * To run:
 *   fluidsynth_arpeggio soundfont [steps [duration]]
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <fluidsynth.h>
#include <unistd.h>


fluid_synth_t *synth;
fluid_audio_driver_t *audiodriver;
fluid_sequencer_t *sequencer;
short synth_destination, client_destination;
fluid_settings_t *settings;


void fluid_synth_init(){


settings = new_fluid_settings();
fluid_settings_setstr(settings,"audio.driver","alsa");

/* create the synth, driver and sequencer instances */
synth = new_fluid_synth(settings);
/* load a SoundFont */
int sf_id = fluid_synth_sfload(synth, "/usr/share/sounds/sf2/FluidR3_GM.sf2", 1);

sequencer = new_fluid_sequencer2(0);
/* register the synth with the sequencer */
synth_destination = fluid_sequencer_register_fluidsynth(sequencer,synth);
/* register the client name and callback */
client_destination = fluid_sequencer_register_client(sequencer,"MidiController", NULL, NULL);

audiodriver = new_fluid_audio_driver(settings, synth);
 
printf("Hello World!");

/* Changing Intruments */
fluid_synth_program_select(synth, 0, sf_id,0, 20);

}

/* schedule a note on message */
void noteOn(int chan, short key)
{
    fluid_event_t *ev = new_fluid_event();
    fluid_event_set_source(ev, -1);
    fluid_event_set_dest(ev, synth_destination);
    fluid_event_noteon(ev, chan, key, 127);
    fluid_sequencer_send_now(sequencer, ev);
    delete_fluid_event(ev);
    
}
/* schedule a note off message */
void noteOff(int chan, short key)
{
    fluid_event_t *ev = new_fluid_event();
    fluid_event_set_source(ev, -1);
    fluid_event_set_dest(ev, synth_destination);
    fluid_event_noteoff(ev, chan, key);
    fluid_sequencer_send_now(sequencer, ev);
    delete_fluid_event(ev);

}

/* Play a note with a length in seconds*/
void playNoteOfLength(int chan, short key, short length){
    noteOn(chan, key);
    sleep(length);
    noteOff(chan, key);
}


void deleteFluidSynth(){
    delete_fluid_audio_driver(audiodriver);
    delete_fluid_sequencer(sequencer);
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
}

int main(){
while(1){
}
}
