/*
* FILENAME:       Scoreboard.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Scoreboard class.
* It reads and writes score from and to a txt file.
*/

#pragma once
#include "Score.h"
#include <string>
#include <fstream>
#include <vector>
#include <functional> // std::greater<int>
#include <sstream>

class Scoreboard
{
public:
	Scoreboard() = default;
	~Scoreboard() = default;

	/*
	* FUNCTION: std::string read();
	* Sorts and reads a txt file and returns it as a string
	*/

	std::string read();

	/*
	* FUNCTION: std::string read_top5();
	* Using read() it only returns the top 5 results
	*/

	std::string read_top5();

	/*
	* FUNCTION: void write(std::string);
	* Takes a string and appends it to the end of a txt file
	*/

	void write(std::string);
};