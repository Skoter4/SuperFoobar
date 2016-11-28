#include "Coin.h"

using namespace std;

Coin::Coin(int x_pos, int y_pos, int width, int length)
	: position{ make_unique<Position>(x_pos, y_pos), width{ width }, length{ length } }
{}