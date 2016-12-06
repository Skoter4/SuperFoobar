#pragma once
#include "../Character filer/Enemy/Enemy_1.h"
class Projectile :
	protected Enemy_1
{
public:
	Projectile(int, int, int, int);

	bool interact_with(std::shared_ptr<Map_object> my_char) override;

	void interact() override;

	void poly() override;
	~Projectile();

	std::string type_str() override;
};

