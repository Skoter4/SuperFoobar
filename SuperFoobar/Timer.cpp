#include "Timer.h"

using namespace std;

float Timer::get_time_remaining()
{
	return this->time_remaining;
}

void Timer::countdown()
{
	this->temp_counter = (this->clock).getElapsedTime().asSeconds();
	this->time_remaining -= this->temp_counter;
	(this->clock).restart();
}