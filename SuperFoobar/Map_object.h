/*
* FILENAME:       Map_object.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
* This file declares the base-class Map_object which declares every function that are common for
* all the subclasses. It stores the input-values of the objects when creating them. 
*
*/

#pragma once
#include <memory>
#include "../Collision/Cluster.h"
#include <string>

/*
 * Defining a namespace to be able to have a member sf::Sprite 
 * without including a SFML-class. 
 */
namespace sf

{
	class Sprite;
};

//Getting access to the above defined namespace.
class sf::Sprite;

class Map_object {
public:


	/*
	* FUNCTION: get_cluster();
	*
	* Returns the cluster-object that the Cluster-ptr is pointing at. 
	*/
	std::shared_ptr<Cluster> get_cluster();

	/*
	* FUNCTION: virtual type_Str() = 0;
	*
	* A virtual function making this class pure virtual. 
	* Returns a string that is specific for this type of object.
	* Used to identify the specific object.
	* This function is overwritten in every subclass that is creatable. 
	*/
	virtual std::string type_str() = 0;

	/*
	* FUNCTION: interact() override;
	*
	*/
	virtual void interact() = 0;

	/*
	* FUNCTION: interact_with(std::shared_ptr<Map_object>);
	*
	* A function that differs between the subclasses, is used when collision i detected
	* and proceeds the executing accordingly after the input. 
	*/
	virtual void interact_with(std::shared_ptr<Map_object>) = 0;

	/*
	* FUNCTION: get_height();
	*
	* Returns the height of the current object.
	*/
	int get_height();

	/*
	* FUNCTION: get_width();
	*
	* Returns the width of the current object.
	*/
	int get_width();

	/*
	* FUNCTION: set_height(int);
	*
	* Set the height to the new value int. 
	*/
	void set_height(int);

	/*
	* FUNCTION: set_width(int);
	*
	* Set the width to the new value int. 
	*/
	void set_width(int);

	/*
	* FUNCTION: is_dead();
	*
	* Returns the objects status on the memeber dead. 
	*/
	bool is_dead();

	/*
	* FUNCTION: flip_dead();
	*
	* Set the status of the member dead.
	*/
	void flip_dead();

	/*
	* FUNCTION: get_x_pos();
	*
	* Returns the x-position.
	*/
	int get_x_pos();

	/*
	* FUNCTION: get_y_pos();
	*
	* Returns the y-position.
	*/
	int get_y_pos();

	/*
	* FUNCTION: set_x();
	*
	* Changes the x-position.
	*/
	void set_x(int);

	/*
	* FUNCTION: set_y();
	*
	* Changes the y-position.
	*/
	void set_y(int);

	/*
	* FUNCTION: get_desx_pos();
	*
	* When a character moves he wants to move to a desired x-pos. 
	* This function returns that desired x.
	*/
	int get_desx_pos();

	/*
	* FUNCTION: get_desy_pos();
	*
	* When a character moves he wants to move to a desired y-pos.
	* This function returns that desired y.
	*/
	int get_desy_pos();

	/*
	* FUNCTION: set_desx_pos();
	*
	* When a character moves he wants to move to a desired x-pos.
	* This function set this to the desired x-pos, so it is possible to check the collision
	* at that desired position.
	*/
	void set_desx_pos(int);

	/*
	* FUNCTION:sget_desy_pos();
	*
	* When a character moves he wants to move to a desired x-pos.
	* This function set this to the desired y-pos, so it is possible to check the collision
	* at that desired position.
	*/
	void set_desy_pos(int);

	/*
	* FUNCTION: get_old_x();
	*
	* Returns the old_x, which is the x-position the object have before it 
	* move to desired-x. 
	*/
	int get_old_y();

	/*
	* FUNCTION: get_old_y();
	*
	* Returns the old_y, which is the x-position the object have before it
	* move to desired-y.
	*/
	int get_old_x();

	/*
	* FUNCTION: set_old_x();
	*
	* When the player has moved and before next collision occurs, old_x will
	* be set to be the x-pos before the next move happen.
	*/
	void set_old_x(int);

	/*
	* FUNCTION: set_old_y();
	*
	* When the player has moved and before next collision occurs, old_y will
	* be set to be the y-pos before the next move happen.
	*/
	void set_old_y(int);


	/*
	* FUNCTION: get_sprite();
	*
	* Returns the sprite belonging to the object. 
	*/
	std::shared_ptr<sf::Sprite> get_sprite();

	/*
	* FUNCTION: setSprite();
	*
	* Set the sprite of the member sprite to be the input-sprite.
	*/
	void setSprite(std::shared_ptr<sf::Sprite>);

protected:

	//Member-declarations
	bool dead{ false };
	std::shared_ptr<sf::Sprite> object_sprite;

	/*
	 * These two members are used in the collision-detection. 
	 * These will be set to be x-pos before we change desired-x. 
	 * With the help of the old-positions we can see from which side the player, for instance,
	 * came from before the collision-detection. 
	 */
	int old_x{};
	int old_y{};

	Map_object(int, int, int, int);

	//Hold the information of the current position and size of the object. 
	std::shared_ptr<Cluster> cluster;
};