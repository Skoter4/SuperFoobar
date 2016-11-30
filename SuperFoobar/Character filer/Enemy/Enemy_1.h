#pragma once
#include "../Character filer/Character.h"
//#include "Projectile.h"
class Enemy_1 :
	protected Character
{
public:
	Enemy_1(float x, float y, float width, float height)
		: Character(x, y, width, height) {}
	~Enemy_1();

	void fire_projectile();

};

