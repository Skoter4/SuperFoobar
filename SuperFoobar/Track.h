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

class Track
{
public:

	Track(std::list<std::shared_ptr<Block>>,
		std::list<std::shared_ptr<Character>>,
		std::list<std::shared_ptr<Interactable>>,
		int, int, int);

	int get_width();
	int get_height();
	int get_floor();

	std::shared_ptr<Foobar> get_foobar();
	void set_foobar(std::shared_ptr<Foobar>);

	std::list<std::shared_ptr<Block>> & get_block_list();
	std::list<std::shared_ptr<Character>> & get_character_list();
	std::list<std::shared_ptr<Interactable>> & get_interactable_list();

	void set_score(Score&);
	void set_timer(Timer&);
	void set_scoreboard(Scoreboard&);

	Score& get_score();
	Timer& get_timer();
	Scoreboard& get_scoreboard();

	Track add_map_object(std::shared_ptr<Map_object>);

	Track operator+(std::shared_ptr<Map_object>);

	void handle_map_object_flags();

	void set_width(int);
	void set_height(int);
	void set_floor(int);

	~Track() = default;

private:

	int floor;
	int width;
	int height;
	std::shared_ptr<Foobar> foobar{};
	Score score{};
	Timer timer{};
	Scoreboard scoreboard{};

	std::list<std::shared_ptr<Block>> block_list{};
	std::list<std::shared_ptr<Character>> character_list{};
	std::list<std::shared_ptr<Interactable>> interactable_list{};
};