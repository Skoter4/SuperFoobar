#include "Non_breakable.h"
using namespace std;

Non_breakable::Non_breakable(int x, int y, int height, int width)
	:Block(x, y, height, width)
{}

void Non_breakable::poly()
{
}

void Non_breakable::interact()
{
}

bool Non_breakable::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "projectile") {
		my_char->flip_dead();
	}
	else if (my_char->type_str() == "enemy_2")
	{
		dynamic_pointer_cast<Enemy_2> (my_char)->flip_x_velocity();
	}
	else if (my_char->type_str() == "enemy_3")
	{
		dynamic_pointer_cast<Enemy_3> (my_char)->flip_x_velocity();
	}
	return false;
}

std::string Non_breakable::type_str()
{
	return "non_breakable";
}
