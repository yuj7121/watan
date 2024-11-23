#include <iostream> 
#include <vector> 
#include <string>

#include "goal.h"
#include "criteria.h"
#include "player.h"

using namespace std; 

Goal::Goal(int index, Student* owner) : index{index}, owner{nullptr} {}

void Goal::attachCriteria(Criteria *c) {
    adjCriteria.push_back(c);
}

void Goal::detachCriteria(Criteria *c) {
    for(auto it = myCriteria.begin(); *it != crit; ++it) { 
        myCriteria.erase(it);
    }
}

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

void buildGoal(Student *player) {
    if (!owner) {
        bool connected = false; 
    }
}

