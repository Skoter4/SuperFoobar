#pragma once
#include "Enemy_1.h"
#include "../Projectile.h"

Enemy_1::~Enemy_1()
{
}

void Enemy_1::fire_projectile()
{
	Projectile::Projectile(this->get_x_pos, this->get_y_pos, 10, 5);
}
