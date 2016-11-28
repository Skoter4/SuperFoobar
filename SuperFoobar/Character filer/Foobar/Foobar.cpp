#include "Foobar.h"


Foobar::~Foobar()
{
}

void Foobar::set_invulnarable()
{
	if (invulnerable)
	{
		invulnerable = false;
	}
	else
	{
		invulnerable = true;
	}
}

void Foobar::power_up(Power_up immortal)
{
	if (immortal == invulnerable)
	{
		
	}
}


void Foobar::increase_size()
{

}

void Foobar::pick_up_coin()
{

}