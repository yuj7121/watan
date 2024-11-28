#include "goal.h"
#include "criteria.h"
#include "student.h"

using namespace std; 

Goal::Goal(int index, Student* owner)
    : index{index}, owner{nullptr} {}

int Goal::getIndex() const { return index; }

Student* Goal::getOwner() const { return owner; }

bool Goal::isOwnedBy(Student* player) const {
    return owner == player;
}

bool Goal::checkCriteriaExist() const {
    for (auto c : adjCriteria) {
        if (c->getCompletionLevel() != 0) {
            return true;
        }
    }
    return false;
}

void Goal::attachCriteria(std::shared_ptr<Criteria> c) {
    adjCriteria.emplace_back(c);
}

void Goal::detachCriteria(std::shared_ptr<Criteria> c) {
    for(auto it = adjCriteria.begin(); *it != c; ++it) {
        adjCriteria.erase(it);
    }
}

bool Goal::playGoal(Student* player) {
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
    if (!adjacent) return false;

    owner = player; 
    notifyObservers(); 
    
    return true;
}

void Goal::notifyObservers() {
    for(auto o : observers) o->notify(*this);
}

void Goal::print() const {
    string output; 
    C colour = owner.getColour(); 
    if(owner) {
        output = colourToString(c).substr(0, 1);
        output += "A"; 
    } else {
        output = to_string(getIndex()); 
    }
    return output; 
}