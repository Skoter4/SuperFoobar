#include "Enemy_2.h"


Enemy_2::~Enemy_2()
{
}

void Enemy_2::poly()
{
}

std::string Enemy_2::type_str()
{
	return "enemy_2";
}

bool Enemy_2::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "foobar")
	{
		this->flip_dead();
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

void Enemy_2::interact()
{
}