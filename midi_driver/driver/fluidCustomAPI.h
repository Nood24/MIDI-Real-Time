#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void fluid_synth_init();

void noteOn(int chan, short key);

void noteOff(int chan, short key);

void playNoteOfLength(int chan, short key, short length);

void deleteFluidSynth();

void changeInstrument(int channel, int bank, int instrument);

void sendNote(bool on, int channel, int note);

#ifdef __cplusplus
}
#endif
