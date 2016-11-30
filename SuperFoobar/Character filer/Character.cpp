#include "Character.h"



Character::Character()
{

}

int Character::get_x_pos() 
{
	return x_pos;
}

int Character::get_y_pos() 
{
	return y_pos;
}

void Character::move_x(int x_speed) 
{
	set_x_pos(x_speed);
}

void Character::move_y(int y_speed)
{
	set_y_pos(y_speed);
}

void Character::set_x_pos(int new_pos)
{
	x_pos += new_pos;
}

void Character::set_y_pos(int new_pos)
{
	y_pos += new_pos;
}

void Character::die()
{
	
}
