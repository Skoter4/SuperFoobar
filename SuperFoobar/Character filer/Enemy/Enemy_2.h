/*
* FILENAME:       Enemy_2.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
* This file contains the declaration of the class Enemy_2, it is one type of 3 enemies, and is a subclass to Character, so it inheritates
* the functionality of Character. 
* 
*/

#pragma once
#include "../Character filer/Foobar/Foobar.h"
class Enemy_2 :
	public Character
{
public:
	/*
	* CONSTRUCTOR: Enemy_2() = defualt;
	*
	* Constructor, to create an enemy of type 2. 
	*/
	Enemy_2(int x, int y, int width, int height);

	/*
	* DESTRUCTOR: ~Enemy_2() = defualt;
	*
	* Default-destructor, used when necessary to destruct the object. Used by the compiler. 
	*/
	~Enemy_2() = default;

	/*
	* FUNCTION: type_Str() override;
	*
	* Returns a string that is specific for this type of object. 
	* Used to identify the specific object.
	*/
	std::string type_str() override;

	/*
	* FUNCTION: interact_with(std::shared_ptr<Map_object> my_char);
	*
	* If a collsision occurs, this function is executed. Depending on what type of other object 
	* the input is, it runs functions accordingly. 
	*/
	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	* FUNCTION: interact() override;
	*
	* Is used in some part of the function interact_with(). It will change the member dead of the object
	* to true. 
	*/
	void interact() override;
};

