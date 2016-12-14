/*
* FILENAME:      Timer.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include "Timer.h"

float Timer::get_time_remaining()
{
	return this->time_remaining;
}

void Timer::set_time_remaining(float new_time_remaining)
{
	this->time_remaining = new_time_remaining;
}

void Timer::countdown()
{
	this->temp_counter = (this->clock).getElapsedTime().asSeconds();
	this->time_remaining -= this->temp_counter;
	(this->clock).restart();
}