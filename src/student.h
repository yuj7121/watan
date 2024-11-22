#ifndef STUDENT_H
#define STUDENT_H

#include "constants.h"
#include "tile.h"
//#include "goal.h"
//#include "criteria.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Student {
  protected:
    int index;
    Colour colour;
    std::vector<std::shared_ptr<Criteria>> criterion; 
    std::vector<std::shared_ptr<Goal>> goals;
    unordered_map<ResourceType, int> resources;
    int victoryPotins;

  public:
    //ctor
    Student(Colour colour);

    //get functions
    int getIndex();
    Colour getColour();
    int getVictoryPoints();
    int getResource(ResourceType type);
    std::vector<std::shared_ptr<Goal>> getGoals();
    std::vector<std::shared_ptr<Criteria>> getCriterion();

    //other functions
    void addResource(ResourceType type);
    void removeResource(ResourceType type);
    void addGoal(int index);
    void addCriterion(int index);
    void updateCriteria(int index);
};

#endif