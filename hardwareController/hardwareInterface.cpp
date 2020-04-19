#include<iostream>  //Include all needed libraries
#include<wiringPi.h>   //Add the wiringPi library to control GPIO pins on C++
#include"HardwareController.h"

using namespace std;
int state;
bool newState = false;

int getState(){
	if (newState == true){
		newState = false;
		return state;
	}
	else {
		return 0;
	}
}


int runHardwareInterface()
{

//init state
state = 0;

//Declare the GPIO pins for each system component

// Switch1: Physical pin 12, wiringPi 1, BCM GPIO18.
const int button1 = 1;
//LED1: Physical pin 11, wiringPi 0, BCM GPIO17.
const int light1 = 0; 
// Switch2: Physical pin 16, wiringPi 4, BCM GPIO23.
const int button2 = 4;
//LED2: Physical pin 15, wiringPi 3, BCM GPIO22.
const int light2 = 3; 
// Switch3: Physical pin 18, wiringPi 5, BCM GPIO24.
const int button3 = 5;
//LED3: Physical pin 19, wiringPi 12, BCM GPIO10.
const int light3 = 12; 
// Switch4: Physical pin 22, wiringPi 6, BCM GPIO25.
const int button4 = 6;
//LED4: Physical pin 21, wiringPi 13, BCM GPIO9.
const int light4 = 13; 


wiringPiSetup();           //Setup the Pi Library
pinMode(button1, INPUT);   //Set button1 as an input
pinMode(light1, OUTPUT);   //Set LED1 as an output

pinMode(button2, INPUT);   //Set button2 as an input
pinMode(light2, OUTPUT);   //Set LED2 as an output

pinMode(button3, INPUT);   //Set button3 as an input
pinMode(light3, OUTPUT);   //Set LED3 as an output

pinMode(button4, INPUT);   //Set button4 as an input
pinMode(light4, OUTPUT);   //Set LED4 as an output


//set initial state to 0 
digitalWrite(light1, LOW);
//Turn off other LEDs
digitalWrite(light2, LOW);
digitalWrite(light3, LOW);
digitalWrite(light4, LOW);
//digitalRead(button1) == LOW;
while(1)
{	
	//When button1 is pressed digitalRead returns LOW
	if (digitalRead(button1) == LOW)
{	
	state = 1;	
	newState = true;
	processInput(state);
	cout << state << "\n";
        do{	//printf("Button1 pressed\n");
		digitalWrite(light1, HIGH);
		digitalWrite(light2, LOW);
		digitalWrite(light3, LOW);
		digitalWrite(light4, LOW);
	}while(digitalRead(button1)== LOW);
	digitalWrite(light1,LOW);
}
//When button2 is pressed digitalRead returns LOW
	else if (digitalRead(button2) == LOW)
{	
	state = 2;
	newState = true;
        processInput(state);	
	cout << state << "\n";
	do{	
		digitalWrite(light2, HIGH);
		digitalWrite(light1, LOW);
		digitalWrite(light3, LOW);
		digitalWrite(light4, LOW);
	
	}while(digitalRead(button2) == LOW);
	digitalWrite(light2,LOW);
}

//When button3 is pressed digitalRead returns LOW
	else if (digitalRead(button3) == LOW)
{	
	state = 3;
	newState = true;
	processInput(state);
	cout << state << "\n";
	do{
		digitalWrite(light3, HIGH);
		digitalWrite(light1, LOW);
		digitalWrite(light2, LOW);
		digitalWrite(light4, LOW);
	       
	
	}while(digitalRead(button3) == LOW);
	digitalWrite(light3,LOW);
}

//When button4 is pressed digitalRead returns LOW
	else if (digitalRead(button4) == LOW)
{	
        state = 4;
	newState = true;
	processInput(state);
	cout << state << "\n";
	do{	
		digitalWrite(light4, HIGH);
		digitalWrite(light1, LOW);
		digitalWrite(light2, LOW);
		digitalWrite(light3, LOW);
	}while(digitalRead(button4) == LOW);
	digitalWrite(light4,LOW);
}
    }
return 0; 
}
