#include "goal.h"
#include "criteria.h"
#include "student.h"

using namespace std; 

Goal::Goal(int index, Student *owner)
    : index{index}, owner{nullptr} {}

int Goal::getIndex() const { return index; }

Student *Goal::getOwner() const { return owner; }

bool Goal::isOwnedBy(Student * player) const {
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

// change to void function -> just throw with exception
bool Goal::playGoal(Student *player) {
    bool adjacent = false;

    if (owner) {
        return false;
    } // through exception

    for (auto c : adjCriteria) {
        if (c->isOwnedBy(player) || c->adjacentGoalOwner(player)) {
            adjacent = true;
            break;
        }
    }
    if (!adjacent) return false; // through exception

    owner = player; 
    return true;
}

void Goal::setOwner(Student *s) {
    owner = s; 
}
    

string Goal::info() const {
    string output; 
    if(owner) {
        Colour c = owner->getColour(); 
        output = colourToString(c).substr(0, 1);
        output += "A"; 
    } else {
        output = to_string(getIndex()); 
    }
    return output; 
}
