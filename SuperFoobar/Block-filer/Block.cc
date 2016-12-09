//#include "../Collision/Cluster.h"
#include "Block.h"

using namespace std;

Block::Block(int x, int y, int length, int width)
	:Map_object(x, y, length, width) 
{}
/*
int Block::get_x_pos()
{
	return this->cluster->get_x();
}

int Block::get_y_pos()
{
	return this->cluster->get_y();
}
void Block::set_x_pos(int new_x)
{
	this->cluster->set_des_x(new_x);
}

void Block::set_y_pos(int new_y)
{
	this->cluster->set_des_y(new_y);
}*/

int Block::area()
{
	return this->cluster->get_height()*cluster->get_width();
}

void Block::flip_dead()
{
	this->dead = !(this->dead);
}

bool Block::get_dead()
{
	return this->dead;
}

bool Block::get_active()
{
	return this->active;
}

void Block::flip_active()
{
	this->active = !active;
}