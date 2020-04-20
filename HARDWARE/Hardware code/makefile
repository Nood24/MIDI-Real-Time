all:
	g++ -pthread -c -g -o HardwareController.o HardwareController.cpp -lwiringPi
	g++ -pthread -c -g -o HardwareController_Test.o HardwareController_Test.cpp -lwiringPi
	g++ -pthread -c -g -o hardwareInterface.o hardwareInterface.cpp -lwiringPi
	g++ -pthread -o executible HardwareController_Test.o HardwareController.o hardwareInterface.o -lwiringPi
	rm *.o
