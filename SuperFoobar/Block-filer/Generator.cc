/*
* FILENAME:     Generator.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*/

#include "Generator.h"
#include <utility>

using namespace std;

Generator::Generator(int x, int y, int height, int width,
		    std::shared_ptr<Interactable> interactable)
  :Block(x, y, height, width), reward(std::move(interactable))
{}

void Generator::flip_deactivated()
{
	this->deactivated = !deactivated;
}

void Generator::flip_generating()
{
	this->generating = !generating;
}

bool Generator::is_generating()
{
	return this->generating;
}

bool Generator::is_deactivated()
{
	return this->deactivated;
}

std::string Generator::type_str()
{
	return "generator";
}

std::shared_ptr<Interactable> const & Generator::generate()
{
	this->flip_generating();
	this->flip_deactivated();

	return move(this->reward);
}

void Generator::interact_with(std::shared_ptr<Map_object> map_object)
{
	if(map_object->type_str() == "foobar")
	{
		if (map_object->get_old_y() >= this->get_height() + this->get_y_pos())
		{
			// If Foobar is beneath the Generator-object, following happens:
			if (!this->deactivated)
			{
				//Generates its interactable if deactivates is false.
				this->interact();
			}
			dynamic_pointer_cast<Foobar> (map_object)->set_y_velocity(0);
		
		}
		else if (this->get_y_pos() >= map_object->get_old_y() + map_object->get_height()
			&& map_object->get_x_pos() <= this->get_x_pos() + this->get_width()
			&& map_object->get_x_pos() + map_object->get_width() >= this->get_x_pos())
		{
			// If Foobar is above the Generator-object
			dynamic_pointer_cast<Foobar> (map_object)->set_y_velocity(0);
			if (!dynamic_pointer_cast<Foobar> (map_object)->get_on_ground())
			{
				//Set on_ground to true if Foobar lands on the Generator-object.
				dynamic_pointer_cast<Foobar> (map_object)->flip_on_ground();
			}
		}
		else
		{
			// This happens when Foobar is on the side of the breakable-object.
			dynamic_pointer_cast<Foobar> (map_object)->set_x_velocity(0);
		}
	}
	else
		if (map_object->type_str() == "projectile")
		{
			map_object->flip_dead();
		}
}

void Generator::interact()
{
	this->flip_generating();
}

