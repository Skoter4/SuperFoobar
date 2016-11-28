#include "Character.h"



Character::Character()
{

}

float Character::get_x_pos() 
{
	return x_pos;
}

float Character::get_y_pos() 
{
	return y_pos;
}

void Character::move_x(float x_speed) 
{
	set_x_pos(x_speed);
}

void Character::move_y(float y_speed)
{
	set_y_pos(y_speed);
}

void Character::set_x_pos(float new_pos)
{
	x_pos += new_pos;
}

void Character::set_y_pos(float new_pos)
{
	y_pos += new_pos;
}

void Character::die()
{
	
}
