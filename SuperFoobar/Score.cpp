/*
* FILENAME:      Score.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include "Score.h"

void Score::increase_score(float num)
{
	this->score += num;
}

float Score::get_score()
{
	return this->score;
}

void Score::time_to_score(Timer timer)
{
	this->score += timer.get_time_remaining();
}

