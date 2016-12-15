/*
* FILENAME:     Projectile.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
* DESCRIPTION:
* This is the declaration file for Projectile. Projectile is a subclass to character.
* It inheritates the functionality of character.
*/


#pragma once
#include "../Character filer/Enemy/Enemy_1.h"
#include "Character filer\Foobar\Foobar.h"
class Projectile :
	public Character
{
public:
	/*
	*	CONSTRUCTOR: Projectile(int, int, int, int)
	*
	*	Constructor used to create Projectile-objects.
	*  Uses the character constructor.
	*/

	Projectile(int, int, int, int);

	/*
	*	DESTRUCTOR: ~Projectile()
	*
	*	A defualt destructor for Generator objects.
	*/

	~Projectile() = default;

	/*
	*	FUNCTION: interact_with(std::shared_ptr<Map_object> my_char) override
	*
	*	If a collision occurs, this function is executed. Depending on what type the other object
	*	is, it runs different functions.
	*/

	void interact_with(std::shared_ptr<Map_object> my_char) override;


	/*
	*	FUNCTION: type_str() override
	*
	*	This function returns a string which says "projectile".
	*	Is used to define that a object is of type Projectile.
	*/

	std::string type_str() override;


	void interact() override;
};

