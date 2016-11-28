#include "Generator.h"
#include "../Interactable-filer/Interactable.h"
#include <utility>

using namespace std;

Generator::Generator(int x_pos, int y_pos, 
		    int length, int width,
		    std::unique_ptr<Interactable> interactable)
  :Block(x_pos, y_pos, length, width), reward(std::move(interactable))
{}

auto Generator::generate()
{
  
}
