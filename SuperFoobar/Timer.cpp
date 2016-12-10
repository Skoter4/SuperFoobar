#include "Timer.h"

using namespace std;

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