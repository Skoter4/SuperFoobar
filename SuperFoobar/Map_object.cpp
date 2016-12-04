#include "Map_object.h"


Map_object::Map_object(int x, int y, int length, int width)
	:cluster{ new Cluster(x, y, length, width) }
{}

std::shared_ptr<Cluster> Map_object::get_cluster()
{
	return cluster;
}