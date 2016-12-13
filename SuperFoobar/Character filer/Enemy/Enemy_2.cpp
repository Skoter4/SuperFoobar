#include "Enemy_2.h"


Enemy_2::Enemy_2(int x, int y, int width, int height)
	: Character(x, y, width, height) 
{}


std::string Enemy_2::type_str()
{
	return "enemy_2";
}

void Enemy_2::interact_with(std::shared_ptr<Map_object> map_object)
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

void Enemy_2::interact()
{
}