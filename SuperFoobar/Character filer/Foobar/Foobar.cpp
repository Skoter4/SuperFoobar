#include "Foobar.h"
#include <memory>

using namespace std;


Foobar::Foobar(int x_pos, int y_pos, int width, int height)
	: Character(x_pos, y_pos, width, height)
{
	this->set_x_velocity(0);
	this->set_y_velocity(0);
}

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
	if (this->get_on_ground() && this->get_y_velocity() == 0)
	{
		this->set_y_velocity(-25);
		this->flip_on_ground();
	}
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


bool Foobar::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "projectile") {
		this->die();
		my_char->interact();
	}
	else if (my_char->type_str() == "power_up"){
		//TODO
	}
	else if (my_char->type_str() == "coin") {
		my_char->interact();
	}
	else if (my_char->type_str() == "enemy_1") {
		if (this->to_break(my_char->get_cluster())) {
			my_char->flip_dead();
		}
	}
	else if (my_char->type_str() == "enemy_2") {
		if (this->to_break(my_char->get_cluster())) {
			my_char->flip_dead();
		}
	}
	else if (my_char->type_str() == "enemy_3") {
		if (this->to_break(my_char->get_cluster())) {
			my_char->flip_dead();
		}
	}
	return true;
}

void Foobar::interact()
{
}

void Foobar::run()
{
	this->set_max_speed_x(10);
}

