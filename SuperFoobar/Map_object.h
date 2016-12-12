#pragma once
#include <memory>
#include "../Collision/Cluster.h"
#include <string>
#include <iostream>
//#include "SFML\Graphics\Texture.hpp"
//#include "SFML\Graphics\Sprite.hpp"

namespace sf
{
	class Sprite;
};

class sf::Sprite;

class Map_object {
public:

	//Map_object() = default;

	virtual void poly() = 0;

	std::shared_ptr<Cluster> get_cluster();

	virtual std::string type_str() = 0;
	virtual void interact() = 0;
	virtual bool interact_with(std::shared_ptr<Map_object>) = 0;
	int get_height();
	int get_width();
	void set_height(int);
	void set_width(int);

	bool is_dead();
	void flip_dead();


	int get_x_pos();
	int get_y_pos();
	void set_x(int);
	void set_y(int);
	int get_desx_pos();
	int get_desy_pos();
	void set_desx_pos(int);
	void set_desy_pos(int);


	int get_old_y();
	int get_old_x();
	void set_old_x(int);
	void set_old_y(int);
	//int area();
	//void flip_dead();

	std::shared_ptr<sf::Sprite> get_sprite();
	void setSprite(std::shared_ptr<sf::Sprite>);
protected:
	bool dead{ false };
	std::shared_ptr<sf::Sprite> object_sprite;

	int old_x{};
	int old_y{};

	Map_object(int, int, int, int);

	std::shared_ptr<Cluster> cluster;
};