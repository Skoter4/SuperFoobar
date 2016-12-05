#include "Foobar.h"
#include <memory>

using namespace std;

void Foobar::poly()
{
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

void Foobar::run()
{
	this->set_max_speed_x(2 * this->max_speed_x);
}
