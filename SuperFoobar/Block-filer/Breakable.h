#pragma once
#include "Block.h"
#include "../Character filer/Enemy/Enemy_2.h"
#include "../Character filer/Enemy/Enemy_3.h"
class Breakable :public Block
{
 public:
  Breakable(int, int, int, int);

  bool to_break(std::shared_ptr<Cluster> other_cluster);

  void interact_with(std::shared_ptr<Map_object> my_char) override;

  void interact() override;

  void destruct();

  std::string type_str() override;

  ~Breakable() = default;
};

