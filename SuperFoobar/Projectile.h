#pragma once
#include "../Character filer/Enemy/Enemy_1.h"
#include "Character filer\Foobar\Foobar.h"
class Projectile :
	public Character
{
public:
	Projectile(int, int, int, int);

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	void interact() override;

	~Projectile();

	std::string type_str() override;
};

