#include "Character.h"
//#include "../Collision/Cluster.h"


Character::Character(int x_pos, int y_pos,int height, int width) 
	: Map_object(x_pos, y_pos, height, width)
{}


void Character::move_x(int x_speed) 

{
	set_desx_pos(x_speed + cluster->get_x());
}

void Character::move_y(int y_speed)
{
	set_desy_pos(y_speed + cluster->get_x());
}


void Character::die()
{
	if (invulnerable == false && this->get_lifes() == 1)
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



void Character::set_velocity(int new_x_velocity, int new_y_velocity)
{
	this->set_x_velocity(new_x_velocity);
	this->set_y_velocity(new_y_velocity);
}

void Character::set_x_velocity(int new_x_velocity)
{
	this->velocity.x_velocity = new_x_velocity;
}

void Character::set_y_velocity(int new_y_velocity)
{
	this->velocity.y_velocity = new_y_velocity;
}

int Character::get_x_velocity()
{
	return this->velocity.x_velocity;
}

int Character::get_y_velocity()
{
	return this->velocity.y_velocity;
}

int Character::get_gravity()
{
	return this->gravity;
}

void Character::set_gravity(int new_gravity)
{
	gravity = new_gravity;
}
