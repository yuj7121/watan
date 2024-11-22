#ifndef STUDENT_H
#define STUDENT_H

#include "constants.h"
#include "tile.h"
#include "goal.h"
#include "criteria.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

//remvoe these and replace with including header files once done!!

class Student {
    int index;
    Colour colour;
    Colour colour;
    std::vector<std::shared_ptr<Criteria>> criterion; 
    std::vector<std::shared_ptr<Goal>> goals;
    unoredered_map<ResourceType, int> resources;
    int victoryPotins;

  public:
    //ctor
    Student(Colour colour);

    //get functions
    int getIndex();
    Colour getColour();
    int getColour();
    int getVictoryPoints();
    unordered_map<String, int> getResource();
    std::vector<std::shared_ptr<Goal>> getGoals();
    std::vector<std::shared_ptr<Criteria>> getCriterion();

    //other functions
    void addResource(ResourceType type);
    void removeResourcec(ResourceType type);
    void addGoal(int index);
    void addCriterion(int index);
    void updateCriteria(int index);
}

#endif