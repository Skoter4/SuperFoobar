/*
* FILENAME:      Coin.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include "Coin.h"

using namespace std;

Coin::Coin(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

void Coin::interact_with(std::shared_ptr<Map_object> map_object)
{
		if (map_object->type_str() == "foobar")
		{
			interact();
		}
}

void Coin::interact()
{
	this->flip_dead();
}

string Coin::type_str()
{
	return "coin";
}
