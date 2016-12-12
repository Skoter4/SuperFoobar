#pragma once
#include "Make_track.h"

using namespace std;

// GLOBAL VARIABLES FOR EASY ACCESS

int GAME_SCALE = 10;
int BLOCK_HEIGHT = GAME_SCALE * 7;
int BLOCK_WIDTH = GAME_SCALE * 7;
int FLOOR = BLOCK_HEIGHT * 11;
int TRACK_WIDTH = GAME_SCALE * ::BLOCK_WIDTH * 100;
int TRACK_HEIGHT = GAME_SCALE *  ::BLOCK_HEIGHT *  12;
int FOOBAR_START_POINT = GAME_SCALE * 2;
int WINDOW_WIDTH = ::BLOCK_WIDTH * 16;
int WINDOW_HEIGHT = ::BLOCK_HEIGHT * 12;

sf::Texture SUPER_FOOBAR_TEXTURES{};

sf::IntRect Foobar_R_pic(150, 0, 50, 50);
sf::IntRect Foobar_L_pic(200, 0, 50, 50);
sf::IntRect Foobar_HR_pic(0, 191, 50, 100);
sf::IntRect Foobar_HL_pic(50, 191, 50, 100);
sf::IntRect Foobar_DR_pic(149, 171, 50, 50);
sf::IntRect Foobar_DL_pic(199, 171, 50, 50);
sf::IntRect Enemy1_pic(100, 0, 50, 50);
sf::IntRect Enemy2_pic(0, 0, 50, 50);
sf::IntRect Enemy3_pic(50, 0, 50, 50);
sf::IntRect Proj_L_pic(120, 145, 50, 25);
sf::IntRect Floor_pic(70, 50, 70, 70);
sf::IntRect Breakable_pic(0, 50, 70, 70);
sf::IntRect Non_Breakable_pic(209, 50, 70, 70);
sf::IntRect Generator_pic(140, 50, 70, 70);
sf::IntRect Used_Generator_pic(0, 120, 70, 70);
sf::IntRect Coin_pic(172, 122, 40, 48);
sf::IntRect Power_Up_1_pic(211, 120, 50, 50);
sf::IntRect Finish_Line_pic(107, 222, 63, 68);
sf::IntRect Power_Up_2_pic(103, 173, 50, 50);

// END OF GLOBAL VARIABLE DEFINITION

