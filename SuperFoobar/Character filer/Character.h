/*
* FILENAME:       Character.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
* This file contains the declarations for the class Character. The class is a subclass to Map_object and a 
* baseclass for several types of Characters. It declares the functionality that makes the object a character.
* And it holds the members making movement possible. 
*
*/

#pragma once
#include "../Map_object.h"
#include <memory>
#include <utility>


class Character : public Map_object{
public:

	/*
	* CONSTRUCTOR: Character();
	*
	* Default constructor
	*/
	Character() = default;

	/*
	* DESTRUCTOR: ~Character();
	*
	* Destruct the object with default-destructor when necessary.
	*/
	~Character() = default;

	/*
	* FUNCTION: move_x(int);
	*
	* Move the object the lenght of the input. 
	* (It will change its x-position with the input-value). Depending on what type of object,
	* and if the desired x-position is below or above a fixed value it will not be able to move.
	*/
	void move_x(int);

	/*
	* FUNCTION: move_y(int);
	*
	* Move the object upwards/downwards the lenght of the input.
	* (It will change its current y-position with input-value). If a object is moving outside of the window,
	* it will be set as dead and disappear from the list to draw. 
	*/
	void move_y(int);

	/*
	* FUNCTION: die();
	*
	* This function will decrease lifes of the character. If #lifes = 1 it will also set 
	* his member "dead" = true. 
	*/
	void die();

	/*
	* FUNCTION: flip_active();
	*
	* 
	*/
	void flip_active();
	/*
	* FUNCTION: set_lifes(int);
	*
	* Increases the #lifes to the input-value. 
	*/
	void set_lifes(int);

	/*
	* FUNCTION: get_lifes();
	*
	* Returns the number of lifes. 
	*/
	int get_lifes();

	/*
	* FUNCTION: set_x_velocity(int);
	*
	* Changes speed of the object in x-axis. 
	*/
	void set_x_velocity(int);

	/*
	* FUNCTION: set_y_velocity(int);
	*
	* Changes speed of the object in y-axis. 
	*/
	void set_y_velocity(int);

	/*
	* FUNCTION: get_x_velocity(int);
	*
	* Returns the current x-speed when calling the function. 
	*/
	int get_x_velocity();

	/*
	* FUNCTION: get_y_velocity(int);
	*
	* Returns the current y-speed when calling the function. 
	*/
	int get_y_velocity();	

	/*
	* FUNCTION: get_gravity();
	*
	* Returns the gravity when calling this function.
	*/
	int get_gravity();

	/*
	* FUNCTION: set_gravity(int);
	*
	* Sets the gravity to the new value.
	*/
	void set_gravity(int);
	
	/*
	* FUNCTION: flip_x_velocity();
	*
	* Changes the direction of the velocity in x-axis. 
	*/
	void flip_x_velocity();

	/*
	* FUNCTION: set_max_speed_x(int);
	*
	* Makes it possible to change the max_speed of the object.
	*/
	void set_max_speed_x(int);

	/*
	* FUNCTION: get_max_speed_x(int);
	*
	* Returns the current max_speed-value.
	*/
	int get_max_speed_x();

	/*
	* FUNCTION: set_max_speed_x(int);
	*
	* Makes it possible to change the max_speed of the object.
	*/
	void set_max_speed_y(int);

	/*
	* FUNCTION: get_max_speed_x(int);
	*
	* Returns the current max_speed-value.
	*/
	int get_max_speed_y();

	/*
	* FUNCTION: get_on_ground();
	*
	* Returns true/false depending on the objects position is on a block or in the air.
	*/
	bool get_on_ground();

	/*
	* FUNCTION: flip_on_ground();
	*
	* Changes true/false depending on the objects position is on a block or in the air.
	*/
	void flip_on_ground();

//DATAMEMBERS

protected:

	/*
	* CONSTRUCTOR: Character(int, int, int, int);
	*
	* Used to create an initialized Character, with input x-pos, y-pos and size. 
	*/
	Character(int, int, int, int);

	int lifes{ 1 };
	bool active{ true };
	
	int gravity{ 1 };

	int max_speed_x{ 5 };
	int max_speed_y{ 5 };

	bool on_ground{ false };

	/* A struct to control the velocity
	*/
	struct Velocity {
		int x_velocity{3};
		int y_velocity{3};
	};

	Velocity velocity{};

};




