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

void Foobar::power_up(Power_up huuuge)
{
	this->set_lifes(2);
	this->increase_size(10, 10);
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

void Foobar::set_max_speed_x(int new_max_speed_x)
{
	this->max_speed_x = new_max_speed_x;
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
}

void Foobar::interact()
{
}

void Foobar::run()
{
	this->set_max_speed_x(2 * this->max_speed_x);
}
