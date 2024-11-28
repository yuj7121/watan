#include "tile.h"
#include "constants.h"

using namespace std; 

Tile::Tile(int index, int value, ResourceType resource, vector<Criteria*>& attachedCriteria, vector<Observer *> oList) :
        index{index}, value{value}, resource{resource}, attachedCriteria{attachedCriteria} {
                for (auto o : oList) {
                        attach(o); 
                }
}
        
int Tile::getIndex() const { return index; } 

int Tile::getValue() const { return value; }

ResourceType Tile::getResourceType() const { return resource; }

bool Tile::isValue(int val) { return val = value; }

void Tile::save() const {
        string output; 
        string resourceTypeNum; 
        if (resource == ResourceType::CAFFEINE) resourceTypeNum = "0"; 
        else if (resource == ResourceType::LAB) resourceTypeNum = "1"; 
        else if (resource == ResourceType::LECTURE) resourceTypeNum = "2"; 
        else if (resource == ResourceType::STUDY) resourceTypeNum = "3"; 
        else if (resource == ResourceType::TUTORIAL) resourceTypeNum = "4";
        else (resource == ResourceType::NETFLIX) resourceTypeNum = "5";
        output += resourceTypeNum + " " + value; 
        return output; 
}

void Tile::notifyObservers() {
    for(auto o : observers) o->notify(*this);
}