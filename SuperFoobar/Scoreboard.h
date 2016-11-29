#pragma once
#include "Score.h"
#include <string>
#include <iostream>
#include <fstream>

class Scoreboard
{
public:
	Scoreboard() = default;
	~Scoreboard() = default;
	std::string read();
	void write(std::string);
	//void sort();
};