#include "Character.h"

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

void Character::set_width(float new_width)
{
	width = new_width;
}

void Character::set_height(float new_height)
{
	height = new_height;
}

void Character::flip_dead()
{
	dead = !dead;
}

void Character::die()
{
	if (invulnerable = false && this->get_lifes() == 1.0f)
	{
		this->flip_dead;
	}
	else
	{
		this->set_lifes(1.0f);
	}
}

void Character::flip_invulnerable()
{
	invulnerable = !invulnerable;
}

void Character::flip_active()
{
	active = !active;
}

void Character::set_lifes(float new_amount_lifes)
{
	this->lifes = new_amount_lifes;
}

float Character::get_lifes()
{
	return this->lifes;
}