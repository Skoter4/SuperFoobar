#pragma once
#include "../Character filer/Foobar/Foobar.h"
class Enemy_2 :
	public Character
{
public:
	Enemy_2(int x, int y, int width, int height);
	~Enemy_2() = default;

	std::string type_str() override;
	void interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;
};

