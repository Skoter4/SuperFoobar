/*
* FILENAME:      Track.h
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
*
* This is the declaration file for the Track class.
*/


#pragma once
#include "Collision\Collision_handler.h"
#include "Character filer\Foobar\Foobar.h"
#include "Character filer\Character.h"
#include "Character filer\Enemy\Enemy_1.h"
#include "Block-filer\Generator.h"
#include "Timer.h"
#include "Score.h"
#include "Scoreboard.h"
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <stdexcept>

class Character;
class Foobar;
class Block;
class Breakable;
class Interactable;
class Scoreboard;

class Track
{
public:

	/*
	* CONSTRUCTOR: Track(std::list<std::shared_ptr<Block>>,
					std::list<std::shared_ptr<Character>>,
					std::list<std::shared_ptr<Interactable>>,
					int, int, int);
	* Initializing a track object with lists with pointers to objects of type Block, Character and Interactable
	* as well as width, height and floor level of the track.
	*/

	Track(std::list<std::shared_ptr<Block>>,
		std::list<std::shared_ptr<Character>>,
		std::list<std::shared_ptr<Interactable>>,
		int, int, int);

	/*
	* FUNCTION: int get_width();
	* Returns the width of the track
	*/

	int get_width();

	/*
	* FUNCTION: int get_height();
	* Returns the height of the track
	*/

	int get_height();

	/*
	* FUNCTION: int get_floor();
	* Returns the floor level of the track
	*/

	int get_floor();

	/*
	* FUNCTION: std::shared_ptr<Foobar> get_foobar();
	* Returns a pointer to the Foobar object
	*/

	std::shared_ptr<Foobar> get_foobar();

	/*
	* FUNCTION: void set_foobar(std::shared_ptr<Foobar>);
	* Assigns a new pointer to a new Foobar object
	*/

	void set_foobar(std::shared_ptr<Foobar>);

	/*
	* FUNCTION: std::list<std::shared_ptr<Block>> & get_block_list();
	* Returns a list with pointers to block objects
	*/

	std::list<std::shared_ptr<Block>> & get_block_list();

	/*
	* FUNCTION: std::list<std::shared_ptr<Character>> & get_character_list();
	* Returns a list with pointers to Character objects
	*/

	std::list<std::shared_ptr<Character>> & get_character_list();

	/*
	* FUNCTION: std::list<std::shared_ptr<Interactable>> & get_interactable_list();
	* Returns a list with pointers to Interactable objects
	*/

	std::list<std::shared_ptr<Interactable>> & get_interactable_list();

	/*
	* FUNCTION: void set_score(Score&);
	* Assigns a new Score object
	*/

	void set_score(Score&);

	/*
	* FUNCTION: void set_timer(Timer&);
	* Assigns a new Timer object
	*/

	void set_timer(Timer&);

	/*
	* FUNCTION: void set_scoreboard(Scoreboard&);
	* Assigns a new Scoreboard object
	*/

	void set_scoreboard(Scoreboard&);

	/*
	* FUNCTION: Score& get_score();
	* Returns the Score object
	*/

	Score& get_score();

	/*
	* FUNCTION: Timer& get_timer();
	* Returns the Timer object
	*/

	Timer& get_timer();

	/*
	* FUNCTION: Scoreboard& get_scoreboard();
	* Returns the Scoreboard object
	*/

	Scoreboard& get_scoreboard();

	/*
	* FUNCTION: Track add_map_object(std::shared_ptr<Map_object>);
	* Adds objects to their respective lists
	*/

	Track add_map_object(std::shared_ptr<Map_object>);

	/*
	* FUNCTION: Track operator+(std::shared_ptr<Map_object>);
	* Executes add_map_object in order to easily add objects to lists
	*/

	Track operator+(std::shared_ptr<Map_object>);

	/*
	* FUNCTION: void handle_map_object_flags();
	* Goes through all lists and checks if any object has been flagged for death, if so it is removed.
	* Depending on what object has been removed, different things occurs.
	*/

	void handle_map_object_flags();

	/*
	* FUNCTION: void set_width(int);
	* Assigns a new width to the track
	*/

	void set_width(int);

	/*
	* FUNCTION: void set_height(int);
	* Assigns a new height to the track
	*/

	void set_height(int);

	/*
	* FUNCTION: void set_floor(int);
	* Assigns a new floor level to the track
	*/

	void set_floor(int);

	/*
	* FUNCTION: void flip_end_of_game();
	* Flips a bool to indicate Foobar have reached the finish line
	*/

	void flip_end_of_game();

	/*
	* FUNCTION: bool is_end_of_game();
	* Returns a bool whether Foobar has reached the finish line or not
	*/

	bool is_end_of_game();

	~Track() = default;

private:
	int floor;
	int width;
	int height;
	std::shared_ptr<Foobar> foobar{};
	Score score{};
	Timer timer{};
	Scoreboard scoreboard{};
	bool end_of_game{ false };

	std::list<std::shared_ptr<Block>> block_list{};
	std::list<std::shared_ptr<Character>> character_list{};
	std::list<std::shared_ptr<Interactable>> interactable_list{};
};