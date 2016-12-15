/*
* FILENAME:      Coin.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Coin class, subclass to Interactable.
*/

#pragma once
#include <string>
#include "Interactable.h"

class Coin : public Interactable
{
public:

	/*
	* CONSTRUCTOR: Coin(int, int, int, int);
	* Initialize a Coin object with x and y positions as well as height and width
	* using the constructor from Interactable
	*/

	Coin(int, int, int, int);

	~Coin() = default;

	/*
	* FUNCTION: void interact_with(std::shared_ptr<Map_object> my_char) override;
	* When a collision occurs with a Coin object this function checks if the other 
	* object type is a Foobar object. If so, it executes interact()
	*/

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	* FUNCTION: void interact() override;
	* Executes flip_dead() which removes the Coin object from the game
	*/

	void interact() override;

	/*
	* FUNCTION: std::string type_str() override;
	* Returns a string which is used to indentify that a specific object is of type Coin
	*/

	std::string type_str() override;
};
