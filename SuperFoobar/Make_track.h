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
#include "Character filer\Enemy\Enemy_3.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Track.h"
#include <list>
#include <string>
#include <memory>

extern sf::Texture SUPER_FOOBAR_TEXTURES;

int interp(int val);

std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & , std::shared_ptr<Block> );

std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & , std::list<std::shared_ptr<Block>> );

std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & , std::shared_ptr<Character> );

std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & , std::list<std::shared_ptr<Character>> );

std::list<std::shared_ptr<Interactable>> add_to_interactable_list(std::list<std::shared_ptr<Interactable>> & , std::shared_ptr<Interactable> );

std::list<std::shared_ptr<Interactable>> add_to_interactable_list(std::list<std::shared_ptr<Interactable>> & , std::list<std::shared_ptr<Interactable>> );

std::shared_ptr<Foobar> make_foobar();

std::shared_ptr<Enemy_1> make_enemy_1(int , int );

std::shared_ptr<Coin> make_coin(int , int );

std::shared_ptr<Power_up> make_pup(int , int , std::string );

std::shared_ptr<Breakable> make_breakable(int , int );

std::shared_ptr<Non_breakable> make_non_breakable(int , int );

std::shared_ptr<Generator> make_coin_generator(int , int );

std::shared_ptr<Generator> make_pup_generator(int , int , std::string );

std::shared_ptr<Finish_line> make_Finish_Line(int , int );

std::list<std::shared_ptr<Block>> make_rect_seg(int , int , int , int );

std::list<std::shared_ptr<Block>> make_floor_seg(int , int );

std::list<std::shared_ptr<Block>> make_one_line_seg(int , int , int);

std::list<std::shared_ptr<Block>> make_rect_breakable_seg(int , int , int , int );

std::list<std::shared_ptr<Block>> make_one_line_breakable_seg(int , int , int);

std::list<std::shared_ptr<Interactable>> make_coin_row_seg(int , int , int );

std::list<std::shared_ptr<Interactable>> make_coin_rect_seg(int , int , int , int );

std::shared_ptr<Track> make_track(std::list<std::shared_ptr<Block>> & , std::list<std::shared_ptr<Character>> & , std::list<std::shared_ptr<Interactable>> & );

void update_sprite_position(std::shared_ptr<Map_object>);

void update_sprite_texture(std::shared_ptr<Map_object>, sf::Texture &, sf::IntRect);

void update_sprite(std::shared_ptr<Map_object>);

void update_sprite(std::list<std::shared_ptr<Character>>);

void update_sprite(std::list<std::shared_ptr<Block>>);

void update_sprite(std::list<std::shared_ptr<Interactable>>);

void update_sprite(std::shared_ptr<Track> track);

void draw_list(std::list<std::shared_ptr<Interactable>> &, sf::RenderWindow &);

void draw_list(std::list<std::shared_ptr<Character>> &, sf::RenderWindow &);

void draw_list(std::list<std::shared_ptr<Block>> &, sf::RenderWindow &);

void draw_track(std::shared_ptr<Track>, sf::RenderWindow &);

std::list<std::shared_ptr<Block>> & operator+(std::list<std::shared_ptr<Block>> &, std::shared_ptr<Block>);

std::list<std::shared_ptr<Character>> & operator+(std::list<std::shared_ptr<Character>> &, std::shared_ptr<Character>);

std::list<std::shared_ptr<Interactable>> & operator+(std::list<std::shared_ptr<Interactable>> &, std::shared_ptr<Interactable>);