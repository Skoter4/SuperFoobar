/*
* FILENAME:      Interactable.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include "Interactable.h"

Interactable::Interactable(int x_pos, int y_pos, int height, int width)
	: Map_object(x_pos, y_pos, height, width)
{}

void Interactable::interact()
{
	this->flip_dead();
}
