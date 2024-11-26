#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string> 
#include <vector>
#include <memory>
#include "constants.h"

using namespace std; 

class Tile { 
    int index; 
    int value; 
    ResourceType resource; // TODO: check what exactly of the resource we want to return, the #? the type?

public: 
    Tile(int index, int value, ResourceType resource);
    int getIndex() const; 
    int getValue() const; 
    ResourceType getResourceType() const;
    bool isValue(int val) const; 
};

#endif 