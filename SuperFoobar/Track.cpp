#include "Track.h"

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

shared_ptr<Foobar> Track::get_foobar()
{
	return this->foobar;
}

void Track::set_foobar(shared_ptr<Foobar> new_foobar)
{
	this->foobar = new_foobar;
}