// FUNCTION FITTING COORDINATES INTO GAME WORLD DICTATED BY BLOCK SIZES.
int interp(int val)
{
	return val * ::BLOCK_HEIGHT;
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

list<shared_ptr<Interactable>> add_to_interactable_list(list<shared_ptr<Interactable>> & interactable_list, shared_ptr<Interactable> interactable)
{
	interactable_list.push_front(interactable);
	return interactable_list;
}

list<shared_ptr<Interactable>> add_to_interactable_list(list<shared_ptr<Interactable>> & interactable_list, list<shared_ptr<Interactable>> other_interactable_list)
{
	interactable_list.splice(interactable_list.end(), other_interactable_list);
	return interactable_list;
}

// FUNCTIONS TO CREATE SINGLE OBJECTS SUCH AS CHARACTERS, GENERATORS OR INTERACTABLES
shared_ptr<Foobar> make_foobar()
{
	Foobar* temp_foobar_ptr{ new Foobar{ ::FOOBAR_START_POINT, ::FLOOR - ::BLOCK_HEIGHT,50,50} };
	
	shared_ptr<Foobar> foobar_ptr{ temp_foobar_ptr };

	std::shared_ptr<sf::Sprite> new_sprite{ new sf::Sprite };
	foobar_ptr->setSprite(new_sprite);

	temp_foobar_ptr = nullptr;

	return  move(foobar_ptr);
}

shared_ptr<Enemy_1> make_enemy_1(int x, int y)
{
	x = interp(x);
	y = interp(y);
	Enemy_1* temp_enemy_1_ptr{ new Enemy_1{ x + 10, y + 20, ::BLOCK_HEIGHT - 20, ::BLOCK_WIDTH - 20, make_projectile(x ,y) } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_enemy_1_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Enemy_1> enemy_1_ptr{ temp_enemy_1_ptr };

	temp_enemy_1_ptr = nullptr;

	return  move(enemy_1_ptr);
}

shared_ptr<Enemy_2> make_enemy_2(int x, int y)
{
	x = interp(x);
	y = interp(y);
	Enemy_2* temp_enemy_2_ptr{ new Enemy_2{ x + 10, y + 20, ::BLOCK_HEIGHT - 20, ::BLOCK_WIDTH - 20 } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_enemy_2_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Enemy_2> enemy_2_ptr{ temp_enemy_2_ptr };

	temp_enemy_2_ptr = nullptr;

	return  move(enemy_2_ptr);
}

shared_ptr<Enemy_3> make_enemy_3(int x, int y)
{
	x = interp(x);
	y = interp(y);
	Enemy_3* temp_enemy_3_ptr{ new Enemy_3{ x + 10, y + 20, ::BLOCK_HEIGHT-20, ::BLOCK_WIDTH-20 } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_enemy_3_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Enemy_3> enemy_3_ptr{ temp_enemy_3_ptr };

	temp_enemy_3_ptr = nullptr;

	return  move(enemy_3_ptr);
}
//------------------------

shared_ptr<Coin> make_coin(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Coin* temp_coin_ptr{ new Coin{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_coin_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Coin> coin_ptr{ temp_coin_ptr };


	return  move(coin_ptr);
}

shared_ptr<Power_up> make_pup(int x, int y, string type)
{
	x = interp(x);
	y = interp(y);

	Power_up* temp_pup_ptr{ new Power_up{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_pup_ptr->setSprite(new_sprite_ptr);

	shared_ptr<Power_up> pup_ptr{ temp_pup_ptr };
	temp_pup_ptr = nullptr;

	pup_ptr->set_type(type);

	return  move(pup_ptr);
}

shared_ptr<Breakable> make_breakable(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Breakable* temp_breakable_ptr{ new Breakable{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_breakable_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Breakable> breakable_ptr{ temp_breakable_ptr };

	temp_breakable_ptr = nullptr;

	return  move(breakable_ptr);

}

shared_ptr<Non_breakable> make_non_breakable(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Non_breakable* temp_non_breakable_ptr{ new Non_breakable{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_non_breakable_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Non_breakable> non_breakable_ptr{ temp_non_breakable_ptr };

	temp_non_breakable_ptr = nullptr;

	return  move(non_breakable_ptr);

}


shared_ptr<Generator> make_coin_generator(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Generator* temp_block_ptr{ new Generator{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH, make_coin(x /::BLOCK_HEIGHT, (y - ::BLOCK_HEIGHT)/::BLOCK_HEIGHT)} };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_block_ptr->setSprite(new_sprite_ptr);
	shared_ptr<Generator> block_ptr{ temp_block_ptr };

	temp_block_ptr = nullptr;

	return  move(block_ptr);
}

shared_ptr<Generator> make_pup_generator(int x, int y, string type)
{
	x = interp(x);
	y = interp(y);

	Generator* temp_block_ptr{ new Generator{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH, make_pup(x/::BLOCK_HEIGHT, (y - ::BLOCK_HEIGHT)/::BLOCK_HEIGHT, type) } };
	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_block_ptr->setSprite(new_sprite_ptr);

	shared_ptr<Generator> block_ptr{ temp_block_ptr };
	temp_block_ptr = nullptr;

	return  move(block_ptr);
}

shared_ptr<Finish_line> make_Finish_Line(int x, int y)
{
	x = interp(x);
	y = interp(y);

	Finish_line* temp_finish_line_ptr{ new Finish_line{ x, y, ::BLOCK_HEIGHT, ::BLOCK_WIDTH } };

	std::shared_ptr<sf::Sprite> new_sprite_ptr{ new sf::Sprite };
	temp_finish_line_ptr->setSprite(new_sprite_ptr);

	shared_ptr<Finish_line> finish_line_ptr{ temp_finish_line_ptr };


	temp_finish_line_ptr = nullptr;

	return  move(finish_line_ptr);

}

shared_ptr<Projectile> make_projectile(int x, int y) {
	// = interp(x);
	//y = interp(y);

	Projectile* temp_projectile_ptr{ new Projectile {x - 10, y, ::BLOCK_HEIGHT - 20, ::BLOCK_WIDTH - 20} };
	
	std::shared_ptr<sf::Sprite> new_sprite_ptr { new sf::Sprite };
	temp_projectile_ptr->setSprite(new_sprite_ptr);

	shared_ptr<Projectile> projectile_ptr{ temp_projectile_ptr };

	temp_projectile_ptr = nullptr;

	return move(projectile_ptr);
}


// FUNCTIONS TO MASS PRODUCE OBJECTS IN BASIC SHAPES

// FUNCTION THAT CREATES A LIST OF A RECTANGULAR SEGMENT OF SET WIDTH AND HEIGHT OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_rect_seg(int seg_width, int seg_height, int x, int y)
{

	list<shared_ptr<Block>> block_list{};

	int blocks_to_generate_x{ seg_width };
	int blocks_to_generate_y{ seg_height };

	for (int i{}; i < blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k < blocks_to_generate_y; k++)
		{
			block_list.push_front(make_non_breakable(x + i, y + k));
		}
	}

	return block_list;
}

// FUNCTION THAT CREATES A LIST OF A FLOOR SEGMENT OF SET LENGTH OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_floor_seg(int seg_length, int x_start)
{
	return make_rect_seg(seg_length, 1, x_start, ::FLOOR /::BLOCK_HEIGHT);
}

// FUNCTION THAT CREATES A LIST OF A ONE-LINE SEGMENT OF SET LENGTH OUT OF INVURNABLE BLOCKS.
list<shared_ptr<Block>> make_one_line_seg(int seg_length, int x, int y)
{
	return make_rect_seg(seg_length, 1, x, y);
}

// FUNCTION THAT CREATES A LIST OF A RECTANGULAR SEGMENT OF SET WIDTH AND HEIGHT OUT OF DESTROYABLE BLOCKS.
list<shared_ptr<Block>> make_rect_breakable_seg(int seg_width, int seg_height, int x, int y)
{

	list<shared_ptr<Block>> block_list{};


	int blocks_to_generate_x{ seg_width };
	int blocks_to_generate_y{ seg_height  };

	for (int i{}; i < blocks_to_generate_x; i++)
	{
		int k = 0;
		for (k; k < blocks_to_generate_y; k++)
		{
			block_list.push_front(make_breakable(x + i, y + k ));

		}
	}

	return block_list;
}

// FUNCTION THAT CREATES A LIST OF A ONE-LINE SEGMENT OF SET LENGTH OUT OF BREAKABLE BLOCKS.
list<shared_ptr<Block>> make_one_line_breakable_seg(int seg_length, int x, int y)
{
	return make_rect_breakable_seg(seg_length, 1, x, y);
}

// FUNCTION THAT CREATES A LIST OF A ONE-LINE SEGMENT OF SET LENGTH OUT OF COINS.
list<shared_ptr<Interactable>> make_coin_rect_seg(int seg_width, int seg_height, int x, int y)
{

	list<shared_ptr<Interactable>> coin_list{};

	int coins_to_generate_x{ seg_width};
	int coins_to_generate_y{ seg_height};

	for (int i{}; i < coins_to_generate_x; i++)
	{
		int k = 0;
		for (k; k < coins_to_generate_y; k++)
		{
			coin_list.push_front(make_coin(x + i, y + k));

		}
	}

	return coin_list;
}

list<shared_ptr<Interactable>> make_coin_row_seg(int seg_length, int x, int y)
{
	return make_coin_rect_seg(seg_length, 1, x, y);
}


shared_ptr<Track> make_track(list<shared_ptr<Block>> & blocks, list<shared_ptr<Character>> & characters, list<shared_ptr<Interactable>> & interactables)
{
	Track* temp_ptr{ new Track{blocks, characters, interactables, ::TRACK_WIDTH, ::TRACK_HEIGHT, ::FLOOR} };
	shared_ptr<Track> temp_track_ptr{ temp_ptr };

	temp_ptr = nullptr;

	return move(temp_track_ptr);
}

void update_sprite_position(shared_ptr<Map_object> MO)
{
	MO->get_sprite()->setPosition(static_cast<float>(MO->get_x_pos()), static_cast<float>(MO->get_y_pos()));
}

void update_sprite_texture(shared_ptr<Map_object> MO, sf::Texture &texture, sf::IntRect rect)
{
	MO->get_sprite()->setTexture(texture);
	MO->get_sprite()->setTextureRect(rect);
}


// FUNCTION TO UPDATE SPRITES POSITION AND TEXTURE TO THE RIGHT ONE
// INDIVUAL IF CLAUSES CAN AFFECT SPRITE LOOK (FOR EXAMPLE FOOBAR FACE DIRECTION)
void update_sprite(shared_ptr<Map_object> MO)
{
	if (MO->type_str() == "foobar")
	{
		if (MO->get_height() > 50)
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Foobar_HR_pic);
		else
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Foobar_R_pic);
	}
	else if (MO->type_str() == "enemy_1")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Enemy1_pic);
	}
	else if (MO->type_str() == "enemy_2")
	{
		if (dynamic_pointer_cast<Enemy_2>(MO)->get_x_velocity() >= 0)
		{
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Enemy2_pic);
			MO->get_sprite()->setScale(-1.f, 1.f);
		}
		else 
		{
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Enemy2_pic);
			MO->get_sprite()->setScale(1.f, 1.f);
		}
	}
	else if (MO->type_str() == "enemy_3")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Enemy3_pic);
	}
	else if (MO->type_str() == "breakable")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Breakable_pic);
	}
	else if (MO->type_str() == "non_breakable")
	{
		if (MO->get_y_pos() == ::FLOOR)
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Floor_pic);
		else 
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Non_Breakable_pic);
	}
	else if (MO->type_str() == "generator")
	{
		shared_ptr<Generator> generator_ptr{ dynamic_pointer_cast<Generator>(MO) };
		if (generator_ptr->is_deactivated())
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Used_Generator_pic);
		else
			update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Generator_pic);
	}
	else if (MO->type_str() == "coin")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Coin_pic);
	}
	else if (MO->type_str() == "power_up_shroom")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Power_Up_1_pic);
	}
	else if (MO->type_str() == "finish_line")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Finish_Line_pic);
	}
	else if (MO->type_str() == "power_up_star")
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Power_Up_2_pic);
	}
	else if (MO->type_str() == "projectile") 
	{
		update_sprite_texture(MO, ::SUPER_FOOBAR_TEXTURES, ::Proj_L_pic);
	}
	update_sprite_position(MO);

}

