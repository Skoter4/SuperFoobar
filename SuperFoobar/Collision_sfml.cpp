/*
* FILENAME:     Collision_sfml.cpp
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*               Alexander Eriksson 950405-9552 MED3
*               Martin Allander 951218-6215 Y2b
*               Tobias Nilsson 950103-6736 MED3
*               Tomas Widfeldt 940121-2015 MED3
*
* DATE:         2016-12-14
*/

#pragma once
#include "Collision_sfml.h"


void block_collision(std::shared_ptr<Character> character_object, std::shared_ptr<Map_object> map_object)
{
	//Declarations for easy access of variables needed.
	int desx = character_object->get_desx_pos();
	int desy = character_object->get_desy_pos();


	if (map_object != character_object)
	{
		//Declarations for easy access of variables needed.
		int width = character_object->get_width();
		int height = character_object->get_height();
		int oldx = character_object->get_old_x();
		int oldy = character_object->get_old_y();


		bool top_right_collision = point_in_rect(desx + width, desy, map_object);
		bool top_left_collision = point_in_rect(desx, desy, map_object);
		bool bottom_left_collision = point_in_rect(desx, desy + height, map_object);
		bool bottom_right_collision = point_in_rect(desx + width, desy + height, map_object);
		bool middle_left_collision = point_in_rect(desx, desy + (height / 2), map_object);
		bool middle_right_collision = point_in_rect(desx + width, desy + (height / 2), map_object);

		if (top_left_collision || top_right_collision || bottom_left_collision
			|| bottom_right_collision || middle_left_collision || middle_right_collision) // Checks if a collsion happens
		{
			map_object->interact_with(character_object);

			if (top_right_collision || bottom_right_collision || middle_right_collision) // Checks if the collsion is from the right
			{
				if ((desy + height) >= map_object->get_y_pos() && desy <= (map_object->get_y_pos() + map_object->get_height())
					&& (oldy + height) > map_object->get_y_pos() && oldy < map_object->get_y_pos() + map_object->get_height()) //Collision from the side
				{
					character_object->set_desx_pos(map_object->get_x_pos() - width);
				}

				else
					if ((oldy + height) <= map_object->get_y_pos()) //Collision from above
					{
						character_object->set_desy_pos(map_object->get_y_pos() - height);
					}
					else //Collsion from beneath
					{
						character_object->set_desy_pos(map_object->get_y_pos() + map_object->get_height());
					}

			}

			if (top_left_collision || bottom_left_collision || middle_left_collision) // Checks if the collsion is from the left
			{
				if ((desy + height) >= map_object->get_y_pos() && desy <= (map_object->get_y_pos() + map_object->get_height()) &&
					(oldy + height) > map_object->get_y_pos() && oldy < map_object->get_y_pos() + map_object->get_height()) // Collsion from the side
				{
					character_object->set_desx_pos(map_object->get_x_pos() + map_object->get_width());
				}
				else
					if ((oldy + height) <= map_object->get_y_pos()) // Collision from above
					{
						character_object->set_desy_pos(map_object->get_y_pos() - height);
					}
					else
					{
						character_object->set_desy_pos(map_object->get_y_pos() + map_object->get_height()); // Collsion from beneath
					}
			}
		}
	}

	character_object->set_x(desx);
	character_object->set_y(desy);

}

bool point_in_rect(int x, int y, std::shared_ptr<Map_object> obj)
{
	if (x <= (obj->get_x_pos() + obj->get_width()) && y <= (obj->get_y_pos() + obj->get_height())
		&& x >= obj->get_x_pos() && y >= obj->get_y_pos()) {
		return true;
	}
	else {
		return false;
	}
}

