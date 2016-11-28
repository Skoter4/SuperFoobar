#include "Block.h"

using namespace std;

Block::Block(int x_pos, int y_pos, int length, int width)
  :position{new Position(x_pos, y_pos)}, length{length}, width{width}
{}


int Block::get_x_pos()
{
  return position->get_x();
}

int Block::get_y_pos()
{
  return position->get_y();
}
void Block::set_x_pos(int new_coord)
{
  position->set_x(new_coord);
}

void Block::set_y_pos(int new_coord)
{
  position->set_y(new_coord);
}

int Block::area()
{
  return width*length;
}

void Block::flip_dead()
{
  dead = !dead;
}
