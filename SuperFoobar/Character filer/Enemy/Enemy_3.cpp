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
	if (my_char->type_str() == "foobar") 
	{
		this->flip_dead();
	}
	return 0;
}

void Enemy_3::interact()
{
}