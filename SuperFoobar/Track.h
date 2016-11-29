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

	Track(std::initializer_list<std::shared_ptr<Block>>,
		std::initializer_list<std::shared_ptr<Character>>,
		std::initializer_list<std::shared_ptr<Interactable>>,
		float, float, float);

	float get_width();
	float get_height();
	float get_floor();
	std::list<std::shared_ptr<Block>> get_block_list();
	std::list<std::shared_ptr<Character>> get_character_list();
	std::list<std::shared_ptr<Interactable>> get_interactable_list();

	void set_width(float);
	void set_height(float);
	void set_floor(float);

	~Track() = default;

private:

	float floor;
	float width;
	float height;

	//Score score;
	//Timer timer;

	std::list<std::shared_ptr<Block>> block_list{};
	std::list<std::shared_ptr<Character>> character_list{};
	std::list<std::shared_ptr<Interactable>> interactable_list{};
};