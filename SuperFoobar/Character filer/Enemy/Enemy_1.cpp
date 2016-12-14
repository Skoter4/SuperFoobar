/*
* FILENAME:     Enemy_1.cpp
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*/


#pragma once
#include "Enemy_1.h"
#include "../Projectile.h"
#include "../Make_track.h"

Enemy_1::Enemy_1(int x, int y, int width, int height)
	: Character(x, y, width, height) 
{
}



std::shared_ptr<Character> Enemy_1::fire_projectile()
{
	//Runs the Make_track function make_projectile, which creates a Projectile-object
	return  make_projectile(get_x_pos(), get_y_pos());
}



std::string Enemy_1::type_str()
{
	return "enemy_1";
}

void Enemy_1::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
	{
		if (map_object->get_height() > 50)
		{
			// If Foobar is huge (have interacted with a mushroom)
			if ((map_object->get_old_y() + 50 < this->get_y_pos()))
			{
				// If Foobar is above the enemy_1
				this->flip_dead();

			}
			else
			{
				std::dynamic_pointer_cast<Foobar> (map_object)->die();
				this->flip_dead();

			}
		}
		else if ((map_object->get_old_y() < this->get_y_pos()))
		{
			this->flip_dead();
		}
		else
		{
			std::dynamic_pointer_cast<Foobar> (map_object)->die();
		}
	}
	else if (map_object->type_str() == "projectile") {
		this->flip_dead();
		map_object->flip_dead();
	}
}

void Enemy_1::interact()
{
}

bool Enemy_1::ready_to_fire()
{
	return this->to_fire;
}

void Enemy_1::flip_ready()
{
	to_fire = !to_fire;
}

int Enemy_1::get_prev_time()
{
	return prev_time;
}

void Enemy_1::set_prev_time(int time)
{
	prev_time = time;
}
