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
class Student; 
class Goal;

class Tile { 
    int index; 
    int value; 
    ResourceType resource; 
    vector<std::shared_ptr<Criteria>> attachedCriterion;  
    vector<std::shared_ptr<Goal>> attachedGoals;  

public:
    Tile(int index, int value, ResourceType resource, vector<std::shared_ptr<Criteria>> attachedCriterion, vector<std::shared_ptr<Goal>> attachedGoals);
    int getIndex() const; 
    int getValue() const; 
    ResourceType getResourceType() const;
    bool isValue(int val);
    string save() const; 
    bool studentOwns(shared_ptr<Student> student);
};

#endif 