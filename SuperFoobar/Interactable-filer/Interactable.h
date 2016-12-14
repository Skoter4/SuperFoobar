/*
* FILENAME:      Interactable.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Interactable class, subclass to Map_object.
*/

#pragma once
#include <memory>
#include "../Block-filer/Block.h"
#include "../Map_object.h"

class Interactable : public Map_object
{
public:

	/*
	* FUNCTION: void interact();
	* Executes flip_dead() which removes the Coin object from the game
	*/

	void interact();

	~Interactable() = default;

protected:

	/*
	* CONSTRUCTOR: Interactable(int, int, int, int);
	* Initialize an Interactable object with x and y positions as well as height and width
	* using the Map object constructor
	*/

	Interactable(int, int, int, int);
	std::unique_ptr<Cluster> position;
};
