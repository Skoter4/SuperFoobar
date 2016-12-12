#pragma once
#include "Enemy_1.h"
#include "../Projectile.h"

Enemy_1::Enemy_1(int x, int y, int width, int height, std::shared_ptr<Projectile> projectile_ptr)
	: Character(x, y, width, height), 
	my_projectile{ std::shared_ptr <Character>{projectile_ptr} }
{
}

Enemy_1::~Enemy_1()
{
}

std::shared_ptr<Character> Enemy_1::fire_projectile()
{
	return my_projectile;
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
		this->flip_dead();
		my_char->flip_dead();
	}
	else if (my_char->type_str() == "power_up") {
		return true;
	}
	else if (my_char->type_str() == "coin") {
		return true;
	}
	else if (my_char->type_str() == "foobar") {
		if (to_break(my_char->get_cluster())) {
			my_char->interact();
		}
	}
	else if (my_char->type_str() == "enemy_2") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_3") {
		//TODO
	}
	return false;
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
