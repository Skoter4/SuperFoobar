#pragma once
#include "Make_track.h"

using namespace std;

// GLOBAL VARIABLES FOR EASY ACCESS

int GAME_SCALE = 10;
int BLOCK_HEIGHT = GAME_SCALE * 7;
int BLOCK_WIDTH = GAME_SCALE * 7;
int FLOOR = GAME_SCALE * 42;
int TRACK_LENGTH = GAME_SCALE * 400;
int TRACK_HEIGHT = GAME_SCALE * 200;
int FOOBAR_START_POINT = GAME_SCALE * 10;

// END OF GLOBAL VARIABLE DEFINITION

// FUNCTION FITTING COORDINATES INTO GAME WORLD DICTATED BY BLOCK SIZES.
int interp(int val)
{
	int block_size{ ::BLOCK_HEIGHT };
	int half_block{ block_size / 2 };

	if (val % block_size >= half_block)
	{
		val += block_size - val % block_size;
	}
	else if (val % block_size < half_block)
	{
		val -= val % block_size;
	}

	return val;
}

// HELP FUNCTIONS TO EASILY CREATE TRACKS
//----------------------------------------------------------------//

// HELP FUNCTIONS TO ADD LISTS TO LISTS OR ELEMENTS TO LISTS
list<shared_ptr<Block>> add_to_block_list(list<shared_ptr<Block>> & block_list, shared_ptr<Block> block)
{
	block_list.push_front(block);
	return block_list;
}

list<shared_ptr<Block>> add_to_block_list(list<shared_ptr<Block>> & block_list, list<shared_ptr<Block>> other_block_list)
{
	block_list.splice(block_list.end(), other_block_list);
	return block_list;
}

list<shared_ptr<Character>> add_to_character_list(list<shared_ptr<Character>> & character_list, shared_ptr<Character> character)
{
	character_list.push_front(character);
	return character_list;
}

list<shared_ptr<Character>> add_to_character_list(list<shared_ptr<Character>> & character_list, list<shared_ptr<Character>> other_character_list)
{
	character_list.splice(character_list.end(), other_character_list);
	return character_list;
}

list<shared_ptr<Interactable>> add_to_character_list(list<shared_ptr<Interactable>> & interactable_list, shared_ptr<Interactable> interactable)
{
	interactable_list.push_front(interactable);
	return interactable_list;
}

list<shared_ptr<Interactable>> add_to_character_list(list<shared_ptr<Interactable>> & interactable_list, list<shared_ptr<Interactable>> other_interactable_list)
{
	interactable_list.splice(interactable_list.end(), other_interactable_list);
	return interactable_list;
}

