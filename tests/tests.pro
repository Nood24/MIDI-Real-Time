QT += core gui
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


CONFIG += link_pkgconfig
PKGCONFIG += 'fluidsynth'

LIBS +=  -lpthread
LIBS +=  -lasound 

        
QMAKE_CXXFLAGS += -D__LINUX_ALSA__
QMAKE_CXXFLAGS += -Wall

SOURCES += ../midi_driver/driver/DanceSet.cpp \
    ../midi_driver/driver/Instrument.cpp \
    tests_main.cpp \
    mock_mainwindow.cpp \
    ../midi_driver/driver/Controller.cpp \
    ../midi_driver/driver/fluidCustomAPI.c \
    ../rtmidi/RtMidi.cpp \
    ../midi_driver/driver/VirtualHardwareController.cpp

HEADERS += ../midi_driver/driver/DanceSet.h \
    ../midi_driver/driver/Instrument.h \
    mock_mainwindow.h \
    ../midi_driver/driver/Controller.h \
    ../midi_driver/driver/fluidCustomAPI.h \
    ../rtmidi/RtMidi.h \
    ../midi_driver/driver/VirtualHardwareController.h \
    ../midi_driver/driver/cppThread-master/CppThread.h



INCLUDEPATH += ../midi_driver/driver

FORMS += \
    ../frontEnd/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../frontEnd/images.qrc
