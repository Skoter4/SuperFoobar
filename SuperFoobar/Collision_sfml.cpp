#pragma once
#include "Collision_sfml.h"
/*
Foobar* foobar;

std::list<std::shared_ptr<Block>> block_list;
std::list<std::shared_ptr<Interactable>> interact_list;
std::list<std::shared_ptr<Character>> char_list;

sf::IntRect Char_Rect, sf::IntRect Block_Rect*/

//Bör vara två map_objects
//Så kan gravity osv. sättas i respektive interact

void block_collision(std::shared_ptr<Character> character_object, std::shared_ptr<Map_object> map_object)
{
	int desx = character_object->get_desx_pos();
	int desy = character_object->get_desy_pos();

	if (character_object != map_object)
	{

		int width = character_object->get_width();
		int height = character_object->get_height();
		int oldx = character_object->get_old_x();
		int oldy = character_object->get_old_y();


		//	std::cout << "Char " << desx << " " << desy<< " " << width << " " << height << " " << std::endl;
		//s	std::cout << block_object->get_x_pos()<< " " << block_object->get_x_pos()<< " " << block_object->get_width()<< " " << block_object->get_height() << std::endl;

		if (point_in_rect(desx, desy, map_object) || point_in_rect(desx + width, desy, map_object) ||
			point_in_rect(desx, desy + height, map_object) || point_in_rect(desx + width, desy + height, map_object)
			|| point_in_rect(desx + width, desy + (height / 2), map_object) || point_in_rect(desx, desy + (height / 2), map_object))
		{
			map_object->interact_with(character_object);

			if (point_in_rect(desx + width, desy, map_object) || point_in_rect(desx + width, desy + height, map_object) || point_in_rect(desx + width, desy + (height / 2), map_object))
			{
				if ((desy + height) >= map_object->get_y_pos() && desy <= (map_object->get_y_pos() + map_object->get_height())
					&& (oldy + height) > map_object->get_y_pos() && oldy < map_object->get_y_pos() + map_object->get_height())
				{
					character_object->set_desx_pos(map_object->get_x_pos() - width);
				}

				else
					if ((oldy + height) <= map_object->get_y_pos())
					{
						character_object->set_desy_pos(map_object->get_y_pos() - height);
					}
					else
					{
						character_object->set_desy_pos(map_object->get_y_pos() + map_object->get_height());
					}

			}

			if (point_in_rect(desx, desy, map_object) || point_in_rect(desx, desy + height, map_object) || point_in_rect(desx, desy + (height / 2), map_object))
			{
				if ((desy + height) >= map_object->get_y_pos() && desy <= (map_object->get_y_pos() + map_object->get_height()) &&
					(oldy + height) > map_object->get_y_pos() && oldy < map_object->get_y_pos() + map_object->get_height())
				{
					character_object->set_desx_pos(map_object->get_x_pos() + map_object->get_width());

				}
				else
					if ((oldy + height) <= map_object->get_y_pos())
					{
						character_object->set_desy_pos(map_object->get_y_pos() - height);
					}
					else
					{
						character_object->set_desy_pos(map_object->get_y_pos() + map_object->get_height());
					}

			}

		}
	}
	//std::cout << desy << "          " << character_object->get_y_pos() << std::endl;

	character_object->set_x(desx);
	character_object->set_y(desy);
	


}



bool point_in_rect(int x, int y, std::shared_ptr<Map_object> obj)
{
	if (x < (obj->get_x_pos() + obj->get_width()) && y < (obj->get_y_pos() + obj->get_height())
		&& x > obj->get_x_pos() && y > obj->get_y_pos()) {
		return true;
	}
	else {
		return false;
	}
}

