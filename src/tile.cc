#include <iostream> 
#include <vector>
#include <memory>
#include "tile.h"
#include "criterion.h"

using namespace std; 

Tile::Tile(int index, int value, string resource, bool hasGoose) :
        index{index}, value{value}, resource{resource}, hasGoose{hasGoose} {} 
        
int Tile::getIndex() const { return index; } 

int Tile::getValue() const { return value; }

string Tile::getResourceType() const { return resource; }

bool Tile::checkGoose() const { return hasGoose; } 

// bool isVertex() const; 
