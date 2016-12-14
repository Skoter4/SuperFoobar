/*
* FILENAME:       Score.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Score class.
*/

#pragma once
#include "Timer.h"

class Score
{
public:
	Score() = default;
	~Score() = default;

	/*
	* FUNCTION: void increase_score(float);
	* Increases the float score with a specified amount
	*/

	void increase_score(float);

	/*
	* FUNCTION: float get_score();
	* Returns the float score
	*/

	float get_score();

	/*
	* FUNCTION: void time_to_score(Timer);
	* Takes a Timer object and adds the time remaining to score when Foobar reaches the finish line
	*/

	void time_to_score(Timer);

private:
	float score{0.0f};
};