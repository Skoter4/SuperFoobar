#pragma once
#include "../Character.h"
#include "../Interactable-filer/Power_up.h"
#include <iostream>



class Foobar :
	public Character
{
public:
	//Foobar();
	~Foobar() = default;
	Foobar(int x_pos, int y_pos, int width, int height)
		: Character(x_pos, y_pos, width, height) {}
	void poly() override;
	std::string type_str() override;
	void power_up(Power_up);
	void increase_size(int, int);
	void pick_up_coin();
	void jump();
	void duck();
	void stand_up();
	void run();
	void set_max_speed_x(int);
	int get_max_speed_x();

	bool interact_with(std::shared_ptr<Map_object> my_char) override;

	void interact() override;
	void flip_is_ducking();
	bool get_is_ducking();

private:
	int max_speed_x{1};
	bool is_ducking{ false };
};


