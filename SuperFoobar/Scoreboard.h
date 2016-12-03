#pragma once
#include "Score.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional> // std::greater<int>

class Scoreboard
{
public:
	Scoreboard() = default;
	~Scoreboard() = default;
	std::string read();
	void write(std::string);
};