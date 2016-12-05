#include "Character.h"
//#include "../Collision/Cluster.h"


Character::Character(int x_pos, int y_pos,int height, int width) 
	: Map_object(x_pos, y_pos, height, width)
{}


void Character::move_x(int x_speed) 

{
	set_x_pos(x_speed);
}

void Character::move_y(int y_speed)
{
	set_y_pos(y_speed);
}


void Character::flip_dead()
{
	dead = !dead;
}

void Character::die()
{
	if (invulnerable = false && this->get_lifes() == 1)
	{
		this->flip_dead();
	}
	else
	{
		this->set_lifes(1);
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

void Character::set_lifes(int new_amount_lifes)
{
	this->lifes = new_amount_lifes;
}

int Character::get_lifes()
{
	return this->lifes;
}