/*
* FILENAME:       Power_up.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Power up class, subclass to Interactable.
*/

#pragma once
#include "Interactable.h"

class Power_up : public Interactable
{
public:

	/*
	* CONSTRUCTOR: Power_up(int, int, int, int);
	* Initialize a Power_up object with x and y positions as well as height and width
	* using the constructor from Interactable
	*/

	Power_up(int, int, int, int);

	~Power_up() = default;

	/*
	* FUNCTION: void set_type(std::string);
	* Sets the string that characterizes the type of power up
	*/

	void set_type(std::string);

	/*
	* FUNCTION: void interact_with(std::shared_ptr<Map_object> my_char) override;
	* Takes a map_object and checks if Foobar have collided with a power up, if so interact() is executed
	*/

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	* FUNCTION: void interact() override;
	* Executes flip_dead() which removes it from the game
	*/

	void interact() override;

	/*
	* FUNCTION: std::string type_str() override;
	* Returns the string that characterizes the type of power up
	*/

	std::string type_str() override;

private:
	std::string type{ "powerup" };
};
