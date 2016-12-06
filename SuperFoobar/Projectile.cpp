#include "Projectile.h"

Projectile::Projectile(int x_pos, int y_pos, int height, int width)
	: Enemy_1(x_pos, y_pos, height, width)
{}

bool Projectile::interact_type(std::shared_ptr<Map_object> my_char)
{
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

