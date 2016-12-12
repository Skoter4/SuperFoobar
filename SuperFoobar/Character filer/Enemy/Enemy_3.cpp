#include "Enemy_3.h"

Enemy_3::Enemy_3(int x, int y, int width, int height)
	: Character(x, y, width, height) {}

Enemy_3::~Enemy_3()
{
}
void Enemy_3::poly()
{
}

std::string Enemy_3::type_str()
{
	return "enemy_3";
}

bool Enemy_3::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
	{
		if ((map_object->get_old_y()) < this->get_y_pos())
		{
			this->flip_dead();
		}
		else
		{
			map_object->flip_dead();
		}
	}
	else if (map_object->type_str() == "projectile") {
		this->interact();
		map_object->interact();
	}
	else if (map_object->type_str() == "power_up") {
		return true;
	}
	else if (map_object->type_str() == "coin") {
		return true;
	}
	else if (map_object->type_str() == "enemy_1") {
		//TODO
	}
	else if (map_object->type_str() == "enemy_2") {
		//TODO
	}
	else if (map_object->type_str() == "foobar") {
		//TODO
	}
	return false;
}

void Enemy_3::interact()
{
}