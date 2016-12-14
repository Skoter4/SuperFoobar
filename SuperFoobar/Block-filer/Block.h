/*
* FILENAME:       Block.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
* This is the declaration-file for the class Block. Block is a virtual base-class for the different type of blocks defined 
* further on and also a subclass of Map_object class. The functions declared inside this class is common for the different subclasses.
* The class is necessary to differentiate between the two different Map_object classes, Character and Block. 
* 
*/

#pragma once
#include <memory>
#include "../Collision/Cluster.h"
#include "../Map_object.h"


class Block :public Map_object{
public:

	/*
	* DESTRUCTOR: ~Block() = default;
	*
	* Destruct the objects when necessary and uses the compiler-destructor. 
	*/
	~Block() = default;

	/*
	* CONSTRUCTOR: Block() = defualt;
	*
	* Default-constructor, never used inside the game, but declared and defined
	* using the compiler-constructor. 
	*/
	Block() = default;

protected:

	/*
	* CONSTRUCTOR: Block(int, int, int, int);
	*
	* Constrctor used to create initialized Block-objects, given values on x-/y-positions
	* and size. 
	*/
	Block(int, int, int, int);
};
