#include "Enemy_2.h"


Enemy_2::~Enemy_2()
{
}

Enemy_2::Enemy_2(int x, int y, int width, int height)
	: Character(x, y, width, height) 
{}

void Enemy_2::poly()
{
}

std::string Enemy_2::type_str()
{
	return "enemy_2";
}

bool Enemy_2::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "projectile") {
		this->interact();
		my_char->interact();
	}
	else if (my_char->type_str() == "power_up") {
		return true;
	}
	else if (my_char->type_str() == "coin") {
		return true;
	}
	else if (my_char->type_str() == "foobar") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_2") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_3") {
		//TODO
	}
	return false;
}

void Enemy_2::interact()
{
}