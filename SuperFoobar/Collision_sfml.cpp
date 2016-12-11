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


	sf::IntRect char_rect = character_object->get_sprite()->getTextureRect();
	sf::IntRect block_rect = map_object->get_sprite()->getTextureRect();

	int desx = character_object->get_desx_pos();
	int desy = character_object->get_desy_pos();
	int width = character_object->get_width();
	int height = character_object->get_height();

	//	std::cout << "Char " << desx << " " << desy<< " " << width << " " << height << " " << std::endl;
	//s	std::cout << block_object->get_x_pos()<< " " << block_object->get_x_pos()<< " " << block_object->get_width()<< " " << block_object->get_height() << std::endl;

	if (point_in_rect(desx, desy, map_object) || point_in_rect(desx + width, desy, map_object) ||
		point_in_rect(desx, desy + height, map_object) || point_in_rect(desx + width, desy + height, map_object)
		|| point_in_rect(desx + width, desy + (height / 2), map_object) || point_in_rect(desx, desy + (height / 2), map_object))
	{
		map_object->interact_with(character_object);

		if (point_in_rect(desx + width, desy, map_object) || point_in_rect(desx + width, desy +  height, map_object) || point_in_rect(desx + width, desy + (height/2), map_object))
		{
			if ((desy + height) >= map_object->get_y_pos() && desy <= (map_object->get_y_pos() + map_object->get_height()))
			{
				character_object->set_y(character_object->get_desy_pos());
				character_object->set_desx_pos(map_object->get_x_pos() - width);

				update_sprite_position(character_object);
			}

			else
			{
				character_object->set_x(character_object->get_desx_pos());
				character_object->set_desy_pos(map_object->get_y_pos() - height);

				update_sprite_position(character_object);
			}

		}

		if (point_in_rect(desx, desy, map_object) || point_in_rect(desx, desy + height, map_object) || point_in_rect(desx, desy + (height / 2), map_object))
		{
			if ((desy + height) >= map_object->get_y_pos() && desy <= (map_object->get_y_pos() + map_object->get_height()) &&
				(character_object->get_y_pos() + height) > map_object->get_y_pos())
			{
				character_object->set_y(character_object->get_desy_pos());
				character_object->set_desx_pos(map_object->get_x_pos() + map_object->get_width());

				update_sprite_position(character_object);
			}

			else
			{
				character_object->set_x(character_object->get_desx_pos());
				character_object->set_desy_pos(map_object->get_y_pos() - height);

				update_sprite_position(character_object);
			}

		}


		
		/*
			//std::cout << "Collision" << std::endl;
			//character_object->interact_with(block_object);

			//std::cout << map_object->get_x_pos() << std::endl;
			while (desx + width > map_object->get_x_pos())
			{
				character_object->set_x(map_object->get_x_pos() - character_object->get_width());
				break;
			}
			while (desy + height > map_object->get_y_pos())
			{
				character_object->set_y(map_object->get_y_pos() - character_object->get_height());
				break;
			}
			*/

	}
	else {
		character_object->set_y(character_object->get_desy_pos());
		character_object->set_x(character_object->get_desx_pos());
		std::cout << desy << "          " << character_object->get_y_pos() << std::endl;
	}
	/*
	if (character_object->get_desy_pos() >= (block_object->get_y_pos() + block_object->get_height())
		&& (character_object->get_desy_pos() + character_object->get_height() <= block_object->get_y_pos())
		&& character_object->get_desx_pos() + character_object->get_width() <= block_object->get_x_pos())
	{
		if (character_object->type_str() == "foobar")
		{
			character_object->set_x_velocity(0);
			character_object->set_y(character_object->get_desy_pos());
		}

		if (character_object->type_str() == "projectile")
		{

		}

		else
		{
			character_object->set_x_velocity(-character_object->get_x_velocity());
		}

	}

	if ((character_object->get_desy_pos() + character_object->get_height()) >= block_object->get_y_pos())
	{
		if ((character_object->get_desx_pos() + character_object->get_width()) > block_object->get_x_pos()
			&& character_object->get_desx_pos() < (block_object->get_x_pos() + block_object->get_width()))

		{
			character_object->set_y(block_object->get_y_pos() - character_object->get_height());
			character_object->set_x(character_object->get_desx_pos());
		}



	}

	if (block_object->type_str() == "non_breakable")
	{
		character_object->set_y_velocity(character_object->get_gravity());
		character_object->set_y(character_object->get_y_pos() + character_object->get_y_velocity());
		character_object->set_x(character_object->get_desx_pos());
	}

	if (block_object->type_str() == "breakable")
	{
		character_object->set_y_velocity(character_object->get_gravity());
		character_object->set_y(character_object->get_y_pos() + character_object->get_y_velocity());
		character_object->set_x(character_object->get_desx_pos());
		block_object->interact();
	}

	if (block_object->type_str() == "generator")
	{
		character_object->set_y_velocity(character_object->get_gravity());
		character_object->set_y(character_object->get_y_pos() + character_object->get_y_velocity());
		character_object->set_x(character_object->get_desx_pos());
		block_object->interact();

	}*/
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

