/*
* FILENAME:       Map_object.cpp
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
*/


#include "Map_object.h"


int Map_object::get_height()
{
	return cluster->get_height();
}

int Map_object::get_width()
{
	return cluster->get_width();
}

void Map_object::set_height(int height)
{
	cluster->set_height(height);
}

void Map_object::set_width(int width)
{
	cluster->set_width(width);
}

int Map_object::get_x_pos()
{
	return cluster->get_x();
}

int Map_object::get_y_pos()
{
	return cluster->get_y();
}

void Map_object::set_x(int x)
{
	cluster->set_x(x);
}

void Map_object::set_y(int y)
{
	cluster->set_y(y);
}

int Map_object::get_desx_pos()
{
	return cluster->get_des_x();
}

int Map_object::get_desy_pos()
{
	return cluster->get_des_y();
}

void Map_object::set_desx_pos(int x)
{
	cluster->set_des_x(x);
}

void Map_object::set_desy_pos(int y)
{
	cluster->set_des_y(y);
}

int Map_object::get_old_x()
{
	return this->old_x;
}

int Map_object::get_old_y()
{
	return this->old_y;
}


void Map_object::set_old_x(int new_old_x)
{
	this->old_x = new_old_x;
}

void Map_object::set_old_y(int new_old_y)
{
	this->old_y = new_old_y;
}

Map_object::Map_object(int x, int y, int length, int width)
	:cluster{ new Cluster(x, y, length, width) }
{}

std::shared_ptr<Cluster> Map_object::get_cluster()
{
	return cluster;
}


std::shared_ptr<sf::Sprite> Map_object::get_sprite()
{
	return this->object_sprite;
}

void Map_object::setSprite(std::shared_ptr<sf::Sprite> new_sprite)
{
	if (new_sprite != nullptr)
	{
		object_sprite = new_sprite;
	}
}

void Map_object::flip_dead()
{
	if (!dead)
	{
		this->dead = !(this->dead);
	}
}

bool Map_object::is_dead()
{
	return this->dead;
}

