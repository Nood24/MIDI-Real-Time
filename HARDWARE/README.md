# Hardware

The hardware for this project consisted of a Raspberry Pi model 3 B+ and a set of custom made pedals. The pedals work by sending a signal to the Raspberry Pi through the GPIO pins when a button is pressed. Each button controlls a different state on the Raspberry Pi. 
Power was supplied to the pedals through the 3.3v pin of the Raspberry Pi and the buttons interfaced with the GPIO pins. The buttons on the Foootpedal were pulled up usng 10k resistors and 1k resistors were used to provide protection to the GPIO pins. Each button returned a different state, which was used to control the song to be played.

## Working Mode for Pedals

Button 1 was configured for changing to the previous song, 
Button 2 changes to the next song
Button 3 starts or stops the current song
Buttons 4&5 were added for redundancy

## Overview
This folder contains the Schematic and PCB design layout for the hardware in addition to the code initially written for the hardware.
The hardware could not be completed due to the preferred components not arriving on time, and unforeseen circumstances (COVID-19) affecting group testing and completion of the case.

A Demo for the hardware can be found Below:
https://drive.google.com/open?id=1KOdL7dBLpbYbbtoLG0HIcY_gDxDBb9kd
https://drive.google.com/file/d/1KW-3mOWQXjU814z6pvtI7nNkC33g68KU/view?usp=sharing

## Design Software
ORCAD 17.2 was used for the design of the circuit schematic and PCB layout of this project
