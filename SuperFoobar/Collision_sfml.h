/*
* FILENAME:     Collision_sfml.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* A collision handler which controlls the collision between two objects, for example between Foobar and the floor.
*
*/

#pragma once
#include "Map_object.h"
#include "Character filer\Character.h"
#include <string>
#include <memory>

/*
*	FUNCTION: void block_collision (std::shared_ptr<Character> character_object, std::shared_ptr<Map_object> block_object)
*	This function controlls the collision between a character_obejct and a block_object.
*	If a collision occurs it decides from which direction the collsion happen, and then it
*	changes the colliding objects coordinates/position accordingly.
*/

void block_collision(std::shared_ptr<Character> character_object, std::shared_ptr<Map_object> block_object);


/*
*	FUNCTION: bool point_in_rect(int x, int y, std::shared_ptr<Map_object> character_object)
*	This function will return true if the inserted coordinates overlaps with the input object.
*	It compares the given coordinates with the objects corner coordinates.
*/

bool point_in_rect(int x, int y, std::shared_ptr<Map_object> character_object);