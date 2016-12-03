#pragma once
#include "../Character.h"
#include "../Interactable-filer/Power_up.h"

class Foobar :
	public Character
{
public:
	//Foobar();
	~Foobar() = default;
	Foobar(int x_pos, int y_pos, int width, int height)
		: Character(x_pos, y_pos, width, height) {}
	void poly() override;
	void power_up(Power_up);
	void increase_size(int, int);
	void pick_up_coin();
	void jump();
	void duck();
	void run();
	void set_max_speed_x(int);
	std::shared_ptr<Cluster> get_cluster();


private:
	int max_speed_x{1};

};


