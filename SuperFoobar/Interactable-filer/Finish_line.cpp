/*
* FILENAME:      Finish_line.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*/

#include "Finish_line.h"

using namespace std;

Finish_line::Finish_line(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

void Finish_line::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
	{
		interact();
	}
}

void Finish_line::interact()
{
	flip_dead();
}
string Finish_line::type_str()
{
	return "finish_line";
}
