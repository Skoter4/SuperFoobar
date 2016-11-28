#pragma once
class Position {
public:
	Position(int x_pos, int y_pos);
	int get_x();
	int get_y();
	void print_pos();
private:
	int x;
	int y;
};