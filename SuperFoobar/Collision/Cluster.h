#pragma once
#include <memory>

class Cluster {

public:

	Cluster(int x_s, int y_s, int height_s, int width_s);
	Cluster() = default;
	~Cluster() = default;

	int get_x();
	int get_y();

	int get_width();
	int get_height();

	int get_des_x();
	int get_des_y();

	void set_des_x(int x);
	void set_des_y(int y);

	void set_x(int);
	void set_y(int);

	void set_width(int);
	void set_height(int);


private:

	int x;
	int y;
	int height;
	int width;
	int desired_x = 0;
	int desired_y = 0;
};