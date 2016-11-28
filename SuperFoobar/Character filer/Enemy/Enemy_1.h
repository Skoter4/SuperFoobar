#pragma once
#include "Character.h"
#include "Projectile.h"
class Enemy_1 :
	public Character
{
public:
	Enemy_1();
	~Enemy_1();

	void fire_projectile();

};