void update_sprite(list<shared_ptr<Interactable>> interactable_list)
{
	for (auto it = interactable_list.begin(); it != interactable_list.end(); ++it)
	{
		update_sprite(*it);
	}
}

void update_sprite(list<shared_ptr<Block>> block_list)
{
	for (auto it = block_list.begin(); it != block_list.end(); ++it)
	{
		update_sprite(*it);
	}
}

void update_sprite(list<shared_ptr<Character>> character_list)
{
	for (auto it = character_list.begin(); it != character_list.end(); ++it)
	{
		update_sprite(*it);
	}
}

void update_sprite(shared_ptr<Track> track)
{
	update_sprite(track->get_block_list());
	update_sprite(track->get_character_list());
	update_sprite(track->get_interactable_list());
}

void init_sprite(shared_ptr<Track> track)
{
	update_sprite(track);
}

void update_sprite_position(list<shared_ptr<Block>> block_list)
{
	for (auto it = block_list.begin(); it != block_list.end(); ++it)
	{
		update_sprite_position(*it);
	}
}

void update_sprite_position(list<shared_ptr<Character>> character_list)
{
	for (auto it = character_list.begin(); it != character_list.end(); ++it)
	{
		update_sprite_position(*it);
	}
}


void update_sprite_position(list<shared_ptr<Interactable>> interactable_list)
{
	for (auto it = interactable_list.begin(); it != interactable_list.end(); ++it)
	{
		update_sprite_position(*it);
	}
}

