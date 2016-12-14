/*
* FILENAME:      Foobar.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*
* DESCRIPTION:
* This file contains the declaration of the class Foobar, which holds the information of the player,
* it is one type of 3 enemies, and is a subclass to Character, so it inheritates the functionality of Character.
* In this file some function only used for the player is declared och defined. 
*/

#pragma once
#include "../Character.h"
#include "../Interactable-filer/Power_up.h"
#include <iostream>



class Foobar :
	public Character
{
public:
	//Foobar();

	/*
	* DESTRUCTOR: ~Foobar() = defualt;
	*
	* Default-destructor, used when necessary to destruct the object. Used by the compiler.
	*/
	~Foobar() = default;

	/*
	* CONSTRUCTOR: Foobar() = defualt;
	*
	* Constructor to create a foobar-object. Given the member-values as input. 
	*/
	Foobar(int x_pos, int y_pos, int width, int height);

	/*
	* FUNCTION: type_Str() override;
	*
	* Returns a string that is specific for this type of object.
	* Used to identify the specific object.
	*/
	std::string type_str() override;

	/*
	* FUNCTION: power_up(std::shared_ptr<Power_up>) override;
	*
	* When player interacts with a power_up some members must change values/settings accordingly. 
	* One example may be that when you get large your height is increased, your #lifes is increased. 
	* With this function all necessary changes will happen. 
	*/
	void power_up(std::shared_ptr<Power_up>);

	/*
	* FUNCTION: increase_size(int, int);

	* A function used when you use take a power-up. Will increase the players size,
	* set his height to the double.
	*/
	void increase_size(int, int);


	/*
	* FUNCTION: jump();
	*
	* If player is on the ground/standing on a block,, he will be able to jump.
	* This means his y-position will be set aswell as his y-velocity. 
	*/
	void jump();

	/*
	* FUNCTION: run();
	*
	* Changes the value of the possible max_speed. This allows the player to
	* move faster than without run. 
	*/
	void run();


	/*
	* FUNCTION: interact_with(std::shared_ptr<Map_object> my_char) override;
	*
	* Depending on what type of object the player is colliding with different things will happen.
	* 
	*/
	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	* FUNCTION: interact() override;
	*
	*/
	void interact() override;
};


