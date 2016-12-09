#pragma once
#include "../Character filer/Character.h"
//#include "Projectile.h"
class Enemy_1 :
	public Character
{
public:
	Enemy_1(int x, int y, int width, int height)
		: Character(x, y, width, height) {}
	~Enemy_1();
	void poly() override;
	std::string type_str() override;
	bool interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;

	
	void fire_projectile();

};

