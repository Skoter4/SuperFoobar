#include "Foobar.h"


void Foobar::power_up(Power_up immortal)
{
	this->flip_invulnerable();
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
	this->set_height( (this->height) / 2);
}

void Foobar::set_max_speed_x(int new_max_speed_x)
{
	this->max_speed_x = new_max_speed_x;
}

void Foobar::run()
{
	this->set_max_speed_x(2 * this->max_speed_x);
}