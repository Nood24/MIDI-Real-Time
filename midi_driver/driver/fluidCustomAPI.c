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
#include <stdbool.h>


fluid_synth_t *synth;
fluid_audio_driver_t *audiodriver;
fluid_sequencer_t *sequencer;
short synth_destination, client_destination;
fluid_settings_t *settings;
int sf_id;


/* Initialize fluidsynth API */
void fluid_synth_init(){

    /* Set Settings */
    settings = new_fluid_settings();
    fluid_settings_setstr(settings,"audio.driver","alsa");
    fluid_settings_setint(settings,"audio.periods",4);
    fluid_settings_setnum(settings,"synth.gain",1);
    fluid_settings_setint(settings,"synth.min-note-length", 55);
    fluid_settings_setint(settings,"synth.sample-rate", 44100);

    /* create the synth, driver and sequencer instances */
    synth = new_fluid_synth(settings);
    /* load a SoundFont */
    sf_id = fluid_synth_sfload(synth, "/usr/share/sounds/sf2/FluidR3_GM.sf2", 1);

    sequencer = new_fluid_sequencer2(0);
    /* register the synth with the sequencer */
    synth_destination = fluid_sequencer_register_fluidsynth(sequencer,synth);
    /* register the client name and callback */
    client_destination = fluid_sequencer_register_client(sequencer,"MidiController", NULL, NULL);

    audiodriver = new_fluid_audio_driver(settings, synth);

}

/* schedule a note on message */
void noteOn(int chan, short key, short vel){
    fluid_event_t *ev = new_fluid_event();
    fluid_event_set_source(ev, -1);
    fluid_event_set_dest(ev, synth_destination);
    fluid_event_noteon(ev, chan, key, vel);
    fluid_sequencer_send_now(sequencer, ev);
    delete_fluid_event(ev);
}

/* schedule a note off message */
void noteOff(int chan, short key){
    fluid_event_t *ev = new_fluid_event();
    fluid_event_set_source(ev, -1);
    fluid_event_set_dest(ev, synth_destination);
    fluid_event_noteoff(ev, chan, key);
    fluid_sequencer_send_now(sequencer, ev);
    delete_fluid_event(ev);
}

/* Play a note with a length in seconds*/
void playNoteOfLength(int chan, short key, short length){
    //printf("Playing Note of length ");
    noteOn(chan, key,90);
    sleep(length);
    noteOff(chan, key);
}

/* Shutdown synth */
void deleteFluidSynth(){
    delete_fluid_audio_driver(audiodriver);
    delete_fluid_sequencer(sequencer);
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
}

/* Changing Intruments */
void changeInstrument(int channel, int bank, int instrument){
    fluid_synth_program_select(synth, channel, sf_id, bank, instrument);
}

/* Send On or Off Notes */
void sendNote(bool on, int channel, int note, int velocity){ 
    //printf("Sending note: %d to channel %d and its %d\n",note,channel,on);
    if (on)
        noteOn(channel,note,velocity);
    else
        noteOff(channel,note);
}

/* Set All Notes on a Channel Off*/
void all_notes_off(int chan){
    fluid_synth_all_notes_off(synth, chan);
}

