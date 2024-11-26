#include <iostream> 
#include <vector>
#include <memory>
#include "tile.h"
#include "criteria.h"
#include "constants.h"

using namespace std; 

Tile::Tile(int index, int value, ResourceType resource, bool hasGoose) :
        index{index}, value{value}, resource{resource}, hasGoose{hasGoose} {} 
        
int Tile::getIndex() const { return index; } 

int Tile::getValue() const { return value; }

ResourceType Tile::getResourceType() const { return resource; }

bool Tile::checkGoose() const { return hasGoose; } 

// bool isVertex() const; 
