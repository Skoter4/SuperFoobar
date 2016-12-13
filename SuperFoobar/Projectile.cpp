#include "Projectile.h"

Projectile::Projectile(int x_pos, int y_pos, int height, int width)
	: Character(x_pos, y_pos, height, width)
{
	this->flip_x_velocity();
}

void Projectile::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar"){
		if (map_object->get_height() > 50)
		{
			if ((map_object->get_old_y() + 50 < this->get_y_pos()))
			{
				this->flip_dead();

			}
			else
			{
				std::dynamic_pointer_cast<Foobar> (map_object)->die();
				this->flip_dead();

			}
		}
		else if ((map_object->get_old_y() < this->get_y_pos()))
		{
			this->flip_dead();
		}
		else
		{
			std::dynamic_pointer_cast<Foobar> (map_object)->die();
		}
	}
}

void Projectile::interact()
{
}


Projectile::~Projectile()
{

}

std::string Projectile::type_str()
{
	return "projectile";
}

