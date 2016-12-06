#pragma once
#include <memory>
#include "../Collision/Cluster.h"
#include <string>
//#include "SFML\Graphics\Texture.hpp"
//#include "SFML\Graphics\Sprite.hpp"

namespace sf
{
	class Sprite;
	class Texture;
};

class sf::Sprite;
class sf::Texture;

class Map_object {
public:

	//Map_object() = default;

	virtual void poly() = 0;

	std::shared_ptr<Cluster> get_cluster();

	virtual std::string type_str() = 0;
	virtual void interact() = 0;
	virtual bool interact_type(std::shared_ptr<Map_object>) = 0;
	int get_height();
	int get_width();
	void set_height(int);
	void set_width(int);

	int get_x_pos();
	int get_y_pos();
	void set_x(int);
	void set_y(int);
	void set_desx_pos(int);
	void set_desy_pos(int);
	//int area();
	//void flip_dead();

	//sf::Texture get_texture();
	//sf::Sprite get_sprite();

protected:

	sf::Texture* texture_ptr{};
	sf::Sprite* sprite_ptr{};

	Map_object(int, int, int, int);

	std::shared_ptr<Cluster> cluster;
};