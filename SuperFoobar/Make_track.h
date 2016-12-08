#pragma once
#include "Block-filer\Block.h"
#include "Block-filer\Non_breakable.h"
#include "Block-filer\Breakable.h"
#include "Block-filer\Generator.h"
#include "Interactable-filer\Interactable.h"
#include "Interactable-filer\Coin.h"
#include "Interactable-filer\Power_up.h"
#include "Interactable-filer\Finish_line.h"
#include "Character filer\Character.h"
#include "Character filer\Foobar\Foobar.h"
#include "Character filer\Enemy\Enemy_1.h"
#include "Character filer\Enemy\Enemy_2.h"
#include "Character filer\Enemy\Enemy_2.h"
#include "Map_object.h"
#include "Track.h"
#include <list>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>




int interp(int val);

std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & block_list, std::shared_ptr<Block> block);

std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & block_list, std::list<std::shared_ptr<Block>> other_block_list);

std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & character_list, std::shared_ptr<Character> character);

std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & character_list, std::list<std::shared_ptr<Character>> other_character_list);

std::list<std::shared_ptr<Interactable>> add_to_character_list(std::list<std::shared_ptr<Interactable>> & interactable_list, std::shared_ptr<Interactable> interactable);

std::list<std::shared_ptr<Interactable>> add_to_character_list(std::list<std::shared_ptr<Interactable>> & interactable_list, std::list<std::shared_ptr<Interactable>> other_interactable_list);

std::shared_ptr<Foobar> make_Foobar();

std::shared_ptr<Coin> make_coin(int x, int y);

std::shared_ptr<Breakable> make_breakable(int x, int y);

std::shared_ptr<Non_breakable> make_non_breakable(int x, int y);

std::shared_ptr<Generator> make_coin_generator(int x, int y);

std::shared_ptr<Generator> make_pup_generator(int x, int y);

std::shared_ptr<Finish_line> make_Finish_Line(int x, int y);

std::list<std::shared_ptr<Block>> make_rect_seg(int seg_width, int seg_height, int x, int y);

std::list<std::shared_ptr<Block>> make_floor_seg(int seg_length, int x_start);

std::list<std::shared_ptr<Block>> make_one_line_seg(int seg_length, int x, int y);

std::list<std::shared_ptr<Block>> make_rect_breakable_seg(int seg_width, int seg_height, int x, int y);

std::list<std::shared_ptr<Block>> make_one_line_breakable_seg(int seg_length, int x, int y);

std::list<std::shared_ptr<Interactable>> make_coin_rect_seg(int seg_height, int seg_width, int x, int y);

std::list<std::shared_ptr<Interactable>> make_coin_row_seg(int seg_length, int x, int y);

std::shared_ptr<Track> make_track(std::list<std::shared_ptr<Block>>,
	std::list<std::shared_ptr<Character>>,
	std::list<std::shared_ptr<Interactable>>,
	int, int, int);