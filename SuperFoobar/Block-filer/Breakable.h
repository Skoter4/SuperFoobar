#include "Block.h"

class Breakable :public Block
{
 public:
  Breakable(int, int, int, int);
  
  void interact() override;

  void poly() override;

  bool to_break(std::shared_ptr<Cluster> other_cluster);

  bool interact_type(std::shared_ptr<Map_object> my_char) override;

  void destruct();
 // ~Breakable() = default;
};

