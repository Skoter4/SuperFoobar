/*
* FILENAME:     Non_breakable.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
* DESCRIPTION:
* This is the declaration file for Non-breakable. Non_breakable is a subclass to Block.
* It inheritates the functionality of block and map_object.
*/

#pragma once
#include "../Block-filer/Block.h"
#include "../Character filer/Enemy/Enemy_2.h"
#include "../Character filer/Enemy/Enemy_3.h"
#include "../Character filer/Foobar/Foobar.h"


class Non_breakable
	: public Block
{
public:
	/*
	*	CONSTRUCTOR: Non_breakable(int, int, int, int)
	*
	*	Constructor used to create non_breakable-block objects.
	*  Uses the Block constructor.
	*/

	Non_breakable(int, int, int, int);

	/*
	*	DESTRUCTOR: ~Non_breakable()
	*
	*	A defualt destructor for Non_breakable objects.
	*/

	~Non_breakable() = default;

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
	*	This function returns a string which says "non-breakable".
	*	Is used to define that a object is of type Non_breakable.
	*/

	std::string type_str() override;

	void interact() override;
};
