#pragma once
//#ifndef BLOCK_H
//#define BLOCK_H
//#include "../Character filer/Character.h"
//#include "../Interactable-filer/Interactable.h"
#include <memory>

//class Block;

class Cluster {

public:

	Cluster(int x_s, int y_s, int height_s, int width_s);
	Cluster() = default;
	~Cluster() = default;

	void move_x();
	void move_y();

	int begin_x();
	int begin_y();

	int end_x();
	int end_y();

	int get_x();
	int get_y();

	int get_width();
	int get_height();

	void set_des_x(int x);
	void set_des_y(int y);

	void set_x(int);
	void set_y(int);

	void set_remove(bool);

	void print_x_y();

private:

	int x;
	int y;
	int height;
	int width;
	int desired_x = 0;
	int desired_y = 0;
	bool to_remove{ false };
	//std::shared_ptr<Block> block_ptr{nullptr};
	//std::shared_ptr<Character> char_ptr{nullptr};
	//std::shared_ptr<Interactable> inter_ptr{nullptr};
};
//#endif