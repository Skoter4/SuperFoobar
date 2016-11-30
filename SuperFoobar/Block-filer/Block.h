#include <utility>
#include <string>
#include "../Collision/Cluster.h"
#include <memory>

class Block
{
public:

	Block(float, float, float, float); // Block-position and area is defined in its contructor.
	~Block() = default;

	float get_x_pos();
	float get_y_pos();
	void set_x_pos(float);
	void set_y_pos(float);
	float area();
	void flip_dead();

protected:


	std::unique_ptr<Cluster> cluster;
	float length;
	float width;
	std::string block_color{};
	bool block_outline{};
	bool dead{ false };
};
