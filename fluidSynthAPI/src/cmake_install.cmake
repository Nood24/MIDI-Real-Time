# Install script for directory: /home/neil/MIDI-Real-Time/fluidsynth/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/neil/MIDI-Real-Time/fluidSynthAPI/src/fluidsynth")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth"
         OLD_RPATH "/home/neil/MIDI-Real-Time/fluidSynthAPI/src:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/fluidsynth")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libfluidsynth.so.2.3.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libfluidsynth.so.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libfluidsynth.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES
    "/home/neil/MIDI-Real-Time/fluidSynthAPI/src/libfluidsynth.so.2.3.0"
    "/home/neil/MIDI-Real-Time/fluidSynthAPI/src/libfluidsynth.so.2"
    "/home/neil/MIDI-Real-Time/fluidSynthAPI/src/libfluidsynth.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libfluidsynth.so.2.3.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libfluidsynth.so.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libfluidsynth.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/fluidsynth" TYPE FILE FILES
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/audio.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/event.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/gen.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/ladspa.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/log.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/midi.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/misc.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/mod.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/seq.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/seqbind.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/settings.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/sfont.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/shell.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/synth.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/types.h"
    "/home/neil/MIDI-Real-Time/fluidsynth/include/fluidsynth/voice.h"
    "/home/neil/MIDI-Real-Time/fluidSynthAPI/include/fluidsynth/version.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/neil/MIDI-Real-Time/fluidSynthAPI/include/fluidsynth.h")
endif()

