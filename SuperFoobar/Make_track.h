/*
* FILENAME:       Make_track.h
* PROGRAMMERS: Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* Make_track is a comprehensive file containing all the "make" functions, which are used to easily create and contain the different objects
* that the game contains. It includes every object filed that is to be created or from where it inherits, in order to easily create the lists
* as well as add Map_objects to them. It also has functionality to update sprite position and texture more easily.
*/
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
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Track.h"
#include <list>
#include <string>
#include <memory>

/*
* Variables declared as a global for access externally.
*/
extern sf::Texture SUPER_FOOBAR_TEXTURES;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;


/*
* FUNCTION: int interp(int val);
* Function that multiplies given value by the height of a block.
*/

int interp(int val);


/*
* FUNCTION: std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & , std::shared_ptr<Block> );
* Function that adds a Block pointer to a list of Block pointers.
*/

std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & , std::shared_ptr<Block> );

/*
* FUNCTION: std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & , std::shared_ptr<Block> );
* Function that utilizes the list.splice(other) member function to add all pointers of other to referenced list.
*/

std::list<std::shared_ptr<Block>> add_to_block_list(std::list<std::shared_ptr<Block>> & , std::list<std::shared_ptr<Block>> );

/*
* FUNCTION: std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & , std::shared_ptr<Character> );
* Function that adds a Character pointer to a list of Character pointers.
*/


std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & , std::shared_ptr<Character> );

/*
* FUNCTION: std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & , std::list<std::shared_ptr<Character>> );
* Function that utilizes the list.splice(other) member function to add all pointers of other to referenced list.
*/

std::list<std::shared_ptr<Character>> add_to_character_list(std::list<std::shared_ptr<Character>> & , std::list<std::shared_ptr<Character>> );

/*
* FUNCTION: std::list<std::shared_ptr<Interactable>> add_to_interactable_list(std::list<std::shared_ptr<Interactable>> & , std::shared_ptr<Interactable> );
* Function that adds a Interactable pointer to a list of Interactable pointers.
*/

std::list<std::shared_ptr<Interactable>> add_to_interactable_list(std::list<std::shared_ptr<Interactable>> & , std::shared_ptr<Interactable> );

/*
* FUNCTION: std::list<std::shared_ptr<Interactable>> add_to_interactable_list(std::list<std::shared_ptr<Interactable>> & , std::list<std::shared_ptr<Interactable>> );
* Function that utilizes the list.splice(other) member function to add all pointers of other to referenced list.
*/

std::list<std::shared_ptr<Interactable>> add_to_interactable_list(std::list<std::shared_ptr<Interactable>> & , std::list<std::shared_ptr<Interactable>> );

/*
* FUNCTION: std::shared_ptr<Foobar> make_foobar();
* Function that calls the constructor of the type Foobar with preset values and setting a sprite object with same dimensions.
*/

std::shared_ptr<Foobar> make_foobar();

/*
* FUNCTION: std::shared_ptr<Enemy_1> make_enemy_1(int , int);
* Function that calls the constructor of the type Enemy_1 with preset values and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Enemy_1> make_enemy_1(int , int);

/*
* FUNCTION: std::shared_ptr<Enemy_2> make_enemy_1(int , int);
* Function that calls the constructor of the type Enemy_2 with preset values and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Enemy_2> make_enemy_2(int, int);

/*
* FUNCTION: std::shared_ptr<Enemy_3> make_enemy_1(int , int);
* Function that calls the constructor of the type Enemy_3 with preset values and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Enemy_3> make_enemy_3(int, int);

/*
* FUNCTION: std::shared_ptr<Coin> make_coin(int , int);
* Function that calls the constructor of the type Coin with preset values and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Coin> make_coin(int , int);

/*
* FUNCTION: std::shared_ptr<Power_up> make_pup(int , int, std::string);
* Function that calls the constructor of the type Power_up with preset values and setting a sprite object with same dimensions. Requires x and y coordinates,
* as well as a string to diiferentiate shroom and star.      
*/

