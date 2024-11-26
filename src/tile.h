#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string> 
#include <vector>
#include <memory>
#include "constants.h"

using namespace std; 

class Criterion; 

class Tile { 
    int index; 
    int value; 
    ResourceType resource; 

public: 
    Tile(int index, int value, ResourceType resource);
    int getIndex() const; 
    int getValue() const; 
    ResourceType getResourceType() const;
    bool isVertex() const; 
};

#endif 