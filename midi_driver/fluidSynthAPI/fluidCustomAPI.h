#ifdef __cplusplus
extern "C" {
#endif

void fluid_synth_init();

void noteOn(int chan, short key);

void noteOff(int chan, short key);

void playNoteOfLength(int chan, short key, short length);

void deleteFluidSynth();


#ifdef __cplusplus
}
#endif
