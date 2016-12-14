/*
* FILENAME:      Timer.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Timer class.
*/

#pragma once
#include "SFML/Graphics.hpp"

class Timer {
public:
	Timer() = default;
	~Timer() = default;

	/*
	* FUNCTION: float get_time_remaining();
	* Returns the float time_remaining, used to countdown the in game timer
	*/

	float get_time_remaining();

	/*
	* FUNCTION: void set_time_remaining(float);
	* Sets the value of the float time_remaining
	*/

	void set_time_remaining(float);

	/*
	* FUNCTION: void countdown();
	* Uses the sfml clock object and float temp_counter to reduce time_remaining
	*/

	void countdown();

protected:
	float time_remaining{ 120.0f };
	float temp_counter{ 0.0f };
	sf::Clock clock;
};