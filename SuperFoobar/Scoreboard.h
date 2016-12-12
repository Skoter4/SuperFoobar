#pragma once
#include "Score.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional> // std::greater<int>
#include <sstream>

class Scoreboard
{
public:
	Scoreboard() = default;
	~Scoreboard() = default;
	std::string read();
	std::string read_top5();
	void write(std::string);
};