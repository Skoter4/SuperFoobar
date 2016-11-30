#include "Block-filer\Non_breakable.h"
#include <list>
#include <string>
#include <memory>

using namespace std;

//---------------- GLOBAL VARIABLES FOR EASY ACCESS-------------------//

float GAME_SCALE = 10;
float BLOCK_HEIGHT = GAME_SCALE * 5;
float BLOCK_WIDTH = GAME_SCALE * 5;
float FLOOR = GAME_SCALE * 5;
float TRACK_LENGTH = GAME_SCALE * 400;

//----------------END OF GLOBAL VARIABLE DECLARATION-----------------//

//----------------HELP FUNCTIONS TO EASILY CREATE TRACKS-------------//

list<shared_ptr<Block>> make_floor_seg(float floor_length, float x, float floor)
{
	list<shared_ptr<Block>> block_list{};
	list<shared_ptr<Block>>::iterator it;
	it = block_list.begin();
	int blocks_to_generate{ static_cast<int>(floor_length / ::BLOCK_WIDTH) };

	for (int i; i >= blocks_to_generate; i++)
	{	
		Non_breakable* temp_block_ptr{ new Non_breakable{ x * i * ::BLOCK_WIDTH, floor, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };

		shared_ptr<Non_breakable> temp_ptr{ temp_block_ptr };

		block_list.insert(it, temp_ptr);

		temp_block_ptr = nullptr;
	}

	return block_list;
}