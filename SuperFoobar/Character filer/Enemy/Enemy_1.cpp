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

bool Enemy_1::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "projectile") {
		//Is kill
	}
	else if (my_char->type_str() == "power_up") {
		//TODO
	}
	else if (my_char->type_str() == "coin") {
		my_char->interact();
	}
	else if (my_char->type_str() == "enemy_1") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_2") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_3") {
		//TODO
	}
	return 0;
}

void Enemy_1::interact()
{
}
