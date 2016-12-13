#pragma once
#include "Map_object.h"
#include "Character filer\Character.h"
#include <string>
#include <memory>

void block_collision(std::shared_ptr<Character> character_object, std::shared_ptr<Map_object> block_object);
bool point_in_rect(int x, int y, std::shared_ptr<Map_object> character_object);