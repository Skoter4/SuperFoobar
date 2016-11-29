#include "Block.h"


using namespace std;

Block::Block(float x, float y, float length, float width)
	:cluster{ new Cluster(x, y, length, width) }
{}

float Block::get_x_pos()
{
	return cluster->get_x();
}

float Block::get_y_pos()
{
	return cluster->get_y();
}
void Block::set_x_pos(float new_x)
{
	cluster->set_des_x(new_x);
}

void Block::set_y_pos(float new_y)
{
	cluster->set_des_y(new_y);
}

float Block::area()
{
	return cluster->get_height()*cluster->get_width();
}

void Block::flip_dead()
{
	dead = !dead;
}
