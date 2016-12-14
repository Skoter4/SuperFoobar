/*
* FILENAME:     Generator.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
* DESCRIPTION:
* This is the declaration file for Generator. Generator is a subclass to Block.
* It inheritates the functionality of block and map_object.
*/

#pragma once
#include "../Block-filer/Block.h"
#include "../Interactable-filer/Interactable.h"
#include "../Character filer/Foobar/Foobar.h"

class Generator
	: public Block
{
public:

	/*
	*	CONSTRUCTOR: Generator(int, int, int, int, std::shared_ptr<Interactable>)
	*
	*	Constructor used to create Generator objects.
	*	Uses the Block constructor, has an input for which interactable it shall generate.
	*/

	Generator(int, int, int, int, std::shared_ptr<Interactable>);

	/*
	*	DESTRUCTOR: ~Generator()
	*
	*	A defualt destructor for Generator objects.
	*/

	~Generator() = default;

	/*
	*	FUNCTION: interact() override
	*
	*  This function is used in interact_with when a
	*  collsion has occured.
	*/

	void interact() override;

	/*
	*	FUNCTION: generate()
	*
	*
	*
	*/

	std::shared_ptr<Interactable> const & generate();

	/*
	*	FUNCTION: interact_with(std::shared_ptr<Map_object> my_char) override
	*
	*	If a collision occurs, this function is executed. Depending on what type the other object
	*	is, it runs different functions.
	*/

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	/*
	*	FUNCTION: flip_deactivated()
	*
	*	This function flips the value of the variable deactivated.
	*	Is used when the generate function is executed.
	*/

	void flip_deactivated();

	/*
	*	FUNCTION: flip_generating()
	*
	*	This function flips the value of the variable generating.
	*	Is used when the object generates its interactable.
	*/

	void flip_generating();

	/*
	*	FUNCTION: is_generating()
	*
	*	This function returns the value of the variable generating.
	*	Is used to know if the generator-object shall generate its interactable or not.
	*/

	bool is_generating();

	/*
	*	FUNCTION: is_deactivated()
	*
	*	This function returns the value of the variable deactivated.
	*	Is used to know if it has been interacted with it or not.
	*/

	bool is_deactivated();

	/*
	*	FUNCTION: type_str() override
	*
	*	This function returns a string which says "Generaor".
	*	Is used to define that a object is of type Generator.
	*/

	std::string type_str() override;

private:

	bool deactivated{ false };
	bool generating{ false };

	std::shared_ptr<Interactable> reward;

};
