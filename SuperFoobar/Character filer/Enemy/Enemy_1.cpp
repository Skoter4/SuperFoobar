#pragma once
#include "Enemy_1.h"
#include "../Projectile.h"

Enemy_1::~Enemy_1()
{
}

void Enemy_1::fire_projectile()
{
	Projectile::Projectile(this->get_x_pos(), this->get_y_pos(), 10, 5);
}

void Enemy_1::poly()
{
}

std::string Enemy_1::type_str()
{
	return "enemy_1";
}

bool Enemy_1::interact_with(std::shared_ptr<Map_object> map_object)
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
		this->flip_dead();
		map_object->flip_dead();
	}
	else if (map_object->type_str() == "power_up") {
		return true;
	}
	else if (map_object->type_str() == "coin") {
		return true;
	}
	else if (map_object->type_str() == "foobar") 
	{
			map_object->interact();
	}
	else if (map_object->type_str() == "enemy_2") {
		//TODO
	}
	else if (map_object->type_str() == "enemy_3") {
		//TODO
	}
	return false;
}

void Enemy_1::interact()
{
}
