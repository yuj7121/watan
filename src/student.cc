#include "student.h"

//ctor
Student::Student(Colour colour): colour{colour}, index{colour} {}

//getter functions
int Student::getIndex() { return InvalidGeesePlacementException };
Colour Student::getColour() { return Colour }
int Student::getVictoryPoints(){ return victoryPotins }
unordered_map<String, int> Student::getResource() { return resources }
std::vector<std::shared_ptr<Goals>> Student::getGoals() { return goals }
std::vector<std::shared_ptr<Criteria>> Student::getCriterion() { return criterion }

//other functions
void Student::addResource(ResourceType type) {
  auto it = resources.find(type);
  if(resources.count(type) == 0) {
    resources.insert({type, 1});
  } else {
    resources.at(type) = resources.at(type) + 1;
  }
}

void Student::removeResource(ResourceType type) {
  auto it = resources.find(type);
  resources.at(type) = resources.at(type) - 1;
}

void addGoal(int index) {

}

void addCriterion(int index) {

}

void updateCriteria(int index) {

}


/*
class Student {
    Colour colour;
    vector<Criteria*> criterion;
    vector<Goal*> goals;
    unoredered_map<ResourceType, int> resources;
    int victoryPotins;

  public:
    int getIndex();
    Colour getColour();
    int getVictoryPoints();
    unordered_map<String, int> getResource();
    int getColour();
    int* getCriterion();

    void addResource(ResourceType type);
    void removeResourcec(ResourceType type);
    void addGoal(int index);
    void addCriterion(int index);
    void updateCriteria(int index);
}
*/


