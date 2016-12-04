#include "Track.h"

using namespace std;

Track::Track(list<shared_ptr<Block>> blocks, list<shared_ptr<Character>> characters, list<shared_ptr<Interactable>> interactables,
	int width, int height, int floor)
	:block_list{ blocks }, character_list{ characters },
	interactable_list{ interactables }, height{ height },
	width{ width }, floor{ floor }
{}

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

list<shared_ptr<Block>> Track::get_block_list()
{
	return this->block_list;
}

list<shared_ptr<Character>> Track::get_character_list()
{
	return this->character_list;
}

list<shared_ptr<Interactable>> Track::get_interactable_list()
{
	return this->interactable_list;
}