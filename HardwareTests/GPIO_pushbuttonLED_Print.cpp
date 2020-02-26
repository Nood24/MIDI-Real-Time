#include<iostream>  //Include all needed libraries
#include<wiringPi.h>   //Add the wiringPi library

using namespace std;

int main()
{
// Switch: Physical pin 12, wiringPi 1, BCM GPIO18.

const int button = 1;

//LED: Physical pin 11, wiringPi 0, BCM GPIO17.
const int light = 0; 

wiringPiSetup();      //Setup the Library
pinMode(button, INPUT);   //Set the button as an input
pinMode(light, OUTPUT);   //Set the LED as an output

while(1)
{	
	//When button is pressed digitalRead returns LOW
	if (digitalRead(button) == LOW)
{	
	printf("Button is pressed\n");

	//Toggle the LED
	digitalWrite(light, !digitalRead(light));
	delay(500);    //Delay 500ms
}	else{
	printf("Button is released\n");
	delay(1000);	//Delay 1s
}
}
return 0; 
}
