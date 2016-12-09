#pragma once
#include "Block.h"

class Breakable :public Block
{
 public:
  Breakable(int, int, int, int);

  void poly() override;

  bool to_break(std::shared_ptr<Cluster> other_cluster);

  bool interact_with(std::shared_ptr<Map_object> my_char) override;

  void interact() override;

  void destruct();

  std::string type_str() override;

  ~Breakable() = default;
};

