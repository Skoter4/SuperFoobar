#include "Block-filer\Block.h"
#include "Interactable-filer\Interactable.h"
#include "Character filer\Character.h"
#include "Collision\Collision_handler.h"
#include <list>
#include <memory>
#include <utility>
#include <vector>

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
	std::list<std::shared_ptr<Block>> get_block_list();
	std::list<std::shared_ptr<Character>> get_character_list();
	std::list<std::shared_ptr<Interactable>> get_interactable_list();

	void set_width(int);
	void set_height(int);
	void set_floor(int);

	~Track() = default;

private:

	int floor;
	int width;
	int height;

	//Score score;
	//Timer timer;

	std::list<std::shared_ptr<Block>> block_list{};
	std::list<std::shared_ptr<Character>> character_list{};
	std::list<std::shared_ptr<Interactable>> interactable_list{};
};