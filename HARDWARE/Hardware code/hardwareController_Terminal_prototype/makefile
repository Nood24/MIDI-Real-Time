all:
	g++ -pthread -c -g -o HardwareController.o HardwareController.cpp
	g++ -pthread -c -g -o HardwareController_Test.o HardwareController_Test.cpp
	g++ -pthread -o executible HardwareController_Test.o HardwareController.o
	rm *.o
