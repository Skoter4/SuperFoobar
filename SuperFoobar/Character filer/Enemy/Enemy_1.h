#pragma once
#include "../Character filer/Character.h"

class Projectile;

//#include "../Projectile.h"
class Enemy_1 :
	public Character
{
public:
	Enemy_1(int x, int y, int width, int height, std::shared_ptr<Projectile>);
	~Enemy_1();
	void poly() override;
	std::string type_str() override;
	bool interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;

	bool ready_to_fire();
	void flip_ready();
	int get_prev_time();
	void set_prev_time(int time);
	
	std::shared_ptr<Character> fire_projectile();

private:
	std::shared_ptr<Character> my_projectile;
	bool to_fire{false};
	int prev_time{-1};
};