// FUNCTIONS TO CREATE SINGLE OBJECTS SUCH AS CHARACTERS, GENERATORS OR INTERACTABLES
shared_ptr<Foobar> make_Foobar()
{
	Foobar* temp_foobar_ptr{ new Foobar{ ::FOOBAR_START_POINT, ::FLOOR, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	std::shared_ptr<sf::Sprite> sprite_ptr{ new sf::Sprite };
	temp_foobar_ptr->setSprite(sprite_ptr);
	shared_ptr<Foobar> foobar_ptr{ temp_foobar_ptr };

	temp_foobar_ptr = nullptr;

	return  move(foobar_ptr);
}

// INSERT ENEMIES HERE----

//------------------------

shared_ptr<Coin> make_coin(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Coin* temp_coin_ptr{ new Coin{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	std::shared_ptr<sf::Sprite> sprite_ptr{ new sf::Sprite };
	temp_coin_ptr->setSprite(sprite_ptr);
	shared_ptr<Coin> coin_ptr{ temp_coin_ptr };

	temp_coin_ptr = nullptr;

	return  move(coin_ptr);
}

shared_ptr<Breakable> make_breakable(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Breakable* temp_breakable_ptr{ new Breakable{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	shared_ptr<Breakable> breakable_ptr{ temp_breakable_ptr };

	temp_breakable_ptr = nullptr;
	std::shared_ptr<sf::Sprite> sprite_ptr{ new sf::Sprite };
	breakable_ptr->setSprite(sprite_ptr);


	return  move(breakable_ptr);

}

shared_ptr<Non_breakable> make_non_breakable(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Non_breakable* temp_non_breakable_ptr{ new Non_breakable{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	std::shared_ptr<sf::Sprite> sprite_ptr{ new sf::Sprite };
	shared_ptr<Non_breakable> non_breakable_ptr{ temp_non_breakable_ptr };
	non_breakable_ptr->setSprite(sprite_ptr);


	temp_non_breakable_ptr = nullptr;

	return  move(non_breakable_ptr);

}


shared_ptr<Generator> make_coin_generator(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Generator* temp_block_ptr{ new Generator{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH, make_coin(x, y + ::BLOCK_HEIGHT)} };
	std::shared_ptr<sf::Sprite> sprite_ptr{ new sf::Sprite };
	shared_ptr<Generator> block_ptr{ temp_block_ptr };
	block_ptr->setSprite(sprite_ptr);
	

	temp_block_ptr = nullptr;

	return  move(block_ptr);
}

shared_ptr<Generator> make_pup_generator(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Interactable* temp_pup_ptr{ new Power_up{ x, y + ::BLOCK_HEIGHT, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };

	shared_ptr<Interactable> pup_ptr{ temp_pup_ptr };

	Generator* temp_block_ptr{ new Generator{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH, pup_ptr } };
	shared_ptr<Generator> block_ptr{ temp_block_ptr };

	std::shared_ptr<sf::Sprite> sprite_ptr{ new sf::Sprite };
	block_ptr->setSprite(sprite_ptr);

	temp_block_ptr = nullptr;

	return  move(block_ptr);
}

shared_ptr<Finish_line> make_Finish_Line(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Finish_line* temp_finish_line_ptr{ new Finish_line{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	shared_ptr<Finish_line> finish_line_ptr{ temp_finish_line_ptr };

	temp_finish_line_ptr = nullptr;

	return  move(finish_line_ptr);

}


// FUNCTIONS TO MASS PRODUCE OBJECTS IN BASIC SHAPES

// FUNCTION THAT CREATES A LIST OF A RECTANGULAR SEGMENT OF SET WIDTH AND HEIGHT OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_rect_seg(int seg_width, int seg_height, int x, int y)
{

	list<shared_ptr<Block>> block_list{};
	list<shared_ptr<Block>>::iterator it;

	seg_width = interp(seg_width);
	seg_height = interp(seg_height);
	x = interp(x);
	y = interp(y);

	int blocks_to_generate_x{ (seg_width / ::BLOCK_WIDTH) };
	int blocks_to_generate_y{ (seg_height / ::BLOCK_HEIGHT) };

	for (int i{}; i < blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k < blocks_to_generate_y; k++)
		{
			block_list.push_front(make_non_breakable(x + i * ::BLOCK_WIDTH, y - k * ::BLOCK_HEIGHT));
		}
	}

	return block_list;
}

// FUNCTION THAT CREATES A LIST OF A FLOOR SEGMENT OF SET LENGTH OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_floor_seg(int seg_length, int x_start)
{
	return make_rect_seg(seg_length, ::BLOCK_HEIGHT, x_start, ::FLOOR + ::BLOCK_HEIGHT);
}

// FUNCTION THAT CREATES A LIST OF A ONE-LINE SEGMENT OF SET LENGTH OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_one_line_seg(int seg_length, int x, int y)
{
	return make_rect_seg(seg_length, ::BLOCK_HEIGHT, x, y);
}

// FUNCTION THAT CREATES A LIST OF A RECTANGULAR SEGMENT OF SET WIDTH AND HEIGHT OUT OF DESTROYABLE BLOCKS.
list<shared_ptr<Block>> make_rect_breakable_seg(int seg_width, int seg_height, int x, int y)
{

	list<shared_ptr<Block>> block_list{};

	seg_width = interp(seg_width);
	seg_height = interp(seg_height);
	x = interp(x);
	y = interp(y);

	int blocks_to_generate_x{ (seg_width / ::BLOCK_WIDTH) };
	int blocks_to_generate_y{ (seg_height / ::BLOCK_HEIGHT) };

	for (int i{}; i < blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k < blocks_to_generate_y; k++)
		{
			block_list.push_front(make_breakable(x + i * ::BLOCK_WIDTH, y - k * ::BLOCK_HEIGHT));

		}
	}

	return block_list;
}

// FUNCTION THAT CREATES A LIST OF A ONE-LINE SEGMENT OF SET LENGTH OUT OF BREAKABLE BLOCKS.
list<shared_ptr<Block>> make_one_line_breakable_seg(int seg_length, int x, int y)
{
	return make_rect_breakable_seg(seg_length, ::BLOCK_HEIGHT, x, y);
}

list<shared_ptr<Interactable>> make_coin_rect_seg(int seg_height, int seg_width, int x, int y)
{

	list<shared_ptr<Interactable>> coin_list{};

	seg_width = interp(seg_width);
	seg_height = interp(seg_height);
	x = interp(x);
	y = interp(y);

	int coins_to_generate_x{ (seg_width / ::BLOCK_WIDTH) };
	int coins_to_generate_y{ (seg_height / ::BLOCK_HEIGHT) };

	for (int i{}; i < coins_to_generate_x; i++)
	{
		int k = 0;
		for (k; k < coins_to_generate_y; k++)
		{
			coin_list.push_front(make_coin(x + i * ::BLOCK_WIDTH, y - k * ::BLOCK_HEIGHT));

		}
	}

	return coin_list;
}

list<shared_ptr<Interactable>> make_coin_row_seg(int seg_length, int x, int y)
{
	return make_coin_rect_seg(seg_length, ::BLOCK_HEIGHT, x, y);
}

std::shared_ptr<Track> make_track(list<shared_ptr<Block>>, list<shared_ptr<Character>>, list<shared_ptr<Interactable>>, int, int, int ) 
{

return 0;
}
