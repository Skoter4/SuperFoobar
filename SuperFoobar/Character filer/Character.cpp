#include "Character.h"
//#include "../Collision/Cluster.h"



Character::Character(int x_pos, int y_pos,int height, int width) 
	: Map_object(x_pos, y_pos, height, width)
{}


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

//<<<<<<< HEAD
//=======
void Character::set_width(int new_width)
{
	width = new_width;
}

std::shared_ptr<Cluster> Character::get_cluster()
{
	return cluster;
}

void Character::set_height(int new_height)
{
	height = new_height;
}

void Character::flip_dead()
{
	dead = !dead;
}

//>>>>>>> refs/remotes/origin/master
void Character::die()
{
	if (invulnerable = false)
	{
		this->flip_dead();
	}
}

void Character::flip_invulnerable()
{
	invulnerable = !invulnerable;
}
