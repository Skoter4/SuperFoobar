#include "Block.h"
#include "Interactable.h"
class Generator: Protected Block
{
 public:
 
  auto generate();
  void deactivate();
  
  ~Generator();
  
 protected:
  Generator(int, int, int, int, std::unique_ptr<Interactable>);

 private:
  bool deactivated{false}
  std::unique_ptr<Interactable> reward;
  
};
