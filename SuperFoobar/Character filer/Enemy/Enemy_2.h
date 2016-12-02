#pragma once
#include "../Character filer/Character.h"
class Enemy_2 :
	public Character
{
public:
	Enemy_2(float x, float y, float width, float height)
		: Character(x, y, width, height) {}
	~Enemy_2();
};

