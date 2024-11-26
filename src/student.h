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

class Criteria;
class Goal;

class Student {
  protected:
    int index;
    Colour colour;
    std::vector<std::shared_ptr<Criteria>> criterion; 
    std::vector<std::shared_ptr<Goal>> goals;
    std::unordered_map<ResourceType, int> resources;
    int victoryPotins;

  public:
    //ctor
    Student(Colour colour);

    //get functions
    int getIndex() const;
    Colour getColour() const;
    int getVictoryPoints() const;
    int getResource(ResourceType type) const;
    bool hasResources(std::vector<ResourceType> types) const;
    std::vector<std::shared_ptr<Goal>> getGoals() const;
    std::vector<std::shared_ptr<Criteria>> getCriterion() const;

    //other functions
    void addResource(ResourceType type);
    void removeResource(ResourceType type);
    void removeResources(std::vector<ResourceType> types);
    void addGoal(int index);
    void addCriterion(int index);
    void updateCriteria(int index);
};

#endif
