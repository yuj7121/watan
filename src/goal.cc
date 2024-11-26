#include "goal.h"
#include "student.h"
#include "criteria.h"

using namespace std; 

Goal::Goal(int index, Student* owner) : 
    index{index}, owner{owner} {}

int Goal::getIndex() const { return index; }

bool Goal::isOwnedBy(Student* player) const { 
    return owner == player;
}

void Goal::attachCriteria(Criteria *c) {
    adjCriteria.push_back(c);
}

bool Goal::checkCriteriaExist() const {
    for (auto c : adjCriteria) { 
        if(c->getCompletionType() != CompletionType::NONE) {
            return true;
        }
    }
    return false;
}

bool Goal::buildGoal(Student* player) {
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
    if (adjacent == false) return false; // no adjacent -> cant build goal

    owner = player;
    return true;  
}


