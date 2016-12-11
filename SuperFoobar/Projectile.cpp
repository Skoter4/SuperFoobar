#include "Projectile.h"

Projectile::Projectile(int x_pos, int y_pos, int height, int width)
	: Enemy_1(x_pos, y_pos, height, width)
{}

bool Projectile::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "foobar"){
		my_char->flip_dead();
		this->flip_dead();
	}
	else if (my_char->type_str() == "enemy_1") {
		my_char->flip_dead();
		this->flip_dead();
	}
	else if (my_char->type_str() == "enemy_2") {
		my_char->flip_dead();
		this->flip_dead();
	}
	else if (my_char->type_str() == "enemy_3") {
		my_char->flip_dead();
		this->flip_dead();
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

