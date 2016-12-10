#include "Foobar.h"
#include <memory>

using namespace std;

void Foobar::poly()
{
}

std::string Foobar::type_str()
{
	return "foobar";
}

void Foobar::power_up(shared_ptr<Power_up> power_up)
{
	if (power_up->type_str() == "power_up_star")
		this->flip_invulnerable();
	else if (power_up->type_str() == "power_up_shroom")
	{
		this->set_lifes(2);
		this->increase_size(50, 100);
		this->set_desy_pos(this->get_y_pos() - 40);
	}
}

void Foobar::increase_size(int new_width, int new_height)
{
	this->set_width(new_width);
	this->set_height(new_height);
}

void Foobar::pick_up_coin()
{

}

void Foobar::jump()
{

}

void Foobar::duck()
{
	this->set_height( (get_height()) / 2);
}

void Foobar::flip_is_ducking()
{
	is_ducking = !is_ducking;
}

bool Foobar::get_is_ducking()
{
	return is_ducking;
}

void Foobar::stand_up()
{
	this->set_height((get_height()) * 2);
}

void Foobar::set_max_speed_x(int new_max_speed_x)
{
	this->max_speed_x = new_max_speed_x;
}

int Foobar::get_max_speed_x()
{
	return this->max_speed_x;
}

bool Foobar::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "projectile") {
		//Is kill
	}
	else if (my_char->type_str() == "power_up"){
		//TODO
	}
	else if (my_char->type_str() == "coin") {
		pick_up_coin();
		my_char->interact();
	}
	else if (my_char->type_str() == "enemy_1") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_2") {
		//TODO
	}
	else if (my_char->type_str() == "enemy_3") {
		//TODO
	}
	return true;
}

void Foobar::interact()
{
}

void Foobar::run()
{
	this->set_max_speed_x(2 * this->max_speed_x);
}
