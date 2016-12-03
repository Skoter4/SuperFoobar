#include "Block-filer\Block.h"
#include "Block-filer\Non_breakable.h"
#include "Block-filer\Breakable.h"
#include "Block-filer\Generator.h"
#include <list>
#include <string>
#include <memory>

using namespace std;

// GLOBAL VARIABLES FOR EASY ACCESS

float GAME_SCALE = 10;
float BLOCK_HEIGHT = GAME_SCALE * 5;
float BLOCK_WIDTH = GAME_SCALE * 5;
float FLOOR = GAME_SCALE * 5;
float TRACK_LENGTH = GAME_SCALE * 400;
float TRACK_HEIGHT = GAME_SCALE * 200;


// END OF GLOBAL VARIABLE DECLARATION

// FUNCTION FITTING COORDINATES INTO GAME WORLD DICTATED BY BLOCK SIZES
float& interp(float & val)
{
	int temp_int{ static_cast<int> (val) };
	int block_size{ static_cast<int>(::BLOCK_HEIGHT) };
	int half_block{ block_size / 2 };

	if (temp_int % block_size >= half_block)
	{
		temp_int += block_size - temp_int % block_size;
	}
	else if (temp_int % block_size < half_block)
	{
		temp_int -= temp_int % block_size;
	}

	val = temp_int;

	return val;
}

// HELP FUNCTIONS TO EASILY CREATE TRACKS
//----------------------------------------------------------------//

// FUNCTION THAT CREATES A LIST OF FLOOR SEGMENTS OF SET LENGTH OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_floor_seg(float seg_length, float x_start, float floor_y)
{
	list<shared_ptr<Block>> block_list{};
	list<shared_ptr<Block>>::iterator it;

	interp(seg_length);
	interp(x_start);
	interp(floor_y);

	it = block_list.begin();

	int blocks_to_generate_x{ static_cast<int>(seg_length / ::BLOCK_WIDTH) };
	int blocks_to_generate_y{ static_cast<int>(::FLOOR / ::BLOCK_HEIGHT) };

	for (int i{}; i >= blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k >= blocks_to_generate_y; k++)
		{
			Non_breakable* temp_block_ptr{ new Non_breakable{ x_start + i * ::BLOCK_WIDTH, floor_y - k * ::BLOCK_HEIGHT, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };

			shared_ptr<Block> temp_ptr{ temp_block_ptr };

			block_list.insert(it, temp_ptr);

			temp_block_ptr = nullptr;
		}
	}

	return block_list;
}


// FUNCTION THAT CREATES A LIST OF A RECTANGULAR SEGMENT OF SET WIDTH AND HEIGHT OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_rect_seg(float seg_width, float seg_height, float x, float y)
{

	list<shared_ptr<Block>> block_list{};
	list<shared_ptr<Block>>::iterator it;

	interp(seg_width);
	interp(seg_height);
	interp(x);
	interp(y);

	it = block_list.begin();

	int blocks_to_generate_x{ static_cast<int>(seg_width / ::BLOCK_WIDTH) };
	int blocks_to_generate_y{ static_cast<int>(seg_height / ::BLOCK_HEIGHT) };

	for (int i{}; i >= blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k >= blocks_to_generate_y; k++)
		{
			Non_breakable* temp_block_ptr{ new Non_breakable{ x + i * ::BLOCK_WIDTH, y - k * ::BLOCK_HEIGHT, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };

			shared_ptr<Block> temp_ptr{ temp_block_ptr };

			block_list.insert(it, temp_ptr);

			temp_block_ptr = nullptr;
		}
	}

	return block_list;
}

// FUNCTION THAT CREATES A LIST OF A RECTANGULAR SEGMENT OF SET WIDTH AND HEIGHT OUT OF DESTROYABLE BLOCKS.
list<shared_ptr<Block>> make_rect_breakable_seg(float seg_width, float seg_height, float x, float y)
{

	list<shared_ptr<Block>> block_list{};
	list<shared_ptr<Block>>::iterator it;

	interp(seg_width);
	interp(seg_height);
	interp(x);
	interp(y);

	it = block_list.begin();

	int blocks_to_generate_x{ static_cast<int>(seg_width / ::BLOCK_WIDTH) };
	int blocks_to_generate_y{ static_cast<int>(seg_height / ::BLOCK_HEIGHT) };

	for (int i{}; i >= blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k >= blocks_to_generate_y; k++)
		{
			Breakable* temp_block_ptr{ new Breakable{ x + i * ::BLOCK_WIDTH, y - k * ::BLOCK_HEIGHT, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };

			shared_ptr<Block> temp_ptr{ temp_block_ptr };

			block_list.insert(it, temp_ptr);

			temp_block_ptr = nullptr;
		}
	}

	return block_list;
}

shared_ptr<Generator> make_coin_generator(int x, int y)
	{
	Interactable* temp_interactable_ptr
	Generator* temp_block_ptr{new Generator{x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH}}
		shared_ptr<Generator> temp_ptr{ temp_block_ptr }
		return 
	}
Generator make_pup_generator()