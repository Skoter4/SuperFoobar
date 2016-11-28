#include "Power_up.h"

using namespace std;

Power_up::Power_up(int x_pos, int y_pos, int width, int length)
	: position{ make_unique<Position>(x_pos, y_pos) }, width{ width }, length{ length }
{}