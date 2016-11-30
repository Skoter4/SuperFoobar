#include "Block.h"


using namespace std;

Block::Block(float x, float y, float height, float width)
	:cluster{ new Cluster(x, y, height, width) }
{}

float Block::get_x_pos()
{
	return this->cluster->get_x();
}

float Block::get_y_pos()
{
	return this->cluster->get_y();
}
void Block::set_x_pos(float new_x)
{
	this->cluster->set_des_x(new_x);
}

void Block::set_y_pos(float new_y)
{
	this->cluster->set_des_y(new_y);
}

float Block::area()
{
	return this->cluster->get_height()*cluster->get_width();
}

void Block::flip_dead()
{
	this->dead = !(this->dead);
}
