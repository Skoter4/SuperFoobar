#pragma once

#include "Block-filer\Block.h"
#include "Block-filer\Non_breakable.h"
#include "Block-filer\Breakable.h"
#include "Block-filer\Generator.h"
#include "Interactable-filer\Interactable.h"
#include "Interactable-filer\Coin.h"
#include "Interactable-filer\Power_up.h"
#include "Interactable-filer\Finish_line.h"
#include "Character filer\Character.h"
#include "Character filer\Foobar\Foobar.h"
#include "Character filer\Enemy\Enemy_1.h"
#include "Character filer\Enemy\Enemy_2.h"
#include "Character filer\Enemy\Enemy_2.h"
#include <list>
#include <string>
#include <memory>
#include "SFML/Graphics/Sprite.hpp"
#include <SFML\Graphics\Rect.hpp>

void block_collision(std::shared_ptr<Map_object> character_object, std::shared_ptr<Map_object> block_object);
bool point_in_rect(int x, int y, std::shared_ptr<Map_object> character_object);