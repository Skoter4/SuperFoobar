/*
* FILENAME:       Enemy_3.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
*/

#include "Enemy_3.h"

Enemy_3::Enemy_3(int x, int y, int width, int height)
	: Character(x, y, width, height) {}


std::string Enemy_3::type_str()
{
	return "enemy_3";
}

void Enemy_3::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
	{
		if (map_object->get_height() > 50)
		{
			if ((map_object->get_old_y() + 50 < this->get_y_pos()))
			{
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
		this->interact();
		map_object->interact();
	}
}

void Enemy_3::interact()
{
	this->flip_dead();
}