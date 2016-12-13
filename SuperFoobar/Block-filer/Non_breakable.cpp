#include "Non_breakable.h"
using namespace std;

Non_breakable::Non_breakable(int x, int y, int height, int width)
	:Block(x, y, height, width)
{}


void Non_breakable::interact()
{
}

void Non_breakable::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "projectile") {
		map_object->flip_dead();
	}
	else if (map_object->type_str() == "enemy_2")
	{
		if (map_object->get_old_y() <= this->get_y_pos())
		{

		}
		else
		{
			dynamic_pointer_cast<Enemy_2> (map_object)->flip_x_velocity();
		}
	}
	else if (map_object->type_str() == "enemy_3")
	{
		if (map_object->get_old_y() <= this->get_y_pos())
		{
		}
		else
		{
			dynamic_pointer_cast<Enemy_3> (map_object)->flip_x_velocity();
		}
	}
	else 	if (map_object->type_str() == "foobar")
	{
		if (map_object->get_old_y() >= this->get_height() + this->get_y_pos())
		{
			dynamic_pointer_cast<Foobar> (map_object)->set_y_velocity(0);
		}
		else if (this->get_y_pos() >= map_object->get_old_y() + map_object->get_height() && map_object->get_x_pos() <= this->get_x_pos() + this->get_width()
			&& map_object->get_x_pos() + map_object->get_width() >= this->get_x_pos())
		{
			dynamic_pointer_cast<Foobar> (map_object)->set_y_velocity(0);
			if (!dynamic_pointer_cast<Foobar> (map_object)->get_on_ground())
			{
				dynamic_pointer_cast<Foobar> (map_object)->flip_on_ground();
			}
		}
		else
		{
			dynamic_pointer_cast<Foobar> (map_object)->set_x_velocity(0);
		}
	}
}

std::string Non_breakable::type_str()
{
	return "non_breakable";
}
