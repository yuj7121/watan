#include "tile.h"
#include "constants.h"
#include "goal.h"
#include "criteria.h"

using namespace std; 



Tile::Tile(int index, int value, ResourceType resource, vector<std::shared_ptr<Criteria>> attachedCriterion, 
    vector<std::shared_ptr<Goal>> attachedGoals) :
    index{index}, value{value}, resource{resource}, attachedCriterion{attachedCriterion}, 
    attachedGoals{attachedGoals} {}

int Tile::getIndex() const { return index; } 

int Tile::getValue() const { return value; }

ResourceType Tile::getResourceType() const { return resource; }

bool Tile::isValue(int val) { return val == value; }

string Tile::save() const {
    string output;
    string resourceTypeNum; 
    if (resource == ResourceType::CAFFEINE) resourceTypeNum = "0"; 
    else if (resource == ResourceType::LAB) resourceTypeNum = "1"; 
    else if (resource == ResourceType::LECTURE) resourceTypeNum = "2"; 
    else if (resource == ResourceType::STUDY) resourceTypeNum = "3"; 
    else if (resource == ResourceType::TUTORIAL) resourceTypeNum = "4";
    else if (resource == ResourceType::NETFLIX) resourceTypeNum = "5";
    output += resourceTypeNum + " " + std::to_string(value); 
    return output; 
}


bool Tile::studentOwns(shared_ptr<Student> student) {
    for(auto it = attachedCriterion.begin(); it != attachedCriterion.end(); ++it) {
        if((*it)->isOwnedBy(student)){
                return true;
        }
    }
    for(auto it = attachedCriterion.begin(); it != attachedCriterion.end(); ++it) {
        if((*it)->isOwnedBy(student)){
                return true;
        }
    }
    return false;
}



