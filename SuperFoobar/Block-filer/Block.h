#include <utility>
#include <string>
#include "../Collision/Cluster.h"
#include <memory>

class Block {
 public:
  ~Block() = default;

  virtual void interact() = 0;

  int get_x_pos();
  int get_y_pos();
  void set_x_pos(int);
  void set_y_pos(int);
  int area();
  void flip_dead();
 protected:
   Block(int, int, int, int); // Block-position and area is defined in its contructor.
  std::unique_ptr<Cluster> position;
  int length;
  int width;
  std::string block_color{};
  bool block_outline{};
  bool dead{false};
};
