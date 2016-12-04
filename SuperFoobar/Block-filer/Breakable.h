#include "Block.h"
class Breakable :public Block
{
 public:
  Breakable(int, int, int, int);
  
  void interact();

  void destruct();
  ~Breakable() = default;
};

