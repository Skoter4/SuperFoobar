//#include "../Collision/Cluster.h"
#include "Block.h"

using namespace std;

Block::Block(int x, int y, int length, int width)
	:Map_object(x, y, length, width) 
{}

int Block::area()
{
	return this->cluster->get_height()*cluster->get_width();
}


bool Block::get_active()
{
	return this->active;
}

void Block::flip_active()
{
	this->active = !active;
}