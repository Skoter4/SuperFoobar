#pragma once
#include "../Character.h"
#include "../Character filer/Foobar/Foobar.h"
class Enemy_3 :
	public Character
{
public:
	Enemy_3(int x, int y, int width, int height);
	~Enemy_3() = default;
	std::string type_str() override;
	void interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;
};

