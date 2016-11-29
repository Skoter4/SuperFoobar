#pragma once
class Cluster {

public:

	Cluster(int x_s, int y_s, int height_s, int width_s);
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

private:

	int x;
	int y;
	int height;
	int width;
	int desired_x = 0;
	int desired_y = 0;

};
