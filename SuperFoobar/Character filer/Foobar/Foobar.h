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
	Foobar(int x_pos, int y_pos, int width, int height);
	std::string type_str() override;

	void power_up(std::shared_ptr<Power_up>);
	void increase_size(int, int);
	void pick_up_coin();
	void jump();
	void duck();
	void stand_up();
	void run();

	void interact_with(std::shared_ptr<Map_object> my_char) override;

	void interact() override;
	void flip_is_ducking();
	bool get_is_ducking();

private:
	bool is_ducking{ false };

};


