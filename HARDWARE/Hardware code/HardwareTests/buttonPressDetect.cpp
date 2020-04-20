#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char** argv)
{
    // Intialize the wiringPi Library
    wiringPiSetup();

	const int INPUT_PIN = 12;
	
    // Read input on this pin
    pinMode(INPUT_PIN, INPUT);

    while(true)
    {
        // As soon as we dedect an input, log and quit.
        if(digitalRead(INPUT_PIN) == HIGH)
		{
			printf("Button is pressed!\n");	
			break;
		}
    }

    // Exit program
    return 0;
}
