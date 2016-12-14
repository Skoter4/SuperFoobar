/*
* FILENAME:      Track.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include "Track.h"
#include <iostream>
using namespace std;

Track::Track(list<shared_ptr<Block>> blocks, list<shared_ptr<Character>> characters, list<shared_ptr<Interactable>> interactables,
	int width, int height, int floor)
	:block_list{ blocks }, character_list{ characters },
	interactable_list{ interactables }, height{ height },
	width{ width }, floor{ floor }
{
	auto it = characters.begin();
	while (it != characters.end())
	{
		if ((*it)->type_str() == "foobar")
		{
			this->set_foobar(dynamic_pointer_cast<Foobar> (*it));
			break;
		}
		it++;
	}
	if (this->get_foobar().get() == nullptr)
		throw std::invalid_argument("'Characters' list lacks Foobar object!");
}


int Track::get_floor()
{
	return this->floor;
}

int Track::get_height()
{
	return this->height;
}

int Track::get_width()
{
	return this->width;
}

void Track::set_floor(int new_floor)
{
	this->floor = new_floor;
}

void Track::flip_end_of_game()
{
	this->end_of_game = !(this->end_of_game);
}

bool Track::is_end_of_game()
{
	return this->end_of_game;
}

void Track::set_height(int new_height)
{
	this->height = new_height;
}

void Track::set_width(int new_width)
{
	this->width = new_width;
}

list<shared_ptr<Block>> & Track::get_block_list()
{
	return this->block_list;
}

list<shared_ptr<Character>> & Track::get_character_list()
{
	return this->character_list;
}

list<shared_ptr<Interactable>> & Track::get_interactable_list()
{
	return this->interactable_list;
}

void Track::set_score(Score & new_score)
{
	this->score = new_score;
}

void Track::set_timer(Timer & new_timer)
{
	this->timer = new_timer;
}

void Track::set_scoreboard(Scoreboard & new_scoreboard)
{
	this->scoreboard = new_scoreboard;
}

Score & Track::get_score()
{
	return this->score;
}

Timer & Track::get_timer()
{
	return this->timer;
}

Scoreboard & Track::get_scoreboard()
{
	return this->scoreboard;
}

Track Track::add_map_object(shared_ptr<Map_object> new_map_object)
{
	if (dynamic_pointer_cast<Character>(new_map_object).get() != nullptr)
		this->character_list.push_front(dynamic_pointer_cast<Character>(new_map_object));
	else if (dynamic_pointer_cast<Block>(new_map_object).get() != nullptr)
		this->block_list.push_front(dynamic_pointer_cast<Block>(new_map_object));
	else if (dynamic_pointer_cast<Interactable>(new_map_object).get() != nullptr)
		this->interactable_list.push_front(dynamic_pointer_cast<Interactable> (new_map_object));
	else
		throw std::invalid_argument("Cannot add object type to track lists!");

	return *this;
}

Track Track::operator+(shared_ptr<Map_object> new_map_object)
{
	return this->add_map_object(new_map_object);
}

void Track::handle_map_object_flags()
{
	// Goes through the block-list
	for (auto it = this->get_block_list().begin(); it != this->get_block_list().end(); ++it)
	{
		// If a block object is flagged dead it is removed from the list
		if ((*it)->is_dead())
		{
			it = this->get_block_list().erase(it);
			if (it == this->get_block_list().end())
				break;
		}
		// If the block object is of type Generator it generates a reward once
		if ((*it)->type_str() == "generator")
		{
			shared_ptr<Generator> generator_ptr{ dynamic_pointer_cast<Generator>(*it) };
			if (generator_ptr->is_generating())
			{
				shared_ptr<Interactable> reward{ generator_ptr->generate() };
				this->interactable_list.push_front(reward);

			}
		}
	}

	// Goes through the character-list
	for (auto it = this->get_character_list().begin(); it != this->get_character_list().end(); ++it)
	{
		if ((*it)->is_dead())
		{
			it = this->get_character_list().erase(it);
			if (it == this->get_character_list().end())
				break;
		}
		// If the character object is of type Enemy_1 a projectile is generated if it is ready to fire
		if ((*it)->type_str() == "enemy_1")
		{
			shared_ptr<Enemy_1> enemy_ptr{ dynamic_pointer_cast<Enemy_1>(*it) };
			if (enemy_ptr->ready_to_fire())
			{
				shared_ptr<Character> proj{ enemy_ptr->fire_projectile() };
				character_list.push_front(proj);
				enemy_ptr->flip_ready();
			}
		}
	}

	// Goes through the interactable-list
	for (auto it = this->get_interactable_list().begin(); it != this->get_interactable_list().end(); ++it)
	{
		if ((*it)->is_dead())
		{
			// Coins increase the score by 10
			if ((*it)->type_str() == "coin")
			{
				this->score.increase_score(10.0f);
			}
			// Stars increase score by 100
			else if ((*it)->type_str() == "power_up_star")
			{
				foobar->power_up(dynamic_pointer_cast<Power_up>(*it));
				this->score.increase_score(100.0f);
			}
			else if ((*it)->type_str() == "power_up_shroom")
			{
				foobar->power_up(dynamic_pointer_cast<Power_up>(*it));
			}
			else if ((*it)->type_str() == "finish_line") {
				flip_end_of_game();
			}
			it = this->get_interactable_list().erase(it);
			if (it == this->get_interactable_list().end())
				break;
		}
	}

}

shared_ptr<Foobar> Track::get_foobar()
{
	return this->foobar;
}

void Track::set_foobar(shared_ptr<Foobar> new_foobar)
{
	this->foobar = new_foobar;
}


