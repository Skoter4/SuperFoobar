#pragma once
#include "../Character.h"
class Enemy_3 :
	public Character
{
public:
	Enemy_3(float x, float y, float width, float height)
		: Character(x, y, width, height) {}
	~Enemy_3();
};

