/*
* FILENAME:      Finish_line.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Finish line class, subclass to Interactable.
*/

#pragma once
#include "Interactable.h"

class Finish_line : public Interactable
{
public:

	/*
	* CONSTRUCTOR: Finish_line(int, int, int, int);
	* Initialize a Finish_line object with x and y positions as well as height and width
	* using the constructor from Interactable
	*/

	Finish_line(int, int, int, int);

	~Finish_line() = default;

	/*
	* FUNCTION: void interact_with(std::shared_ptr<Map_object> my_char) override;
	* Takes a map_object and checks if Foobar have collided with a finish line, if so interact() is executed
	*/

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	* FUNCTION: void interact() override;
	* Executes flip_dead() which removes it from the game
	*/

	void interact() override;

	/*
	* FUNCTION: std::string type_str() override;
	* Returns a string to indentify a finish line object
	*/

	std::string type_str() override;
};
