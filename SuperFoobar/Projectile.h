#pragma once
#include "../Character filer/Enemy/Enemy_1.h"
class Projectile :
	protected Enemy_1
{
public:
	Projectile(float, float, float, float);

	~Projectile();

};

