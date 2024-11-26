#include "student.h"

//ctor
Student::Student(Colour colour) : colour{colour} {
  switch(colour) {
    case Colour::BLUE:
      index = 0;
      break;
    case Colour::RED:
      index = 1;
      break;
    case Colour::ORANGE:
      index = 2;
      break;
    case Colour::YELLOW:
      index = 3;
      break;
  }
}

//getter functions
int Student::getIndex() const { return index; }
Colour Student::getColour() const { return colour; }
int Student::getVictoryPoints() const { return victoryPotins; }
int Student::getResource(ResourceType type) const {
  return resources.count(type) ? resources.at(type) : 0;
}
std::vector<std::shared_ptr<Goal>> Student::getGoals() const { return goals; }
std::vector<std::shared_ptr<Criteria>> Student::getCriterion() const { return criterion; }

bool Student::hasResources(std::vector<ResourceType> types) const {
    for (ResourceType t : types) {
        if (getResource(t) <= 0) return false;
    }
    return true;
}

//other functions
void Student::addResource(ResourceType type) {
  if (resources.count(type) == 0) {
    resources.insert({type, 1});
  } else {
    resources.at(type) = resources.at(type) + 1;
  }
}

void Student::removeResource(ResourceType type) {
  resources.at(type) = resources.at(type) - 1;
}

void Student::removeResources(std::vector<ResourceType> types) {
    for (ResourceType t : types) {
        removeResource(t);
    }
}

void Student::addGoal(int index) {
}

void Student::addCriterion(int index) {
}

void Student::updateCriteria(int index) {
}
