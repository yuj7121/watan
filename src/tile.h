#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string> 
#include <vector>
#include <memory>
#include "constants.h"
#include "subject.h"

using namespace std; 

class Criteria; 

class Tile : public Subject { 
    int index; 
    int value; 
    ResourceType resource; 
    vector<Criteria *> attachedCriteria;  

public: 
    Tile(int index, int value, ResourceType resource, vector<Criteria*>& attachedCriteria);
    int getIndex() const; 
    int getValue() const; 
    ResourceType getResourceType() const;
    bool isValue(int val);
    void save() const; 
};

#endif 