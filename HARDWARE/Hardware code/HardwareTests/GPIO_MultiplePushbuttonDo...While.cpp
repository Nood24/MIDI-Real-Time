#include<iostream>  //Include all needed libraries
#include<wiringPi.h>   //Add the wiringPi library to control GPIO pins on C++

using namespace std;

int main()
{	//Declare the GPIO pins for each system component

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


wiringPiSetup();      //Setup the Pi Library
pinMode(button1, INPUT);   //Set button1 as an input
pinMode(light1, OUTPUT);   //Set LED1 as an output

pinMode(button2, INPUT);   //Set button2 as an input
pinMode(light2, OUTPUT);   //Set LED2 as an output

pinMode(button3, INPUT);   //Set button3 as an input
pinMode(light3, OUTPUT);   //Set LED3 as an output

pinMode(button4, INPUT);   //Set button4 as an input
pinMode(light4, OUTPUT);   //Set LED4 as an output

while(1)
{	
	//When button1 is pressed digitalRead returns LOW
	if (digitalRead(button1) == LOW)
	//Loop to Keep LED1 on until another button is pressed
{	do{	printf("Button1 pressed\n");
		//Turn on LED1
		digitalWrite(light1, HIGH);
		//Turn off other LEDs
		digitalWrite(light2, LOW);
		digitalWrite(light3, LOW);
		digitalWrite(light4, LOW);
	}while(digitalRead(button2) == HIGH && digitalRead(button3) == HIGH && digitalRead(button4) == HIGH);
}
//When button2 is pressed digitalRead returns LOW
	else if (digitalRead(button2) == LOW)
{	do{	printf("Button2 pressed\n");
		//Turn on LED2
		digitalWrite(light2, HIGH);
		//Turn off other LEDs
		digitalWrite(light1, LOW);
		digitalWrite(light3, LOW);
		digitalWrite(light4, LOW);
	}while(digitalRead(button1) == HIGH && digitalRead(button3) == HIGH && digitalRead(button4) == HIGH);
}

//When button3 is pressed digitalRead returns LOW
	else if (digitalRead(button3) == LOW)
{	do{	printf("Button3 pressed\n");
		//Turn on LED3
		digitalWrite(light3, HIGH);
		//Turn off other LEDs
		digitalWrite(light1, LOW);
		digitalWrite(light2, LOW);
		digitalWrite(light4, LOW);
	}while(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH && digitalRead(button4) == HIGH);
}

//When button4 is pressed digitalRead returns LOW
	else if (digitalRead(button4) == LOW)
{	do{	printf("Button4 pressed\n");
		//Turn on LED4
		digitalWrite(light4, HIGH);
		//Turn off other LEDs
		digitalWrite(light1, LOW);
		digitalWrite(light2, LOW);
		digitalWrite(light3, LOW);
	}while(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH && digitalRead(button3) == HIGH);
}

}
return 0; 
}
