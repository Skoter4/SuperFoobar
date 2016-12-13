#include "Character.h"
//#include "../Collision/Cluster.h"


Character::Character(int x_pos, int y_pos, int height, int width)
	: Map_object(x_pos, y_pos, height, width)
{
	set_old_x(x_pos);
	set_old_y(y_pos);
}


void Character::move_x(int x_speed) 

{
	if (this->get_desx_pos() <= 0 || this->get_old_x() <= 0 || this->get_x_pos() <= 0)
	{
		if (this->type_str() == "foobar")
		{
			this->set_x_velocity(0);
			this->set_desx_pos(0);
			this->set_old_x(0);
		}
		else
			if (this->type_str() == "projectile")
			{
				this->flip_dead();
			}
			else
			{
				this->flip_x_velocity();
				this->set_x(2);
			}
	}
	else if (this->get_desx_pos() > 13020 || this->get_old_x() > 13020 || this->get_x_pos() > 13020)
	{
		if (this->type_str() == "foobar")
		{
			this->set_x_velocity(13020);
			this->set_desx_pos(13020);
			this->set_old_x(13020);
		}
		else {
			this->flip_dead();
			this->set_y_velocity(0);
			this->set_x_velocity(0);
		}
	}
	else
	{
		this->set_desx_pos(x_speed + cluster->get_x());
		this->set_old_x(this->get_x_pos());
	}
}

void Character::move_y(int y_speed)
{

	if (this->get_y_pos() + this->get_height() > 770)
	{
		if (this->type_str() == "enemy_2")
		{
			this->flip_x_velocity();
			this->set_x(this->get_old_x() + 20);
			this->set_y(this->get_old_y() - 10);
		}
	}
	if(this->get_y_pos() >840)
	{
		this->flip_dead();
		this->set_y_velocity(0);
		this->set_x_velocity(0);
	}
	else
	{
		this->set_old_y(this->get_y_pos());
		this->set_desy_pos(y_speed + cluster->get_y());
	}
}


void Character::die()
{
	if (this->get_lifes() == 1)
	{
		this->flip_dead();
	}
	else
	{
		this->set_lifes(1);
		this->set_height(50);
	}
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
	if (new_x_velocity == 0)
	{
		this->velocity.x_velocity = 0;
	}
	else
		if (new_x_velocity < 0)
		{
			while (this->get_x_velocity() > -this->get_max_speed_x())
			{
				this->velocity.x_velocity += new_x_velocity;
				break;
			}
		}
		else
		while (this->get_x_velocity() < this->get_max_speed_x())
		{
			this->velocity.x_velocity += new_x_velocity;
			break;
		}
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



void Character::flip_x_velocity()
{
	this->velocity.x_velocity = -this->velocity.x_velocity;
}


void Character::set_max_speed_x(int new_max_speed_x)
{
	this->max_speed_x = new_max_speed_x;
}

int Character::get_max_speed_x()
{
	return this->max_speed_x;
}

void Character::set_max_speed_y(int new_max_speed_y)
{
	this->max_speed_y = new_max_speed_y;
}

int Character::get_max_speed_y()
{
	return this->max_speed_y;
}

bool Character::get_on_ground()
{
	return this->on_ground;
}

void Character::flip_on_ground()
{
	if (this->on_ground)
	{
		this->on_ground = !this->on_ground;
	}
	else
	{
		this->on_ground = !this->on_ground;
		this->set_y_velocity(0);
	}
}

