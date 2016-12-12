#include "Breakable.h"
#include "../Character filer/Foobar/Foobar.h"

using namespace std;

Breakable::Breakable(int x_pos, int y_pos, int length, int width)
  :Block(x_pos, y_pos, length, width)
{}

void Breakable::destruct()
{
  this->flip_dead();
}

std::string Breakable::type_str()
{
	return "breakable";
}

bool Breakable::interact_with(shared_ptr<Map_object> my_char) {
	if (my_char->type_str() == "foobar") {
		if (to_break(my_char->get_cluster()))
			this->interact();
			this->get_cluster()->set_remove(true);
		}
	else if (my_char->type_str() == "enemy_2")
	{
		if (my_char->get_old_y() <= this->get_y_pos())
		{
		}
		else
		{
			dynamic_pointer_cast<Enemy_2> (my_char)->flip_x_velocity();
		}
	}
	else if (my_char->type_str() == "enemy_3")
	{
		if (my_char->get_old_y() <= this->get_y_pos())
		{
		}
		else
		{
			dynamic_pointer_cast<Enemy_3> (my_char)->flip_x_velocity();
		}
	}
	else if (my_char->type_str() == "foobar")
	{
		if (this->get_y_pos() > my_char->get_old_y())
		{
			if (!dynamic_pointer_cast<Foobar> (my_char)->get_on_ground())
			{
				dynamic_pointer_cast<Foobar> (my_char)->flip_on_ground();
			}
		}
		dynamic_pointer_cast<Foobar> (my_char)->set_y_velocity(0);

	}
	return false;
}

bool Breakable::to_break(shared_ptr<Cluster> other_cluster) {
	int block_y = this->get_y_pos();
	int other_y = other_cluster->get_y();
	if (other_y > block_y) {
		return true;
	}
	else
	{
		return false;
	}

}

void Breakable::interact()
{ 
  this->destruct();
  this->flip_active();
}

void Breakable::poly()
{

}

