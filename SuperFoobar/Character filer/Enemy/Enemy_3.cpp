#include "Enemy_3.h"


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

bool Enemy_3::interact_with(std::shared_ptr<Map_object> my_char)
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
	else if (my_char->type_str() == "enemy_1") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_2") {
		//TODO
	}
	else if (my_char->type_str() == "foobar") {
		//TODO
	}
	return false;
}

void Enemy_3::interact()
{
}