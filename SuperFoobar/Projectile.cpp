/*
* FILENAME:     Projectile.cpp
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*
*/

#include "Projectile.h"

Projectile::Projectile(int x_pos, int y_pos, int height, int width)
	: Character(x_pos, y_pos, height, width)
{
	this->flip_x_velocity();
}

void Projectile::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar"){
		if (map_object->get_height() > 50)
		{
			//if Foobar is huge ( have interacted with a mushroom)
			if ((map_object->get_old_y() + 50 < this->get_y_pos()))
			{
				//Foobar is above the projectile and destroys it
				this->flip_dead();
			}
			else
			{
				//Foobar gets hit by the Projectile and loses 1 life, the projectle is destroyed
				std::dynamic_pointer_cast<Foobar> (map_object)->die();
				this->flip_dead();

			}
		}
		else if ((map_object->get_old_y() < this->get_y_pos()))
		{
			//Foobar is above the projectile and destroys it
			this->flip_dead();
		}
		else
		{
			//Foobar gets hit by the Projectile and dies, the projectle is destroyed
			std::dynamic_pointer_cast<Foobar> (map_object)->die();
		}
	}
}

void Projectile::interact()
{
}


std::string Projectile::type_str()
{
	return "projectile";
}

