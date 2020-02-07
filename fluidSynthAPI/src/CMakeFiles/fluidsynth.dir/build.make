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
include src/CMakeFiles/fluidsynth.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/fluidsynth.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/fluidsynth.dir/flags.make

src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o: src/CMakeFiles/fluidsynth.dir/flags.make
src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o: /home/neil/MIDI-Real-Time/fluidsynth/src/fluidsynth.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neil/MIDI-Real-Time/fluidSynthAPI/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fluidsynth.dir/fluidsynth.c.o   -c /home/neil/MIDI-Real-Time/fluidsynth/src/fluidsynth.c

src/CMakeFiles/fluidsynth.dir/fluidsynth.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fluidsynth.dir/fluidsynth.c.i"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neil/MIDI-Real-Time/fluidsynth/src/fluidsynth.c > CMakeFiles/fluidsynth.dir/fluidsynth.c.i

src/CMakeFiles/fluidsynth.dir/fluidsynth.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fluidsynth.dir/fluidsynth.c.s"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neil/MIDI-Real-Time/fluidsynth/src/fluidsynth.c -o CMakeFiles/fluidsynth.dir/fluidsynth.c.s

src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.requires:

.PHONY : src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.requires

src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.provides: src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.requires
	$(MAKE) -f src/CMakeFiles/fluidsynth.dir/build.make src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.provides.build
.PHONY : src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.provides

src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.provides.build: src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o


# Object files for target fluidsynth
fluidsynth_OBJECTS = \
"CMakeFiles/fluidsynth.dir/fluidsynth.c.o"

# External object files for target fluidsynth
fluidsynth_EXTERNAL_OBJECTS =

src/fluidsynth: src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o
src/fluidsynth: src/CMakeFiles/fluidsynth.dir/build.make
src/fluidsynth: src/libfluidsynth.so.2.3.0
src/fluidsynth: src/CMakeFiles/fluidsynth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neil/MIDI-Real-Time/fluidSynthAPI/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fluidsynth"
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fluidsynth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/fluidsynth.dir/build: src/fluidsynth

.PHONY : src/CMakeFiles/fluidsynth.dir/build

src/CMakeFiles/fluidsynth.dir/requires: src/CMakeFiles/fluidsynth.dir/fluidsynth.c.o.requires

.PHONY : src/CMakeFiles/fluidsynth.dir/requires

src/CMakeFiles/fluidsynth.dir/clean:
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI/src && $(CMAKE_COMMAND) -P CMakeFiles/fluidsynth.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/fluidsynth.dir/clean

src/CMakeFiles/fluidsynth.dir/depend:
	cd /home/neil/MIDI-Real-Time/fluidSynthAPI && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neil/MIDI-Real-Time/fluidsynth /home/neil/MIDI-Real-Time/fluidsynth/src /home/neil/MIDI-Real-Time/fluidSynthAPI /home/neil/MIDI-Real-Time/fluidSynthAPI/src /home/neil/MIDI-Real-Time/fluidSynthAPI/src/CMakeFiles/fluidsynth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/fluidsynth.dir/depend