std::shared_ptr<Power_up> make_pup(int , int , std::string );

/*
* FUNCTION: std::shared_ptr<Breakable> make_breakable(int , int );
* Function that calls the constructor of the type Breakable with preset values and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Breakable> make_breakable(int , int );

/*
* FUNCTION: std::shared_ptr<Non_breakable> make_non_breakable(int , int );
* Function that calls the constructor of the type Non_beakable with preset values and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Non_breakable> make_non_breakable(int , int );

/*
* FUNCTION: std::shared_ptr<Generator> make_coin_generator(int , int );
* Function that calls the constructor of the type Generator with preset values, most notably a pointer to a Coin object, and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Generator> make_coin_generator(int , int );

/*
* FUNCTION: std::shared_ptr<Generator> make_pup_generator(int , int, std::string);
* Function that calls the constructor of the type Generator with preset values, most uses make_coin and saves its pointer as a member, and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Generator> make_pup_generator(int , int , std::string );

/*
* FUNCTION: std::shared_ptr<Finish_line> make_Finish_Line(int , int);
* Function that calls the constructor of the type Finish_Line with preset values, and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Finish_line> make_Finish_Line(int , int );

/*
* FUNCTION: std::shared_ptr<Projectile> make_projectile(int, int);
* Function that calls the constructor of the type Projectile with preset values, and setting a sprite object with same dimensions. Requires x and y coordinates.
*/

std::shared_ptr<Projectile> make_projectile(int, int);

/*
* FUNCTION: std::list<std::shared_ptr<Block>> make_rect_seg(int, int, int, int);
* Function that returns a list constructed of Non_breakable objects forming a rectangle of given height and width at position x and y.
*/

std::list<std::shared_ptr<Block>> make_rect_seg(int, int, int, int);

/*
* FUNCTION: std::list<std::shared_ptr<Block>> make_floor_seg(int , int );
* Function that returns a list constructed of Non_breakable objects forming a rectangle of one blocks height and given width at position x and predetermined y.
*/

std::list<std::shared_ptr<Block>> make_floor_seg(int , int );

/*
* FUNCTION: std::list<std::shared_ptr<Block>> make_one_line_seg(int , int , int);
* Function that returns a list constructed of Non_breakable objects forming a rectangle of one block's height and given width at position x and y.
*/

std::list<std::shared_ptr<Block>> make_one_line_seg(int , int , int);

/*
* FUNCTION: std::list<std::shared_ptr<Block>> make_rect_breakable_seg(int , int , int , int );
* Function that returns a list constructed of Breakable objects forming a rectangle of given height and width at position x and y.
*/

std::list<std::shared_ptr<Block>> make_rect_breakable_seg(int , int , int , int );

/*
* FUNCTION: std::list<std::shared_ptr<Block>> make_one_line_breakable_seg(int , int , int);
* Function that returns a list constructed of Breakable objects forming a rectangle of one block's height and given width at position x and y.
*/

std::list<std::shared_ptr<Block>> make_one_line_breakable_seg(int , int , int);

/*
* FUNCTION: std::list<std::shared_ptr<Interactable>> make_coin_row_seg(int , int , int );
* Function that returns a list constructed of Coin objects forming a line of one coin's height and given width at position x and y.
*/

std::list<std::shared_ptr<Interactable>> make_coin_row_seg(int , int , int );

/*
* FUNCTION: std::list<std::shared_ptr<Interactable>> make_coin_rect_seg(int , int , int , int );
* Function that returns a list constructed of Coin objects forming a rectangle of given height and width at position x and y.
*/

std::list<std::shared_ptr<Interactable>> make_coin_rect_seg(int , int , int , int );

/*
* FUNCTION: std::shared_ptr<Track> make_track(std::list<std::shared_ptr<Block>> & , std::list<std::shared_ptr<Character>> & , std::list<std::shared_ptr<Interactable>> & );
* Function that constructs a Track object. 
*/

