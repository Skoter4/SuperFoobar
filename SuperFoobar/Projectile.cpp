#include "Projectile.h"

Projectile::Projectile(int x_pos, int y_pos, int height, int width)
	: Enemy_1(x_pos, y_pos, height, width)
{}

bool Projectile::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "foobar"){
		//Is kill
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
	return false;
}

void Projectile::interact()
{
}

void Projectile::poly()
{
}

Projectile::~Projectile()
{

}

std::string Projectile::type_str()
{
	return "projectile";
}

