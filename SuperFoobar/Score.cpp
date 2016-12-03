#include "Score.h"

using namespace std;

void Score::increase_score()
{
	this->score += 1.0f;
}

float Score::get_score()
{
	return this->score;
}

void Score::time_to_score(Timer timer)
{
	this->score += timer.get_time_remaining();
}

