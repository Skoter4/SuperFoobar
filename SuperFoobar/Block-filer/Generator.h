#include "../Block-filer/Block.h"
#include "../Interactable-filer/Interactable.h"
class Generator: protected Block
{
 public:
 
  auto generate();
  void deactivate();
  
  ~Generator();
  
 protected:
  Generator(float, float, float, float, std::unique_ptr<Interactable>);

 private:
	 bool deactivated{ false };
	 std::unique_ptr<Interactable> reward;
  
};
