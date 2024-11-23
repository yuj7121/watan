#include <iostream> 
#include <vector> 
#include <string>

#include "goal.h"
#include "criteria.h"
#include "player.h"

using namespace std; 

Goal::Goal(int index, Student* owner, vector<shared_ptr<Criteria *>> &adjCriteria) : 
    index{index}, owner{nullptr}, adjCriteria{adjCriteria} {}

int Goal::getIndex() const { return index; }

bool Goal::isOwnedBy(Student *player) const { return owner==player; }

bool Goal::checkCriteriaExist() const {
    for (auto c : adjCriteria) { 
        if(c->getCompletionType() != CompletionType::NONE) {
            return true;
        }
    }
    return false;
}

bool Goal::buildGoal(Student *player) {
    // TODO: incoporate cost of building a goal
    bool adjacent = false; 

    if (owner) { 
        return false; 
    }

    for (auto c : adjCriteria) { 
        if (c->isOwnedBy(player) || c->adjacentGoalOwner(player)) {
            adjacent = true;
            break; 
        }
    }
    if (connected == false) return false; // no adjacent -> cant build goal

    owner = player;
    return true;  
}