void update_sprite_position(shared_ptr<Track> track)
{
	update_sprite_position(track->get_block_list());
	update_sprite_position(track->get_character_list());
	update_sprite_position(track->get_interactable_list());
}

void draw_list(list<shared_ptr<Character>> & character_list, sf::RenderWindow & game_window)
{
	for (auto it = character_list.begin(); it != character_list.end(); ++it)
	{
		game_window.draw(*(*it)->get_sprite());
	}
}

void draw_list(list<shared_ptr<Block>> & block_list, sf::RenderWindow & game_window)
{
	for (auto it = block_list.begin(); it != block_list.end(); ++it)
	{
		game_window.draw(*(*it)->get_sprite());
	}
}

void draw_list(list<shared_ptr<Interactable>> & interactable_list, sf::RenderWindow & game_window)
{
	for (auto it = interactable_list.begin(); it != interactable_list.end(); ++it)
	{
		game_window.draw(*(*it)->get_sprite());
	}
}

void draw_track(shared_ptr<Track> track, sf::RenderWindow & game_window)
{
	draw_list(track->get_character_list(), game_window);
	draw_list(track->get_block_list(), game_window);
	draw_list(track->get_interactable_list(), game_window);
}

list<shared_ptr<Block>> & operator+(list<shared_ptr<Block>> & blocks, shared_ptr<Block> new_block)
{
	blocks.push_front(new_block);
	return blocks;
}

list<shared_ptr<Character>> & operator+(list<shared_ptr<Character>> & characters, shared_ptr<Character> new_character)
{
	characters.push_front(new_character);
	return characters;
}

list<shared_ptr<Interactable>> & operator+(list<shared_ptr<Interactable>> & interactables, shared_ptr<Interactable> new_interactable)
{
	interactables.push_front(new_interactable);
	return interactables;
}

list<shared_ptr<Block>> & operator+(list<shared_ptr<Block>> & blocks, list<shared_ptr<Block>> other_blocks)
{
	add_to_block_list(blocks, other_blocks);
	return blocks;
}

list<shared_ptr<Character>> & operator+(list<shared_ptr<Character>> & characters, list<shared_ptr<Character>> other_characters)
{
	add_to_character_list(characters, other_characters);
	return characters;
}

list<shared_ptr<Interactable>> & operator+(list<shared_ptr<Interactable>> & interactables, list<shared_ptr<Interactable>> other_interactables)
{
	add_to_interactable_list(interactables, other_interactables);
	return interactables;
}