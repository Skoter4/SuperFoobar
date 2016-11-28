#include <iostream>
#include "Position.h"
using namespace std;

Position::Position(int x_pos, int y_pos)
{
	x = x_pos;
	y = y_pos;
}

int Position::get_x()
{
	return x;
}

int Position::get_y()
{
	return y;
}

void Position::print_pos()
{
	cout << x << " and " << y << endl;
}