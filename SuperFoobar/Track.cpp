#include "Track.h"

using namespace std;

Track::Track(initializer_list<shared_ptr<Block>> blocks,
	initializer_list<shared_ptr<Character>> characters,
	initializer_list<shared_ptr<Interactable>> interactables,
	float width, float height, float floor)
	:block_list{ move(blocks) }, character_list{ move(characters) },
	interactable_list{ move(interactables) }, height{ height },
	width{ width }, floor{ floor }
{}

float Track::get_floor()
{
	return this->floor;
}

float Track::get_height()
{
	return this->height;
}

float Track::get_width()
{
	return this->width;
}

void Track::set_floor(float new_floor)
{
	this->floor = new_floor;
}

void Track::set_height(float new_height)
{
	this->height = new_height;
}

void Track::set_width(float new_width)
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