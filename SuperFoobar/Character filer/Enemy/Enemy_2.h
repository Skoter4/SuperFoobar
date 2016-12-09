#pragma once
#include "../Character filer/Character.h"
class Enemy_2 :
	public Character
{
public:
	Enemy_2(int x, int y, int width, int height)
		: Character(x, y, width, height) {}
	~Enemy_2();

	void poly() override;
	std::string type_str() override;
	bool interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;
};

