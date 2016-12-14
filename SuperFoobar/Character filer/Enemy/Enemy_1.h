/*
* FILENAME:     Enemy_1.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
* DESCRIPTION:
* This is the declaration file for Enemy_1. Enemy_1 is a subclass to Character.
* It inheritates the functionality of character.
*
*/

#pragma once
#include "../Character filer/Character.h"

class Projectile;

class Enemy_1 :
	public Character
{
public:


	/*
	*	CONSTRUCTOR: Enemy_1(int x, int y, int width, int height)
	*
	*	Constructor used to create Enemy_1-objects.
	*  Uses the character constructor.
	*/


	Enemy_1(int x, int y, int width, int height);

	/*
	*	DESTRUCTOR: ~Enemy_1()
	*
	*	A defualt destructor for Enemy_1 objects.
	*/

	~Enemy_1() = default;

	/*
	*	FUNCTION: type_str() override
	*
	* This function returns a string which says "enemy_1".
	* Is used to define that a object is of type Enemy_1.
	*/

	std::string type_str() override;

	/*
	*	FUNCTION: interact_with(std::shared_ptr<Map_object> my_char) override
	*
	*	If a collision occurs, this function is executed. Depending on what type the other object
	*	is, it runs different functions.
	*/

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	*	FUNCTION: interact() override
	*
	* This function is used in interact_with when a
	* collsion has occured.
	*/

	void interact() override;

	/*
	*	Function: ready_to_fire()
	*
	*	A bool that returns the value of to_fire.
	*	Is used when the enemy shall fire a projectile.
	*/

	bool ready_to_fire();

	/*
	*	Function: flip_ready()
	*
	*	Flips the value of to_fire.
	*	Is used after a projectile is fired and when the enemy_1 is ready again.
	*/

	void flip_ready();

	/*
	*	Function: get_prev_time()
	*
	*	Reurns the value of prev_time.
	*	Is used when a projectile is fired.
	*/

	int get_prev_time();

	/*
	*	Function: set_prev_time(int time)
	*
	*	Sets the value of prev_time.
	*	Is used when a projectile is fired.
	*/

	void set_prev_time(int time);
	
	/*
	*	Function: fire_projectile()
	*
	*	Fires (Creates) a projectile-object which will
	*	fly in a certain direction. This function is executed
	*	when to_fire is true.
	*/

	std::shared_ptr<Character> fire_projectile();

private:
	std::shared_ptr<Character> my_projectile;
	bool to_fire{false};
	int prev_time{-1};
};

