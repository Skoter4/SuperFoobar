/*
* FILENAME:     Breakable.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
* DESCRIPTION:
* This is the declaration file for Breakable. Breakable is a subclass to Block.
* It inheritates the functionality of block and map_object.
*
*/

#pragma once
#include "Block.h"
#include "../Character filer/Enemy/Enemy_2.h"
#include "../Character filer/Enemy/Enemy_3.h"
class Breakable :public Block
{
 public:

/*
 *	CONSTRUCTOR: Breakable(int, int, int, int)
 *
 *	Constructor used to create breakable-block objects.
 *  Uses the Block constructor.
 */

  Breakable(int, int, int, int);

  /*
  *	FUNCTION: interact_with(std::shared_ptr<Map_object> my_char) override
  *
  *	If a collision occurs, this function is executed. Depending on what type the other object
  * is, it runs different functions.
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
  *	FUNCTION: type_str() override
  *
  * This function returns a string which says "breakable".
  * Is used to define that a object is of type breakable.
  */

  std::string type_str() override;

  /*
  *	DESTRUCTOR: ~Breakable()
  *
  * A defualt destructor for breakable objects.
  */

  ~Breakable() = default;
};

