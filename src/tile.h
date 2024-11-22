#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string> 
#include <vector>

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
    // destructor needed?

}

#endif 