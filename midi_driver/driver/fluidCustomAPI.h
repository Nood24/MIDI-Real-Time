#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void fluid_synth_init();

void note_on(int chan, short key, short vel);

void note_off(int chan, short key);

void play_note_of_length(int chan, short key, short length);

void delete_fluidsynth();

void change_instrument(int channel, int bank, int instrument);

void send_note(bool on, int channel, int note, int velocity);

void all_notes_off(int chan);

#ifdef __cplusplus
}
#endif
