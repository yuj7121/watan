#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string> 
#include <vector>
#include <memory>

using namespace std; 

class Criterion; 

class Tile { 
    int index; 
    int value; 
    string resource; 
    vector<std::shared_ptr<Criterion>> criterion;  
    bool hasGoose; 

public: 
    Tile(int index, int value, string resource, bool hasGoose);
    int getIndex() const; 
    int getValue() const; 
    string getResourceType() const;
    bool isVertex() const; 
    bool checkGoose() const; 
    // TODO: Destructor Needed?
    // ^^^ i don't think so since we're using smart pointers
    //     which means there will be no delete statements
};

#endif 