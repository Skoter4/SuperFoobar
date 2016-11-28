#pragma once
#include "Character.h"

class Foobar :
	public Character
{
public:
	Foobar() = default;
	~Foobar() = default;
	Foobar(float x_pos, float y_pos, float width, float height)
		: Character(x_pos, y_pos, width, height) {}
	void power_up(Power_up);
	void increase_size();
	void pick_up_coin();
	void set_invulnarable();

private:
	bool invulnerable{ false };

};