std::shared_ptr<Track> make_track(std::list<std::shared_ptr<Block>> & , std::list<std::shared_ptr<Character>> & , std::list<std::shared_ptr<Interactable>> & );

/*
* FUNCTION: void update_sprite_position(std::shared_ptr<Map_object>);
* Function that matches the map_object sprite member x and y coordianates to the map_object.
*/

void update_sprite_position(std::shared_ptr<Map_object>);

/*
* FUNCTION: void update_sprite_position(std::list<std::shared_ptr<TYPE>> );
* Function with overloads to all list types relevant. Iterates through list, calling update_sprite_position on every element.
*/

void update_sprite_position(std::list<std::shared_ptr<Block>> );

void update_sprite_position(std::list<std::shared_ptr<Character>> );

void update_sprite_position(std::list<std::shared_ptr<Interactable>> );

/*
* FUNCTION: void update_sprite_position(std::shared_ptr<Track> track);
* Function overload which updates the three lists contained in a Track object.
*/

void update_sprite_position(std::shared_ptr<Track> track);

/*
* FUNCTION: void update_sprite_texture(std::shared_ptr<Map_object>, sf::Texture &, sf::IntRect);
* Function which updates the texture of the sprite of the Map_object.
*/

void update_sprite_texture(std::shared_ptr<Map_object>, sf::Texture &, sf::IntRect);

/*
* FUNCTION: void update_sprite(std::shared_ptr<Map_object>);
* Function with overloads which updates both texture and position of the sprite of the Map_object, using type_str() to distinguish between types.
*/

void update_sprite(std::shared_ptr<Map_object>);

void update_sprite(std::list<std::shared_ptr<Character>>);

void update_sprite(std::list<std::shared_ptr<Block>>);

void update_sprite(std::list<std::shared_ptr<Interactable>>);

/*
* FUNCTION: void update_sprite(std::shared_ptr<Map_object>);
* Function overload which updates both texture and position of the every sprite contained within a Track object.
*/

void update_sprite(std::shared_ptr<Track> track);

/*
* FUNCTION: void update_sprite(std::shared_ptr<Map_object>);
* Function overloads which draws the sprite members of map_objects in a list on a window.
*/

void draw_list(std::list<std::shared_ptr<Interactable>> &, sf::RenderWindow &);

void draw_list(std::list<std::shared_ptr<Character>> &, sf::RenderWindow &);

void draw_list(std::list<std::shared_ptr<Block>> &, sf::RenderWindow &);

void draw_track(std::shared_ptr<Track>, sf::RenderWindow &);

/*
* std::list<std::shared_ptr<Type>> & operator+(std::list<std::shared_ptr<Type>> &, std::shared_ptr<Type>);
* std::list<std::shared_ptr<Type>> & operator+(std::list<std::shared_ptr<Type>> &, std::list<std::shared_ptr<Type>>);
* Function which overloads the + operator to use add_to functions declared at the top of the file.
*/

std::list<std::shared_ptr<Block>> & operator+(std::list<std::shared_ptr<Block>> &, std::shared_ptr<Block>);

std::list<std::shared_ptr<Character>> & operator+(std::list<std::shared_ptr<Character>> &, std::shared_ptr<Character>);

std::list<std::shared_ptr<Interactable>> & operator+(std::list<std::shared_ptr<Interactable>> &, std::shared_ptr<Interactable>);

std::list<std::shared_ptr<Block>> & operator+(std::list<std::shared_ptr<Block>> &, std::list<std::shared_ptr<Block>>);

std::list<std::shared_ptr<Character>> & operator+(std::list<std::shared_ptr<Character>> &, std::list<std::shared_ptr<Character>>);

std::list<std::shared_ptr<Interactable>> & operator+(std::list<std::shared_ptr<Interactable>> &, std::list<std::shared_ptr<Interactable>>);

/*
* void init_sprite(std::shared_ptr<Track>);
* Function which calls std::shared_ptr<Track> track;
*/

void init_sprite(std::shared_ptr<Track>);