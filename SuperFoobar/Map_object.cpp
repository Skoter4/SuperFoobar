#include "Map_object.h"


int Map_object::get_height()
{
	return cluster->get_height();
}

int Map_object::get_width()
{
	return cluster->get_height();
}

void Map_object::set_height(int height)
{
	cluster->set_height(height);
}

void Map_object::set_width(int width)
{
	cluster->set_height(width);
}

int Map_object::get_x_pos()
{
	return cluster->get_x();
}

int Map_object::get_y_pos()
{
	return cluster->get_x();
}

void Map_object::set_x(int x)
{
	cluster->set_x(x);
}

void Map_object::set_y(int y)
{
	cluster->set_y(y);
}

void Map_object::set_desx_pos(int x)
{
	cluster->set_des_x(x);
}

void Map_object::set_desy_pos(int y)
{
	cluster->set_des_y(y);
}


Map_object::Map_object(int x, int y, int length, int width)
	:cluster{ new Cluster(x, y, length, width) }
{}

std::shared_ptr<Cluster> Map_object::get_cluster()
{
	return cluster;
}
/*
sf::Texture get_texture()
{
	return this->texture_ptr;
}

sf::Sprite get_sprite()
{
	return this->sprite_ptr;
}*/