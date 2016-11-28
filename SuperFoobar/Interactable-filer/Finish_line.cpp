#include "Finish_line.h"

using namespace std;

Finish_line::Finish_line(int x_pos, int y_pos, int width, int length)
	: position{ make_unique<Position>(x_pos, y_pos) }, width{ width }, length{ length }
{}