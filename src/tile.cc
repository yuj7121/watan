#include "tile.h"
#include "constants.h"

using namespace std; 

Tile::Tile(int index, int value, ResourceType resource) :
        index{index}, value{value}, resource{resource} {} 
        
int Tile::getIndex() const { return index; } 

int Tile::getValue() const { return value; }

ResourceType Tile::getResourceType() const { return resource; }

bool isValue(int val) { return val = value; }

