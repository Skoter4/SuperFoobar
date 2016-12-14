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
			if (!this->deactivated)
			{
				this->interact();
			}
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
	else
		if (map_object->type_str() == "projectile")
		{
			map_object->flip_dead();
		}
}

bool Generator::to_break(shared_ptr<Cluster> other_cluster) {
	int block_y = get_y_pos();
	int other_y = other_cluster->get_y();
	if (other_y < block_y) {
		return true;
	}
	else
	{
		return false;
	}

}

void Generator::interact()
{
	this->flip_generating();
}

