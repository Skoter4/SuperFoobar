#include "Block.h"
class Breakable :public Block
{
 public:
  Breakable(int, int, int, int);
  
  void interact() override;

  void destruct();
  ~Breakable();
};

