#include "Foobar.h"

void Foobar::set_invulnarable()
{
	if (invulnerable)
	{
		this->invulnerable = false;
	}
	else
	{
		this->invulnerable = true;
	}
}

void Foobar::power_up(Power_up immortal)
{
	
}


void Foobar::increase_size(float new_width, float new_height)
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