#include "goal.h"

using namespace std; 

Goal::Goal(int index, shared_ptr<Student> owner) :
    index{index}, owner{nullptr} {}

int Goal::getIndex() const { return index; }

shared_ptr<Student> Goal::getOwner() const { return owner; }

bool Goal::isOwnedBy(shared_ptr<Student> player) const { return owner==player; }

void Goal::attachCriteria(shared_ptr<Criteria> c) {
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

bool Goal::buildGoal(shared_ptr<Student> player) {
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


