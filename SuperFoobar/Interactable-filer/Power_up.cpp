/*
* FILENAME:      Power_up.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include "Power_up.h"

using namespace std;

Power_up::Power_up(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

void Power_up::set_type(string new_type)
{
	this->type = new_type;
}

void Power_up::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
		this->interact();
}

void Power_up::interact()
{
	this->flip_dead();
}

std::string Power_up::type_str()
{
	return this->type;
}
