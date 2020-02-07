# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neil/MIDI-Real-Time/fluidsynth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neil/MIDI-Real-Time/fluidSynthAPI

# Include any dependencies generated for this target.
include test/CMakeFiles/test_ct2hz.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_ct2hz.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_ct2hz.dir/flags.make

test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o: test/CMakeFiles/test_ct2hz.dir/flags.make
test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o: /home/neil/MIDI-Real-Time/fluidsynth/test/test_ct2hz.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neil/MIDI-Real-Time/fluidSynthAPI/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o   -c /home/neil/MIDI-Real-Time/fluidsynth/test/test_ct2hz.c

test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_ct2hz.dir/test_ct2hz.c.i"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neil/MIDI-Real-Time/fluidsynth/test/test_ct2hz.c > CMakeFiles/test_ct2hz.dir/test_ct2hz.c.i

test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_ct2hz.dir/test_ct2hz.c.s"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neil/MIDI-Real-Time/fluidsynth/test/test_ct2hz.c -o CMakeFiles/test_ct2hz.dir/test_ct2hz.c.s

test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.requires:

.PHONY : test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.requires

test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.provides: test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.requires
	$(MAKE) -f test/CMakeFiles/test_ct2hz.dir/build.make test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.provides.build
.PHONY : test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.provides

test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.provides.build: test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o


# Object files for target test_ct2hz
test_ct2hz_OBJECTS = \
"CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o"

# External object files for target test_ct2hz
test_ct2hz_EXTERNAL_OBJECTS = \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_alsa.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_aufile.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_rtkit.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_oss.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_pulse.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_sdl2.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_conv.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_hash.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_list.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_ringbuffer.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_settings.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_sys.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_defsfont.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_sfont.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_sffile.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_samplecache.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_adsr_env.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_chorus.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_iir_filter.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_lfo.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice_dsp.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice_event.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice_mixer.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rev.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_chan.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_event.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_gen.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_mod.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_synth.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_synth_monopoly.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_tuning.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_voice.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_midi.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_midi_router.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_seqbind.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_seq.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_adriver.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_mdriver.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_cmd.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_filerenderer.c.o" \
"/home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_ladspa.c.o"

test/test_ct2hz: test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_alsa.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_aufile.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_rtkit.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_oss.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_pulse.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_sdl2.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_conv.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_hash.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_list.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_ringbuffer.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_settings.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/utils/fluid_sys.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_defsfont.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_sfont.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_sffile.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/sfloader/fluid_samplecache.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_adsr_env.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_chorus.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_iir_filter.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_lfo.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice_dsp.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice_event.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rvoice_mixer.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/rvoice/fluid_rev.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_chan.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_event.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_gen.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_mod.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_synth.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_synth_monopoly.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_tuning.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/synth/fluid_voice.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_midi.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_midi_router.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_seqbind.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/midi/fluid_seq.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_adriver.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/drivers/fluid_mdriver.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_cmd.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_filerenderer.c.o
test/test_ct2hz: src/CMakeFiles/libfluidsynth-OBJ.dir/bindings/fluid_ladspa.c.o
test/test_ct2hz: test/CMakeFiles/test_ct2hz.dir/build.make
test/test_ct2hz: test/CMakeFiles/test_ct2hz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neil/MIDI-Real-Time/fluidSynthAPI/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_ct2hz"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_ct2hz.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_ct2hz.dir/build: test/test_ct2hz

.PHONY : test/CMakeFiles/test_ct2hz.dir/build

test/CMakeFiles/test_ct2hz.dir/requires: test/CMakeFiles/test_ct2hz.dir/test_ct2hz.c.o.requires

.PHONY : test/CMakeFiles/test_ct2hz.dir/requires

test/CMakeFiles/test_ct2hz.dir/clean:
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/test && $(CMAKE_COMMAND) -P CMakeFiles/test_ct2hz.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_ct2hz.dir/clean

test/CMakeFiles/test_ct2hz.dir/depend:
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neil/MIDI-Real-Time/fluidsynth /home/neil/MIDI-Real-Time/fluidsynth/test /home/neil/MIDI-Real-Time/fluidSynthAPI /home/neil/MIDI-Real-Time/fluidSynthAPI/test /home/neil/MIDI-Real-Time/fluidSynthAPI/test/CMakeFiles/test_ct2hz.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_ct2hz.dir/depend

