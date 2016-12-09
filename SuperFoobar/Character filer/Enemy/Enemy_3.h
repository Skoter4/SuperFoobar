#pragma once
#include "../Character.h"
class Enemy_3 :
	public Character
{
public:
	Enemy_3(int x, int y, int width, int height)
		: Character(x, y, width, height) {}
	~Enemy_3();

	void poly() override;
	std::string type_str() override;
	bool interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;
};

