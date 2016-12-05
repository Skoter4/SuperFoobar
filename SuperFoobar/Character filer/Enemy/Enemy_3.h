#pragma once
#include "../Character.h"
class Enemy_3 :
	public Character
{
public:
	Enemy_3(int x, int y, int width, int height)
		: Character(x, y, width, height) {}
	~Enemy_3();
};

