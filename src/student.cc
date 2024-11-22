#include "student.h"

//ctor
Student::Student(Colour colour): colour{colour} {
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
int Student::getIndex() { return index; }
Colour Student::getColour() { return colour; }
int Student::getVictoryPoints(){ return victoryPotins; }
int Student::getResource(ResourceType type) {
  return resources.count(type);
}
std::vector<std::shared_ptr<Goals>> Student::getGoals() { return goals; }
std::vector<std::shared_ptr<Criteria>> Student::getCriterion() { return criterion; }

//other functions
void Student::addResource(ResourceType type) {
  if(resources.count(type) == 0) {
    resources.insert({type, 1});
  } else {
    resources.at(type) = resources.at(type) + 1;
  }
}

void Student::removeResource(ResourceType type) {
  resources.at(type) = resources.at(type) - 1;
}

void Student::addGoal(int index) {

}

void Student::addCriterion(int index) {

}

void Student::updateCriteria(int index) {

}


