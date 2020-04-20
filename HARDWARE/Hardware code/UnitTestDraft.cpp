
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "HardwareController.h"
#include "hardwareinterface.h"


TEST_CASE("Buttons Change System State")
{
	CHECK(true == ((digitalRead(button1) == LOW) && (state == 1)));
	CHECK(true == ((digitalRead(button2) == LOW) && (state == 2)));
	CHECK(true == ((digitalRead(button3) == LOW) && (state == 3)));
	CHECK(true == ((digitalRead(button4) == LOW) && (state == 4)));

}

TEST_CASE("Button press Sets a new state")
{
	CHECK(true == ((digitalRead(button1) == LOW) && (newState == true)));
	CHECK(true == ((digitalRead(button2) == LOW) && (newState == true)));
	CHECK(true == ((digitalRead(button3) == LOW) && (newState == true)));
	CHECK(true == ((digitalRead(button4) == LOW) && (newState == true)));
}

TEST_CASE("New State Occurs only on button press")
{	
	newState == true;
	CHECK(newState == false);
}

TEST_CASE("Button1 Switches the song Left")
{
	digitalRead(button1) == LOW;

	SECTION( "Changes to Previous song if no song is playing"){
	songPlaying == false;

		REQUIRE(processInput(state) == shiftSongLeft());
	}
	SECTION( "Doesn't Change to Previous Song If a song is playing" ){
	songPlaying == true;

		REQUIRE(processInput(state) == cout << "\nSong must be off to switch song!\n");
}

TEST_CASE("Button2 Switches the song Right")
{
	digitalRead(button2) == LOW;

	SECTION( "Changes to Next song if no song is playing"){
	songPlaying == false;

		REQUIRE(processInput(state) == shiftSongRight());
	}
	SECTION( "Doesn't Change to Next Song If a song is playing" ){
	songPlaying == true;

		REQUIRE(processInput(state) == cout << "\nSong must be off to switch song!\n");
}

TEST_CASE("Button3 Starts/Stops the current Song")
{
	digitalRead(button3) == LOW;

	REQUIRE(processInput(state) == startStopSong());
}

TEST_CASE("Button4 Does Nothing :)")
{
	digitalRead(button4) == LOW;

	REQUIRE(processInput(state) == cout << "\nButton 4 is placeholder\n");
}
