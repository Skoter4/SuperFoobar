/*
* FILENAME:       Foobar.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
*/

#include "Foobar.h"
#include <memory>

using namespace std;


Foobar::Foobar(int x_pos, int y_pos, int width, int height)
	: Character(x_pos, y_pos, width, height)
{
	this->set_x_velocity(0);
	this->set_y_velocity(0);
}


std::string Foobar::type_str()
{
	return "foobar";
}

void Foobar::power_up(shared_ptr<Power_up> power_up)
{
	if (power_up->type_str() == "power_up_shroom")
	{
		this->set_lifes(2);
		this->increase_size(50, 100);
		this->set_y(this->get_y_pos() - 52);
		this->set_desy_pos(this->get_y_pos() - 52);
		this->set_old_y(this->get_y_pos() - 52);
	}
}

void Foobar::increase_size(int new_width, int new_height)
{
	this->set_width(new_width);
	this->set_height(new_height);
}


void Foobar::jump()
{
	if (this->get_on_ground() && this->get_y_velocity() == 0)
	{
		this->set_y_velocity(-25);
		this->flip_on_ground();
	}
}


void Foobar::interact_with(std::shared_ptr<Map_object> map_object)
{
	//If player collides with a projectile the player itself will die, unless it collides with player from above. 
	//Otherwise foobar will destruct object that are breakables/generators and only collide with non-breakables.
	if (map_object->type_str() == "projectile") {
		this->die();
		map_object->interact();
	}
	else if (map_object->type_str() == "coin") 
	{
		map_object->interact();
	}
	else if ((map_object->type_str() == "enemy_1 ") || (map_object->type_str() == "enemy_2") || (map_object->type_str() == "enemy_3"))
	{
		if (this->get_height() == 100)
		{
			if ((this->get_old_y() + 50 < map_object->get_y_pos()))
			{
				map_object->flip_dead();
			}
			else
			{
				this->die();
			}
		}
		else if ((this->get_old_y() < map_object->get_y_pos()))
		{
			map_object->flip_dead();
		}
		else
		{
			this->die();
		}
	}
}

void Foobar::interact()
{
}

void Foobar::run()
{
	this->set_max_speed_x(10);
}

