#include "Generator.h"
#include "../Interactable-filer/Interactable.h"
#include <utility>

using namespace std;

Generator::Generator(float x, float y, float height, float width,
		    std::unique_ptr<Interactable> interactable)
  :Block(x, y, height, width), reward(std::move(interactable))
{}

auto Generator::generate()
{
  
}
